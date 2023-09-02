#include <bits/stdc++.h>
using namespace std;


int n,k, a[1005], ok;
void ktaoXauNhiPhan(){
    for (int i=1; i<=n; i++)
        a[i] = 0;
}
void nextNhiPhan(){
    int i = n;
    while(i>=1 && a[i]==1){
        a[i] = 0;
        i--;
    }
    if(i==0)
        ok = 0;
    else
        a[i] = 1;
}
/**
 * Liệt kê tất cả các xâu AB có độ dài n chứa duy nhất 1 dãy kí tự A liên tiếp
7 3
=> 26
AAABAAB AAABABA AAABABB AAABBAA AAABBAB
AAABBBA AAABBBB AABAAAB AABBAAA ABAAABA
ABAAABB ABABAAA ABBAAAB ABBBAAA BAAABAA
BAAABAB BAAABBA BAAABBB BAABAAA BABAAAB
BABBAAA BBAAABA BBAAABB BBABAAA BBBAAAB
BBBBAAA  
*/
bool check1CumKkituA(){
    int res=0, dem=0;
    for (int i =1; i <=n; i++){
        if(a[i] == 0) 
            dem++;
        else dem = 0;
        if(dem > k) return false;
        if(dem == k) ++res;
    }
    return res == 1;
}
void C1run1CumKkituA(){
    cin >> n >> k ;
    ok = 1; int ans = 0;
    ktaoXauNhiPhan();
    while(ok){
        if(check1CumKkituA())
            ++ans;        
        nextNhiPhan();
    }
    cout << ans << endl;
    ok = 1;
    ktaoXauNhiPhan();
    while(ok){
        if(check1CumKkituA()){
            for (int i = 1; i <= n; i++)
                if(a[i]) cout << "B";
                else cout << "A";
            cout << endl;
        }
        nextNhiPhan();
    }
}
void C2run1CumKkituA(){
    cin >> n >> k;
    vector<vector<int>> v;
    ok = 1;
    ktaoXauNhiPhan();
    while(ok){
        if(check1CumKkituA()){
            //copy nội dung của mảng vào vector 
            vector<int> tmp(a+1, a+n+1);   
            v.push_back(tmp);
        }
        nextNhiPhan();
    } 
    // số lượng cấu hình thỏa mãn
    cout << v.size() << endl;   
    for (vector<int> it : v){
        for (int x : it)
            if(x == 1) cout << "B";
            else cout << "A";
        cout << endl;
    }
}
//----------------------------------------------------------------
/**Cho 1 nhóm K chiến sĩ hiện đang tập đội ngũ. Tính xem trong lượt chọn K người tiếp theo
 * thì mấy người trong nhóm cũ sẽ được tạm nghỉ. Nếu là nhóm cuối cùng thì tất cả sẽ được nghỉ 
3
5 3
1 3 5
5 3
1 4 5 
6 4
3 4 5 6
=> 
1
2 
4 
*/
set<int> se;
void nextQuanSu(){
    int i = k;
    while(i>=1 && a[i] == n-k+i)
        i--;
    if(i == 0)
        cout << k;
    else{
        a[i]++;
        for (int j=i+1; j<=k; j++)
            a[j] = a[j-1] + 1;
        int cnt = 0;
        for (int i = 1; i <= k; i++){
            //nếu k tìm thấy a[i] trong se
            if(se.find(a[i]) == se.end()){
                cnt++;
            }
        }
        cout << cnt;
    }
}
void runQuanSu(){
    int t; cin >> t;
    while(t--){
        cin >> n >>k;
        for (int i=1; i<=n; i++){
            cin >> a[i];
            se.insert(a[i]);
        }
        nextQuanSu();
        se.clear();
    }
}
//----------------------------------------------------------------
/**Cho ma trận vuông cấp n. Lấy mỗi hàng, mỗi cột duy nhất 1 ptu 
 * sao cho tổng các ptu này đúng = k
3 10
2 4 3
1 3 6
4 2 4
=> 2
1 3 2 (2 + 6 + 2)
3 2 1 (3 + 3 + 4)
hàng: i (1->n)
cột:  a[i]
*/
int mt[100][100];
void hoanViTongK(){
    cin >> n >> k;  
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <=n; j++)
            cin >> mt[i][j];
    //khởi tạo cấu hình đầu tiên 
    for (int i = 1; i <= n; i++)
        a[i] = i;
    vector<vector<int>> v;
    do{
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += mt[i][a[i]];
        if(sum == k){
            vector<int> tmp(a+1, a+n+1);
            v.push_back(tmp);
        }
    }while(next_permutation(a + 1, a+n+1));

    cout << v.size() << endl;
    for (vector<int> it : v){
        for (int x : it)
            cout << x << " ";          
        cout << endl;
    }
}
/**
Loop through the matrix mt and array a to calculate the sum for different permutations:

Initial a array: [1, 2, 3]
i = 1: sum += mt[1][a[1]] (1st row, 1st column) => sum += 2 => sum becomes 2
i = 2: sum += mt[2][a[2]] (2nd row, 2nd column) => sum += 3 => sum becomes 5
i = 3: sum += mt[3][a[3]] (3rd row, 3rd column) => sum += 4 => sum becomes 9
After the first permutation, sum is 9, but it doesn't equal k (which is 10). 
So, this permutation [1, 2, 3] is not added to the v vector.
Generate the next permutation of a: [1, 3, 2].

i = 1: sum += mt[1][a[1]] (1st row, 1st column) => sum += 2
i = 2: sum += mt[2][a[2]] (2nd row, 3rd column) => sum += 6
i = 3: sum += mt[3][a[3]] (3rd row, 2nd column) => sum += 2
The sum is now 10, it equal k, so this permutation is added to the v vector.
Generate the next permutation of a: [2, 1, 3].

i = 1: sum += mt[1][a[1]] (1st row, 2nd column) => sum += 4
i = 2: sum += mt[2][a[2]] (2nd row, 1st column) => sum += 1
i = 3: sum += mt[3][a[3]] (3rd row, 3rd column) => sum += 4
The sum doesn't equal k, so this permutation is not added to the v vector.
Generate the next permutation of a: [2, 3, 1].

i = 1: sum += mt[1][a[1]] (1st row, 2nd column) => sum += 4
i = 2: sum += mt[2][a[2]] (2nd row, 3rd column) => sum += 6
i = 3: sum += mt[3][a[3]] (3rd row, 1st column) => sum += 4
The sum doesn't equal k, so this permutation is not added to the v vector.
Generate the next permutation of a: [3, 1, 2].

i = 1: sum += mt[1][a[1]] (1st row, 3rd column) => sum += 3
i = 2: sum += mt[2][a[2]] (2nd row, 1st column) => sum += 1
i = 3: sum += mt[3][a[3]] (3rd row, 2nd column) => sum += 3
The sum doesn't equal k, so this permutation is not added to the v vector.
Generate the next permutation of a: [3, 2, 1].

i = 1: sum += mt[1][a[1]] (1st row, 3rd column) => sum += 3
i = 2: sum += mt[2][a[2]] (2nd row, 2nd column) => sum += 4
i = 3: sum += mt[3][a[3]] (3rd row, 1st column) => sum += 4
The sum is now 10, it equals k, so this permutation is added to the v vector.
*/
//----------------------------------------------------------------
/**Tìm số nguyên x nhỏ nhất là bội của n (1<n<500)
 * X chỉ chứa 2 chữ số 0 và 9
3 
2 5 11
=> 
90 90 99
Sinh ra tất cả các số hình thành từ 0 và 9 từ 1-500
*/
#define ll long long
ll b[505]; //dùng để lưu bội 
vector<ll> res; //lưu số mà s sinh ra 
void next09(string &s){
    int i = s.length() - 1;
    while(i >= 0 && s[i]=='9'){
        s[i] = '0';
        i--;
    }
    if(i == -1)
        ok = 0;
    else
        s[i] = '9';
}
void boiSo(){
    ok = 1;
    string s(13, '0');//string s có 13 kí tự, tất cả là kí tự 0
    next09(s);//bỏ qua xâu 0000000
    while(ok){
        res.push_back(stoll(s));
        next09(s);
    }
    for(int i=1; i<=500;i++)
        for (ll x: res)
            if(b[i]==0 && x%i==0)
                b[i] = x;
    int cnt = 0;
    for (int i=1; i<=500; i++){
        cout << i << " co boi la " << b[i] << endl;
        if(b[i]!=0) cnt++;
    }
    cout << cnt <<endl;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << b[n] << endl;
    }
}
//----------------------------------------------------------------
/**Một xâu kí tự được coi là HAHA nếu
 * - Kí tự đầu tiên phải là chữ H, kí tự cuối cùng phải là chữ A
 * - Không có 2 kí tự H nào liền nhau 
0: A, 1: H
2
2 
4
=>
HA
HAAA HAHA
*/
bool checkHA(){
    if(a[1] == 0 || a[n] == 1)
        return false;
    for (int i=1; i<=n-1;i++)
        if(a[i] == 1 && a[i+1] == 1)
            return false;
    return true;
    
}
void runHA(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        ok = 1;
        ktaoXauNhiPhan();
        while(ok){
            if(checkHA()){
                for (int i=1; i<=n; i++)
                    if(a[i]==0) cout << "A";
                    else cout << "H";
                cout << endl;
            }
            nextNhiPhan();
        }
    }
}
bool checkThuanNghich(){
    int l = 1, r = n;
    while(l < r){
        if(a[l] != a[r])
            return false;
        l++; r--;
    }
    return true;
}
//----------------------------------------------------------------
/**Chia táo thành 2 phần sao cho sự khác biệt giữa tổng 2 phần là nhỏ nhất 
5
3 2 7 4 1  
=> 1
sinh ra tất cả các cách chia n quả táo thành 2 phần 
=> sinh xâu nhị phân 01101 (0 là group1, 1 là group2)
*/
void chiaTao(){
    cin >> n;
    int w[n+1];
    for (int i=1; i<=n; i++)
        cin >> w[i];
    ok = 1;
    ktaoXauNhiPhan();
    ll ans = 1e12;
    while (ok){
        ll sumBit0 = 0, sumBit1 =0;
        for (int i=1; i<=n; i++){
            if(a[i]==0)
                sumBit0 += w[i];
            else 
                sumBit1 += w[i];
            ans = min(ans, abs(sumBit1-sumBit0));
        }
        nextNhiPhan();
    }
    cout << ans;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    chiaTao();
    return 0;
}

