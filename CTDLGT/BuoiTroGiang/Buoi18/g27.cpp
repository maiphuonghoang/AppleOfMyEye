#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/**
 * Tìm tplt có nhiều đỉnh nhất 
10 6
8 2 
4 1
8 6
8 7
8 1
8 5 
=> 7
*/

int n, m;
vector<int> adj[100005];
bool used[100005];
int cnt = 0;
void dfs(int u){
    cnt++;
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
    int res = 1;
    f1(i, n){
        if(!used[i]){
            cnt = 0;//reset lại biến đếm cho mỗi tplt 
            dfs(i);
            res = max(res, cnt); 
        }
    }
    cout << res << endl;
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