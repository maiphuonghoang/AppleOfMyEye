#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
//----------------------------------------------------------------
/* Dãy con liên tiếp dài nhất có tổng <= S 
11 10
3 1 4 1 5 3 4 1 5 2 2 
=> 4
12 10
3 1 4 1 5 3 4 1 5 2 1 1 
=> 5 
*/
void meDayConDaiNhat(){
    int n, s; cin >> n >> s;
    int a[n];
    for (int &x : a) cin >> x;

    int sum = 0, res = 0;
    int left = 0, right = 0;
    while ( right < n){
        if(sum + a[right] <= s){
            sum += a[right]; 
            right++; 
        }else{
            sum -= a[left];
            left++;
        }
        res = max(res, right - left);                 
    }
    cout << res << endl;
}
void dayConDaiNhat(){
    int n, s; cin >> n >> s;
    int a[n];
    for (int &x : a) cin >> x;

    int sum = 0, res = 0;
    int left = 0, right = 0;
    for (right = 0; right < n; right++){
        sum += a[right];
        //nếu sum > s => thu hẹp đoạn [l-r] bằng cách tăng left 
        while(sum > s){
            sum -= a[left];
            left++;
        }
        res = max(res, right - left + 1);                 
    }
    cout << res << endl;
}
/**
In meDayConDaiNhat, the condition for including the next element in the subarray 
is checked using an if statement: if (sum + a[right] <= s).
If the sum condition is satisfied, the element is added to the subarray; otherwise, the left pointer is advanced.

In dayConDaiNhat, the condition for removing elements from the left end of the subarray 
is checked using a while loop: while (sum > s). 
This loop keeps removing elements from the left end until the sum condition is satisfied again.
*/
//----------------------------------------------------------------
/* Dãy con liên tiếp ngắn nhất có tổng >= S 
8 10
1 3 4 3 2 1 5 4 
=> 3
8 10
10 3 4 3 2 1 5 4 
*/
void dayConNganNhat(){
    int n, s; cin >> n >> s;
    int a[n];
    for (int &x : a) cin >> x;

    int sum = 0, res = 1e9;
    int left = 0, right = 0;
    for (right = 0; right < n; right++){
        sum += a[right];
        //nếu sum >= s =>cập nhật và thu hẹp đoạn [l-r] bằng cách tăng left 
        while(sum >= s){
            res = min(res, right - left + 1);     
            sum -= a[left];
            left++;
        }                   
    }
    if (res == 1e9) cout << "-1";
    cout << res << endl;
}
//----------------------------------------------------------------
/* Đếm bn mảng con các phần tử liên tiếp trong mảng mà tổng <= S
13 14
5 4 5 2 4 5 1 1 2 5 5 2 2 
=> 47 
*/
void segCountSumLessS(){
    int n, s; cin >> n >> s;
    int a[n];
    for (int &x : a) cin >> x;

    int sum = 0, res = 0;
    int left = 0, right = 0;
    for (right = 0; right < n; right++){
        sum += a[right];
        while(sum > s){
            sum -= a[left];
            left++;
        }
        //số lượng dãy con = r-l+1;
        res += right - left + 1;                 
    }
    cout << res << endl;
}
//----------------------------------------------------------------
/* Đếm bn mảng con các phần tử liên tiếp trong mảng mà tổng >= S
n = 8, s = 10
l     r 
3 1 4 3 5 8 3 1
      x x x x x 
dãy con bắt đầu từ chỉ số l, kết thúc ở chỉ số r, r+1... đều thỏa mãn
*/
void segCountSumGreaterS(){
    int n, s; cin >> n >> s;
    int a[n];
    for (int &x : a) cin >> x;

    int sum = 0, res = 0;
    int left = 0, right = 0;
    for (right = 0; right < n; right++){
        sum += a[right];
        while(sum >= s){
            //số lượng dãy con bắt đầu từ right, kết thúc ở n-1
            res+= n - right; //do chỉ số cuối là n-1 => n-1-r+1
            sum -= a[left];
            left++;
        }                   
    }
    cout << res << endl;
}
//----------------------------------------------------------------
/* Đếm bn mảng con các phần tử liên tiếp trong mảng mà 
số lượng các phần tử khác nhau trong mảng con này không vượt quá k  
=> dùng map 
11 3
5 4 4 5 4 4 2 1 5 2 4
=> 42
*/
void segCountKElement(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    map<int, int> mp;
    int l = 0, r = 0, res = 0;
    for (int r = 0; r < n; r++){
        mp[a[r]] ++;
        while(mp.size() > k){
            mp[a[l]]--;
            if(mp[a[l]] == 0) 
               mp.erase(a[l]);
            l++;
        }
        //sau vòng while thì mp.size <= s thì có r-l+1 mảng 
        res += r - l + 1;
    }
    cout << res << endl;
}
//----------------------------------------------------------------
/* Đếm bn mảng con các phần tử liên tiếp trong mảng mà độ chênh lệch
giữa phần tử lớn nhất và phần tử nhỏ nhất trong mảng con đó không vượt quá k  
=> dùng map 
10 1
2 3 1 3 1 4 1 3 1 2 
=> 12
*/
void segCountKAbs(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    multiset<int> ms;
    int l = 0, r = 0, res = 0;
    for (int r = 0; r < n; r++){
        ms.insert(a[r]);
        while(ms.size() >= 1 && (*ms.rbegin() - *ms.begin() > k)){
            auto it = ms.find(a[l]);
            ms.erase(it);
            ++l;
        }
        //sau vòng while thì mp.size <= s thì có r-l+1 mảng 
        res += r - l + 1;
    }
    cout << res << endl;
}
//----------------------------------------------------------------
/* Xâu con liên tiếp có độ dài lớn nhất mà trong đó chứa nhiều nhất X kí tự 2 và Y kí tự 8.
8228282888 
3 3
=> 6
*/
void xau28(){
    string s; cin >> s;
    int x, y; cin >> x >> y;
    int n = s.size();
    int count2 = 0, count8 = 0;
    int l = 0, res = 0;
    for (int r = 0; r < n; r++){
        if(s[r] == '2') count2++;
        else count8++;
        while (count2 > x || count8 > y){
            // khi có nhiều hơn x số 2 và y số 8 thì thu hẹp 
            if(s[l] == '2') --count2;
            else --count8;
            ++l;
        }
        res = max(res, r-l+1);
    }
    cout << res << endl;
}
int main (){
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT/input.txt", "r", stdin);
    freopen ("D:\\AppleOfMyEye\\CTDLGT/output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    segCountKAbs();
    cout.flush();
    fclose(stdout);
}
