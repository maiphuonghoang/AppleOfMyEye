//Code này dùng mảng parent, in ra chu trình 
#include <bits/stdc++.h>
using namespace std;
/**
8 6 
1 2 
2 3
4 5
4 6
5 6
5 7
=> Yes
Cycle: 4 5 6 4
*/
int n, m;
vector<int> adj[1001];
bool visited[1001];

int parent[1001];
int top, last;

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
bool DFS(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if(!visited[v])
        {   
            parent[v] = u;
            if(DFS(v)) 
                return true;
        }
        else if (v != parent[u]) {
            top = v; last = u;
            return true;          
        }
    }

    //đã duyệt xong tất cả đỉnh kề 
    return false;//không có chu trình 
}
void path(){
    vector<int> cycle;
    cycle.push_back(top);
    while (last != top)
    {
        cycle.push_back(last);
        last = parent[last];//truy vết ngược lại, nó=cha nó 
    }
    cycle.push_back(top);

    reverse(cycle.begin(), cycle.end());
    for (int x : cycle) cout << x << " ";
}
void run(){
    input();
    for (int i = 0; i <= n; i++){
        if(!visited[i]){
            if(DFS(i)){
                cout << "Yes" << endl;
                path();
                return ;
            }
        }
    }
    //duyệt xong tất cả thành phần liên thông của đồ thị rồi mới KL là no 
    cout << "No"<< endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}
