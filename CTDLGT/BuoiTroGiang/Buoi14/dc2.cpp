#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input(a) f0(i,n) cin >> a[i]
#define output(a) f0(i,n) cout << a[i] << " "
using ll = long long;
using namespace std;
int mod = 1e9 + 7;

/** Lũy thừa nhị phân đảo 
 * Cho số nguyên dương n, m là số đảo của n. 
 * Tính lũy thừa với cơ số n với số mũ n
8
=> 16777216
999995841
*/
ll powMod(int a, int n){
    if(n==0) return 1;
    ll x = powMod(a, n/2);
    if(n%2==0){
        return x*x%mod;
    }
    else  {
        return ((a%mod)*(x*x)%mod)%mod;
    }  
}

int daoNguoc(int n){
    int s = 0;
    while(n){
        s = s*10 + n%10;
        n /= 10;
    }
    return s;
}
void run(){
    int n; cin >> n;
    cout << powMod(n, daoNguoc(n));
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
