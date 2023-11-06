#include <bits/stdc++.h>
using namespace std;

/**
 * Đếm số lượng đỉnh trụ 
10 6
5 4
5 2
10 2
10 7
5 3
10 1
=>
2 5 10 
So dinh tru = 3
*/
const int maxn = 1001;
int n, m;
vector<int> adj[maxn];
bool visited[maxn];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u){
    visited[u] = true;
    for (int v : adj[u])
        if(!visited[v]) dfs(v);
}
void dinhtru(){
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
    for (int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        // xóa đỉnh khỏi đồ thị thì cho visited = false thì tự khắc k nhảy vào đỉnh này nữa 
        visited[i] = true;
        int dem = 0; //đếm tplt sau khi loại bỏ đỉnh i 
        for (int j = 1; j <= n; j++){
            if(!visited[j]){
                ++dem;
                dfs(j);
            }
        }
        if(dem > tplt){
            cout << i << " ";
            ++ans;//có thêm 1 đỉnh trụ 
        }
        
    }
    cout << "\nSo dinh tru = " << ans << endl;

}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    dinhtru();
    return 0;
}