#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/**
 * Các ptu k thuộc cùng 1 tplt với 1 số 
6 4
1 3
2 3
1 2
4 5
=> 4 5 6
*/

int n, m;
vector<int> adj[100005];
bool used[100005];
void dfs(int u){
    used[u] = true;
    for (int v : adj[u])
        if(!used[v]){
            dfs(v);
        }
}
void run() {
    cin >> n >> m;
    f0(i, m){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    } 
    dfs(1);
    int ok = 0;
    f1(i, n){
        if(!used[i]){
            ok = 1;
            cout << i << " ";
        }
    }
    if(!ok) cout << 0;
    
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