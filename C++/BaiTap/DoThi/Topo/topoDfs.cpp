#include <bits/stdc++.h>
using namespace std;

/**
7 7 
1 2
2 3
2 4
3 5
4 5
1 6
7 6
=> 7 1 6 2 4 3 5
*/
const int maxn = 1001;
vector<int> adj[maxn];
bool visited[maxn];
vector<int> topo;
int n, m;

void dfs(int u){
    visited[u] = true;
    for (int x : adj[u]) {
        if (!visited[x])
            dfs(x);
    }
    //khi 1 đỉnh đã được thăm xong (gọi hết tất cả các con của nó rồi) 
    //thì mới đến dòng này, mới được đẩy u vào topo 
    topo.push_back(u);
}
void input(){
    cin >> n >> m;
    for (int i = 0; i <m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);//đồ thị có hướng 
    }
}
void topoDfs(){
    memset(visited, false, sizeof(visited));
    for (int i = 1; i<=n; i++){
        if(!visited[i]) dfs(i);
    }
    reverse(topo.begin(), topo.end());
    for (int x : topo) cout << x << " ";

}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    topoDfs();
    return 0;
}