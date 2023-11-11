// Nếu từ đỉnh u mà mở rộng ra được đỉnh v đã được thăm rồi 
// mà v không phải cha trực tiếp u thì (v->u) là cạnh ngược 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
6 6 
1 2
2 3
1 4 
4 5
5 6
6 4
=> Yes 
*/
vector<int> ke[1001];
bool visited[1001];
int parent[1001];
int n, m;

void input(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
bool bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x  = q.front(); q.pop();
        for (int y : ke[x]){
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
                parent[y] = x;
            }
            else if(y != parent[x])
                return true;
        }
    }
    return false;
}
bool dfs(int u){
    visited[u] = true;
    for (int v : ke[u]){
        if(!visited[v]) {
            parent[v] = u;
            if (dfs(v) == true)//nhánh này có chu trình mới được kết luận 
            // vì còn các nhánh khác khi nhánh này chaỵ xong 
                return true;
        }
        else if(v != parent[u]){
            return true;
        }
    }
    return false;
}
// k muốn return thì dùng cách void 
int ok = 0;
void dfs2(int u){
    visited[u] = true;
    for (int v : ke[u]){
        if(!visited[v]) {
            parent[v] = u;
            dfs2(v);
        }
        else if(v != parent[u]){
            ok = true;
        }
    }
}
void run(){
    input();
    cout << dfs(1);
    // cout << bfs(1);

    dfs2(1);
    if(ok) cout << "Yes";
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}