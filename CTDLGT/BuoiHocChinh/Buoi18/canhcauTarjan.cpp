#include <bits/stdc++.h>
using namespace std;

// Tìm cạnh cầu với tarjan O(V+E)
const int maxn = 1001;
int n, m, timer = 0;
vector<int> ke[maxn];
bool visited[maxn];
int disc[maxn], low[maxn];
vector<pair<int, int>> bridge;

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u, int par){
    disc[u] = low[u] = ++timer;
    visited[u] = true;
    for (int v : ke[u]){
        if(v == par) continue;
        if(!visited[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            // K là đỉnh nguồn 
            if(par != -1 && low[v] > disc[u])
                bridge.push_back({u, v});
        }else{
            low[u] = min(low[u], disc[v]);
        }
    }
}
void runCauTarjan(){
    input();
    for (int i=1; i<=n; i++)
        if(!visited[i])
            dfs(i, -1);
    for (auto e : bridge){
        cout << e.first << " " << e.second << endl;
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    runCauTarjan();
    return 0;
}