#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


/**
2352
2*1000 + 3*100+ 50 + 2
Số lượng = số tiền / mệnh giá 
2*1000 => 2352/1000=2 => thừa = 2352%1000 = 352  
*/

void doiTienThamLam(){
    int tien[] = {1000,500,200,100,50,20,10,5,2,1};
    long long n; cin >> n;
    long long cnt = 0;
    int i = 0;
    while (n!=0){
        cnt += n / tien[i];
        n = n % tien[i];
        i++;
    }
    cout << cnt << endl;
} 
//----------------------------------------------------------------
/**
888 289 123
321 54 888
=> 
888 2
123 1
289 1
*/
int checkKhongGiam(int n){
    while (n>=10){//chừng nào còn 2 chữ số thì mới check 
        int r = n%10;
        int l = n/10%10;
        if(r < l) return 0;
        n = n/10;
    }
    return 1;
}
bool cmplietKeVaDem(pair<int, int> a, pair<int, int> b){
    //In ra theo số lần xuất hiện giảm dần, trong trường hợp 
    //cùng số lần xuất hiện thì số nhỏ hơn sẽ xếp trước 
    if(a.second != b.second) 
        return a.second > b.second;
    return a.first < b.first;
}
//Nếu đề bài yêu cầu tiêu chí phụ: số nào xuất hiện trước in ra trước 
//thì trong cmp chỉ có tiêu chí chính, tiêu chí phụ thì dùng stable_sort 
bool cmplietKeVaDemXh(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second) 
        return a.second > b.second;
}

void lietKeVaDem(){
    map<int, int> mp;
    int n; 
    //Dùng khi cho đầu vào không có số lượng phần tử  
    while (cin >> n){//cứ lặp đi đến chừng nào còn cin được 
        if(checkKhongGiam(n))
            mp[n]++;
    }
    //in ra biến map
    for (auto it : mp) cout << it.first << '-' << it.second <<' ';
    //đổ dữ liệu từ trong map vào vector 
    vector <pair<int, int>> v;
    for (auto it : mp) 
        v.push_back(it);
    sort(v.begin(), v.end(), cmplietKeVaDem);
    for (auto it : v) cout << it.first << '-' << it.second <<' ';
    stable_sort(v.begin(), v.end(), cmplietKeVaDemXh);
    for (auto it : v) cout << it.first << '-' << it.second <<' ';
}
//----------------------------------------------------------------
//chinh: sx theo trị tuyệt đối tăng dần
//phụ: sx trước in ra trước  
//2 -3 3 3 -5 5 -5
bool cmpthuTuSort(int a, int b) {
    // if(abs(a) != abs(b))
        return abs(a) < abs(b);
}
void thuTuSort(){
    int a[7] = {-5,5,2,-3,3,3,-5};
    stable_sort(a, a+7, cmpthuTuSort);
    for (int x: a) cout << x << ' ';
}
//----------------------------------------------------------------
/**
4
6 -3 0 4
=> 2 1
*/
void brt(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;  

    sort (a, a + n);
    int min_val = 1e9, cnt = 0;
    for (int i = 1; i < n; i++) {
        int kc = a[i] - a[i - 1];
        if(kc < min_val){
            min_val = kc;
            cnt = 1;
        }
        else if(kc == min_val)
            cnt++;       
    }
    cout << min_val << ' '<< cnt << endl;
}
//----------------------------------------------------------------
/** Tính tổng từ l đến r
5
1 2 3 4 5 
1
1 3 
1 nghìn truy vấn từ left đến right => mảng cộng dồn
F[i] = F[i-1] + a[i]
F[L-R] = F[R] - F[L-1] 
*/
void tongLR(){
    int n; cin >> n;
    int a[n+1];
    long long F[n+1] = {0};//F[0] = 0
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        F[i] = F[i-1] + a[i];
    }
    int q; cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << F[r] - F[l - 1] << endl;
    }
}
//----------------------------------------------------------------
/** Số cặp bằng nhau 
6 
2 2 1 3 2 3 
=> 4 
8
2 2 4 4 3 4 3 4
2 - 2
4 - 4
3 - 2
2C2 + 2C4 + 2C2 
2Cn = n(n-1)/2 
*/
int d[1000005] = {0};
void capBangNhau(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) {
        cin >> x;
        d[x]++;
    }    
    long long cnt = 0;
    for (int val = 0; val <= 1e6; val++)
        cnt += 1ll* d[val]*(d[val]-1)/2;
    cout << cnt << endl;
}
//----------------------------------------------------------------
/**
2 2 3 5 8 10 20 88
=> Yes
*/
void dayUuThe(){
    int cnt_chan = 0, cnt_le = 0;
    int n;
    while (cin >> n){
        if(n%2 == 0) cnt_chan++;
        else cnt_le++;
    }
    int cnt = cnt_chan + cnt_le;
    if(cnt % 2 == 0 && cnt_chan > cnt_le) cout << "YES";
    else if(cnt %2 == 1 && cnt_le > cnt_chan) cout << "YES";
    else cout << "NO"; 
}
//----------------------------------------------------------------
/** Tìm phần tử lặp đầu tiên trong mảng 
5
1 4 4 2 2 3 1
=> 2
*/
int dl[100];
void firstLap(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) {
        cin >> x;
        dl[x]++;
        if(dl[x] == 2){
            cout << x ;
            break;
        }
    }    
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    firstLap();
    return 0;
}