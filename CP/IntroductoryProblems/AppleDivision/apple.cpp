#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
using ll = long long;
#define maxn 1e6
using namespace std;
int mod = 1e9 + 7;
/**
 * https://cses.fi/problemset/task/1623
*/
void run() {
    int n; cin >> n;
    int w[n];
    ll sum1, sum2;
    ll res = (ll) 1e18+5;
    for (int &x : w) cin >> x;
    for (int i = 0; i < (1 << n); i++){
        sum1 = sum2 = 0;
        for (int j = 0; j < n; j++){
            //tìm ra bit thứ i là 0 hay 1 
            if (i & (1 << j))
                sum1 += w[j];
            else 
                sum2 += w[j];
        }
        res = min(res, abs(sum1 - sum2));
    }
    cout << res, el;
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
