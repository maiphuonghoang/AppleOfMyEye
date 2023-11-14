#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define maxn 100007
using namespace std;
using ll = long long;
int mod = 1e9 + 7;
/**
 * https://cses.fi/problemset/task/1634/
*/
// f[s]: số xu nhỏ nhất tạo ra tổng là s 
void run() {
    int n; ll sum; 
    cin >> n >> sum;
    ll a[n];
    for (ll &x : a) cin >> x;
    vector<ll> f(sum+1, 0);
    f[0] = 0;     
    // O(sum*n) = 10^7   
    for (ll s = 1; s <=sum; s++) {
        f[s] = 1e9;
        for (ll i = 0; i < n; i++){
            if(s - a[i] >= 0){
                f[s] = min(f[s], f[s - a[i]] + 1);
            }
        }
    }
    if(f[sum] == 1e9)
        cout << "-1" << endl;
    else cout << f[sum] << endl;
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
