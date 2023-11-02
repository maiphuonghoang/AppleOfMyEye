#include <bits/stdc++.h>
using namespace std;
/**
10 8
1 2 
2 3
2 4
3 6
6 7
3 7
5 8
8 9
1 7

=> s=1, t=7
1 2 3 6 7 (DFS)
1 2 3 7 (BFS)
s=1, t=10
Khong co duong di 
*/

int n, m; 
vector<int> adj[1001];//dsk 
bool visited[1001];
int parent[1001];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void dfs(int u){
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v]){
            //Ghi nhận cha của v là u 
            parent[v] = u;
            dfs(v);
        }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int x : adj[v]){
            if (!visited[x]){
                //Ghi nhận cha của x là v 
                parent[x] = v;
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
void Path(int s, int t){
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    // dfs(s);
    bfs(s);
    if(!visited[t]){
        cout << "Khong co duong di" << endl;
    }
    else{//Truy vết đường đi 
        vector<int> path;
        while(t != s){//chừng nào chưa đến điểm bắt đầu 
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int x : path) cout << x << " ";
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    int s, t; cin >> s >> t;//điểm bắt đầu và kết thúc 
    Path(s,t);
    return 0;
}