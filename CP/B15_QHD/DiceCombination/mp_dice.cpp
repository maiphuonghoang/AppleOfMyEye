/*
https://cses.fi/problemset/task/1633
*/
#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;
int mod = 1e9 + 7;

void run() {
    ll n; cin >> n;
    vector<ll> f(n + 1, 0); // Using vector instead of array

    f[0] = 1;
    for (ll s = 0; s <= n; s++)
        for (int i = 1; i <= 6; i++) {
            if (s >= i) {
                f[s] += f[s - i];
                f[s] %= mod;
            }
        }
    cout << f[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE 
    // freopen ("D:\\AppleOfMyEye\\CP\\input.txt", "r", stdin);
    // #endif
    run();
    return 0;
}
