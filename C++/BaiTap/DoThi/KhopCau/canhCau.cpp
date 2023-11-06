#include <bits/stdc++.h>
using namespace std;

/**
 * Đếm số lượng cạnh cầu 
10 8
10 9
10 8
10 3
10 4
5 3
10 1
5 1
5 4 
=> So canh cau = 2
10 9
10 8

*/
const int maxn = 1001;
int n, m;
vector<int> adj[maxn];
bool visited[maxn];
vector<pair<int, int>> dscanh;

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        dscanh.push_back({x, y});
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u){
    visited[u] = true;
    for (int v : adj[u])
        if(!visited[v]) dfs(v);
}
void dfs2(int u, int s, int t){
    visited[u] = true;
    for (int v : adj[u]){
        if((u == s && v == t) || (u == t && v == s))
        //đang xét cạnh mong muốn loại khỏi đồ thị        
            continue;//k xét cạnh đấy nữa, loại bỏ cạnh (s, t)
        if(!visited[v]) dfs2(v, s, t);
        
    }
}
void canhcau(){
    int ans = 0;
    int tplt = 0;
    memset(visited, false, sizeof(visited));
    // đếm số tplt trước khi loại bỏ
    for (int i = 1; i <= n; i++){
        if(!visited[i]){
            tplt++; 
            dfs(i);
        }
    }
    for (auto it : dscanh){
        int x = it.first, y = it.second;
        // loại bỏ cạnh (x,y) khỏi đồ thị 
        memset(visited, false, sizeof(visited));
        int dem = 0;
        for (int j = 1; j <= n; j++){
            if(!visited[j]){
                ++dem;
                dfs2(j, x, y);
            }
        }
        if(dem > tplt){
            ++ans;
            cout << x << " " << y << endl;
        }
    }
    cout << "So canh cau = " << ans << endl;

}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    canhcau();
    return 0;
}