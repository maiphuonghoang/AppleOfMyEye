#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**Cho N!, tính N! chia dư 10^9+7
 * 1<=N<=10^6
*/
void giaiThua(){
    int n; cin >> n;
    ll gt = 1;
    for (int i = 1; i <= n; i++)
        gt = ((gt % 1000000007) * (i % 1000000007)) % 1000000007;
    cout << gt << endl;
}
/**Tính a^b % c
 * O(N)
*/
void mu(){
    int a, b, c;
    cin >> a >> b >> c;
    ll kq = 1;
    for (int i = 1; i <= b; i++){
        kq *= a;
        kq %= c;
    }
    cout << kq << endl;
}   
/**Chữ số cuối cùng
 * Tìm K chữ số cuối cùng của N^M, kết quả có thể k đủ 3 chữ số
 * Ví dụ: 9^5=59049 và K=3 thì chỉ cần in ra 49
 * Gợi ý: tính N^M chia dư cho 10^K
9 8 1
=> 1
*/
void chuSoCuoiCung(){
    int n, m, k;
    cin >> n >> m >> k;
    int mod = pow(10,k);
    ll kq = 1;
    for (int i = 1; i <= m; i++){
        kq *= n;
        kq %= mod;
    }
    cout << kq << endl;
}
//----------------------------------------------------------------
/**Tính lũy thừa nhị phân
 * a^b = a^b/2 * a^b/2 (b chẵn)
 *     = a^b/2 * a^b/2 * a (b lẻ)
 * 2^30 = 2^15 = 2^7 = 2^3 = 2^1 = 2^0
*/
//b = 10^18
ll binpow(ll a, ll b){
    if(b == 0) 
        return 1;
    ll X = binpow(a, b/2);
    if(b % 2 == 0)
        return X * X;
    else
        return X * X * a;
}
//----------------------------------------------------------------
/** Tính a^b % c dựa vào lũy thừa nhị phân 
 * O(log2củaN)
*/
ll binpowMod(ll a, ll b, ll c){
    if(b == 0) 
        return 1;
    ll X = binpowMod(a, b/2, c);
    if(b % 2 == 0)
        return (X%c) * (X%c)%c;
    else
        return  ((X%c) * (X%c)%c)* (a%c)%c;
}
ll binpowModLoop(ll a, ll b, ll c){
    ll res = 1;
    while (b){
        if(b%2){
            res *= a;
            res %= c;
        }
        a *= a;
        a %= c;
        b /= 2;
    }
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    // cout << binpow(2,10);
    // cout << binpowMod(2, 1000000, 10);
    return 0;
}