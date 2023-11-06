#include <bits/stdc++.h>
using namespace std;

/*
6 5 
2 1
2 3
3 4
5 4
1 6 
=> Yes 
*/

int n, m; 
const int maxn = 1001;
vector<int> adj[maxn];
int color[maxn];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(color, -1, sizeof(color));
}
bool bfs(int u){
    queue<int> q;
    q.push(u);
    color[u] = 0;//0: red;
    while(!q.empty()){
        int v = q.front(); q.pop();
        // duyệt các đỉnh kề của v và tô màu 
        for (int x : adj[v]){
            if(color[x] == -1){//x chưa được tô màu 
                // tô màu x khác v
                color[x] = 1 - color[v];
                q.push(x);
            }
            else if(color[x] == color[v])
                return false;
        }
    }
    return true;
}
bool dfs(int u, int parent){
    color[u] = 1 - color[parent];
    for (int v : adj[u]){
        if(color[v] == -1){
            if(!dfs(v, u)) return false;
        }
        else if(color[v] == color[u]) return false;
    }
    return true;
}
void runBfs(){
    // Xét tất cả thành phần liên thông 
    input();
    bool check = true;
    for (int i = 1; i <= n; i++){
        if(color[i] == -1){
            if(!bfs(i)){
                check = false; break;
            }
        }
    }
    check? cout << "Yes": cout << "No";
}
void runDfs(){
    input();
    bool check = true;
    color[0] = 1;
    for (int i = 1; i <= n; i++){
        if(color[i] == -1){
            if(!dfs(i, 0)){
                check = false; break;
            }
        }
    }
    check? cout << "Yes": cout << "No"; 
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    runDfs();
    return 0;
}