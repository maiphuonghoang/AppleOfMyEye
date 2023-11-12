#include <bits/stdc++.h>
using namespace std;

// Tìm đỉnh trụ với tarjan O(V+E)
const int maxn = 1001;
int n, m, timer = 0;
vector<int> ke[maxn];
bool visited[maxn], AP[maxn];
int disc[maxn], low[maxn];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(AP, false, sizeof(AP));
}
void dfs(int u, int par){
    disc[u] = low[u] = ++timer;
    int child = 0;
    visited[u] = true;
    for (int v : ke[u]){
        if(v == par) continue;
        if(!visited[v]){
            dfs(v, u);
            ++child;
            low[u] = min(low[u], low[v]);
            // K là đỉnh nguồn 
            if(par != -1 && low[v] >= disc[u])
                AP[u] = true;
        }else{
            low[u] = min(low[u], disc[v]);
        }
    }
    // Là đỉnh nguồn, tối thiểu 2 con 
    if(par == -1 && child > 1) 
        AP[u] = true;
}
void runTruTarjan(){
    input();
    for (int i=1; i<=n; i++)
        if(!visited[i])
            dfs(i, -1);
    for (int i=1; i<=n; i++)
        if(AP[i])
            cout << i << " ";
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    runTruTarjan();
    return 0;
}