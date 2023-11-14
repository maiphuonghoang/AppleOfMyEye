#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
using ll = long long;
#define maxn 100006
#define MOD 1000000007
using namespace std;

/**
 * 
*/
int n, f[maxn];
void run() {
    int n; cin >> n;
    f[0] = 1;
    for (int i=1; i<=n; i++){
        for (int j = max(0,i-6); j<=i-1; j++)
            f[i] = (f[i] + f[j]) % MOD;
    }
    // hoặc 
    for (int i=1; i<=n; i++){
        for (int j = 1; j <= min(6,i); j++)
            (f[i]+= f[i-j]) % MOD;
    }
    cout << f[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CP\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}
