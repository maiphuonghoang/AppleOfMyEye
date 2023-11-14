// TIME LIMIT ERROR
#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
using ll = long long;
#define maxn 1e6
using namespace std;
int mod = 1e9 + 7;
/**
 * 
*/
void run() {
    int n; ll sum;
    cin >> n >> sum;
    ll coin[n]; 
    for (ll &x : coin) cin >> x;
    vector<ll> f(sum+1, 0);
    f[0] = 1;
    for (ll s = 1; s <= sum; s++){
        for (ll c : coin){
            if(s >= c){
                f[s] += f[s-c];         
                f[s] %= mod;
            }
        }
    }
    cout << f[sum];
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