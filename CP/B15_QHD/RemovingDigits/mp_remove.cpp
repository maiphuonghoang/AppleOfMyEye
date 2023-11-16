
#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
using ll = long long;
#define maxn 1e6
using namespace std;
int mod = 1e9 + 7;
/**
 * https://cses.fi/problemset/task/1637
*/
int F[1000006];
int tinh(int n){
    if(n == 0) return 0;
    if(F[n] != 0) return F[n];
    int m = n;
    int res = 1e9;
    while (m){
        int r = m % 10;
        if(r != 0)
            res = min(res, tinh(n-r) + 1);
        m/= 10;
    }
    return F[n] = res;
}
void run() {
    int n; cin >> n;
    cout << tinh(n);
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
