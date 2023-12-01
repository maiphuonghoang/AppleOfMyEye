#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input0(a) f0(i,n) cin >> a[i]
#define output0(a) f0(i,n) cout << a[i] << " "
#define input1(a) f0(i,n) cin >> a[i]
#define output1(a) f0(i,n) cout << a[i] << " "
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Đếm dãy số
 * Cho số nguyên dương n, bạn được phép sử dụng k giới hạn các số từ 1..n. 
 * Có bao nhiêu cách chọn ra 1 dãy có tổng các phần tử = n
 * 1<=n<=10^12
 k-1   { x1+x2+...+xk = n
C      { xi >= 1
 n-1

x1 = 6                  0C5
x1+x2 = 6               1C5
x1+x2+x3 = 6            2C5
x1+x2+x3+x4 = 6         3C5
x1+x2+x3+x4+x5  = 6     4C5
x1+x2+x3+x4+x5+x6 = 6   5C5
                        2^n-1
6
=> 32
999995841
*/
ll powMod(int a, ll n){
    if(n==0) return 1;
    ll x = powMod(a, n/2);
    if(n%2==0) 
        return x*x%mod;
    return ((a%mod)*(x*x)%mod)%mod;
}
void run(){
    ll n; cin >> n;
    cout << powMod(2, n-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}