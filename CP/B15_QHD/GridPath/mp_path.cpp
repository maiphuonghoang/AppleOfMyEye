#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
using ll = long long;
#define maxn 1e6
using namespace std;
int mod = 1e9 + 7;
/**
 * https://cses.fi/problemset/task/1638
*/
int F[1001][1001];
char a[1001][1001];

void run() {
    int n, m; cin >> n; m = n;
    F[0][1] = 1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if(a[i][j] == '.')
                F[i][j] = F[i-1][j] + F[i][j-1];
            else 
                F[i][j] = 0;
            F[i][j] %= mod;
        }
    }
    cout << F[n][m];
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
