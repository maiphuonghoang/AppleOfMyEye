#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;
int mod = 1e9 + 7;
/**
 * https://cses.fi/problemset/task/1674
*/
const int maxn = 2e5 + 5;
int n, sub[maxn];
vector<int> adj[maxn];

void dfs(int u, int parent){
    sub[u] = 1;
    for (int v : adj[u]){
        dfs(v, u);
        sub[u] += sub[v]; 
    }
}
void run() {
    cin >> n;
    for(int x=2; x<=n; x++){
        int y; cin >> y;
        adj[y].push_back(x);
    }
    dfs(1,-1);
    f1(i, n) cout << sub[i] - 1 << " ";
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
