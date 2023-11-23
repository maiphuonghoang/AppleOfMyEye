#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;
inline ll gcd(ll a, ll b){ll r; while(b){r=a%b;a=b;b=r;} return a;}
inline ll lcm(ll a, ll b){return a/gcd(a, b)*b;};

/**Số nhị phân chia hết cho 2^x
 * Tổng các bit sau 2^k max chỉ là 2^k-1 (bật hết lên 1)
 * Để phần sau chia hết thì tất cả là bit 0 
 * .....1|000000
 *      | |    |
 *      x x-1  0
 * Check có x số 0 ở cuối 
2
101010010101010101001010101010100000000 8
11111111100001011111110000000000000000000111111111000000000
100
=> YES NO
*/
void run1(){

    string s; int x; cin >> s >> x;
    int cnt = 0;
    for(int i=s.length()-1; i>=0; i--){
        if(s[i]=='0') cnt++;
        else break;
        if(cnt >= x) break;
    }
    (cnt >= x) ? yes: no;    
    
}
/**Số nhị phân chia hết cho 5
2
1010
10000101001
=>YES YES
*/
void run2(){
    string s; cin >> s;
    int lt=1;
    int r = (s[s.length()-1] - '0')%5;
    for (int i=s.length()-2; i>=0; i--){
        lt *= 2;
        r = r+(s[i]-'0')*lt;
        r%=5;
    }
    r==0? yes:no;  
}
//----------------------------------------------------------------
/**Phép chia dư của số nguyên lớn 
 * Tìm k = n % m
 * Số dư của hàng trước * 10 + số hiện tại rồi chia dư  
2
12345 10
182644141451344514145256 8
=> 5 0 
*/
void run3(){
    string s; cin >> s;
    ll m; cin >> m;
    int r = 0;
    for (char x : s){
        r = (r*10)+(x-'0');
        r %= m;
    }
    cout << r << endl;
}
/**Phép chia dư của lũy thừa số nguyên lớn 
 * Tính k = (a^b) % m
 * Tìm số dư của (a % m)^b %m thay cho (a^b) % m
 * Hàm 1: tìm số dư của 1 số nguyên lớn với 1 số long long
 * Hàm 2:  tính a^b % m;
2
3 2 4
123551655485315131256 1000 10
=> 1  6 
*/
ll du(string a, ll m){
    ll r=0;
    for (char x : a){
        r = r*10+x-'0';
        r%=m;
    }
    return r;
}
ll binpow(ll a, ll b, ll m){
    ll res = 1;
    while(b){
        if(b%2==1){
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        b /= 2;
    }
    return res;
}
void run4(){
    string a;
    ll b, m; cin >> a >> b >> m;
    ll r= du(a, m);
    cout << binpow(r, b, m) << endl;
}
//--------------------------------------------------------------
/**Ước chung lớn nhất của 1 số nguyên lớn với 1 số long long
 * a <= 10^12; b <= 10^250
 * => Tìm kết quả chia dư của b%a
1
1221
1234567891011121314151617181920212223242526272829
=> 3
*/
void run5(){
    ll a; string b; cin >> a >> b;
    ll r = du(b, a);
    cout << gcd(a, r) << endl;
}
//------------------------------------------------
/**Số chia hết cho 11
 * n <= 10^1000
2
76945
363588395960667043875487
=> YES NO
*/
void run6(){
    string s; cin >> s;
    (du(s, 11) == 0) ? yes : no;
}
/* 11187
    tìm độ chênh lệch của vị trí chẵn và lẻ cho 11
    (1+1+7) - (1+8) = 0 chia hết cho 11

    Số có số chẵn số 0 đằng sau 1, 100, 10000, 1000000 chia 11 dư 1
    Số có số chẵn số 1 đằng sau 10, 1000 chia 11 dư -1
    (a*b)%c = (a%c)*(b%c) %c
    1234
    = (1.1000 +2.100 +3.10 +4) % 11
    = 1.(-1) + 2.1 + 3.(-1) + 4.1
*/
void run7(){
    string s; cin >> s;
    int r = 0;
    for(int i=0; i<s.length(); i++){
        if(r%2==0) r += s[i]-'0';
        else r -= s[i] - '0';
    }
    (r %= 11)? yes: no;
}
//----------------------------------------------------------------
/** Số chia hết cho 8 và k chia hết cho 3
 * Đếm số các xâu con của S tm
2 
888
6564525600
=> 5 15
*/
int count(string s, int x){
    int res = 0;
    for (int i=0; i<s.length(); i++){
        int sum = 0;
        for(int j=i; j<s.length(); j++){
            sum = sum * 10 + (s[j] - '0');
            sum %= x;
            if(sum == 0) ++res;
        }
    }
    return res;
}
void run8(){
    string s; cin >> s;
    cout << count(s, 8) - count(s, 24) << endl;
}
//Cách quy hoạch động 
void run(){
    string s; cin >> s;
    int len = s.length();
    int dp[len+1][3]; 
    //dp[i][j]  lưu số xâu con bắt đầu từ chỉ số 0 và kết thúc tại 1 chỉ số <= i chia 3 dư j
    int pre[len+1];
    //pre[i]: lưu tổng các chữ số của xâu s kết thúc tại vị trí i chia dư cho 3
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    int sum = 0;
    dp[0][0] = 1;//xâu rỗng 
    // xây dựng bảng dp[i][j]
    for(int i=1; i<=len; i++){
        sum += s[i-1] - '0';
        sum %= 3;
        pre[i] = sum;
        dp[i][sum]++;
        dp[i][0] += dp[i-1][0];
        dp[i][1] += dp[i-1][1];
        dp[i][2] += dp[i-1][2];
    }
    int ans = 0;
    for (int i=1; i<=len; i++){
        //duyệt các số có chiều dài 1,2...
        int num = s[i-1] - '0';
        if(num==8) ++ans;//số 8 
        if(i>=2){
            int tmp = (s[i-2] - '0')*10 +(s[i-1]-'0');
            if(tmp %8 == 0 && tmp %3 != 0)
                ans++;
        } 
        if(i >= 3){//có 3 chữ số trở lên 
            int tmp = (s[i-3] - '0')*100 +(s[i-2]-'0')*10 + s[i-1]-'0';
            if(tmp %8 == 0){
                ans += i-2;
                ans -= dp[i-3][pre[i]];
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    int t; cin >> t; cin.ignore();
    while(t--){
        run();
    }
    // run
    return 0;
}