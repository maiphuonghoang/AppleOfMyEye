#include <bits/stdc++.h>
using namespace std;

// Đếm số lượng thành phần liên thông mạnh 
/*
5 6
1 2
2 3
3 1
2 4
4 5
5 2
=> 
disc low 
1 1
2 1
3 1
4 2
5 2
*/
/*
5 7
1 2
2 3
3 1
2 4
4 5
5 2
5 1
=>
disc low 
1 1
2 1
3 1
4 1
5 1
*/

const int maxn = 1001;
int n, m, timer = 0;
vector<int> ke[maxn];
bool visited[maxn];
int disc[maxn], low[maxn];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u){
    disc[u] = low[u] = ++timer;
    visited[u] = true;
    for (int v : ke[u]){
        if(!visited[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }else{
            low[u] = min(low[u], disc[v]);
        }
    }
}
void runTarjan(){
    input();
    dfs(1);
    for (int i=1; i<=n; i++)
        cout << disc[i] << " " << low[i] << endl; 
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    runTarjan();
    return 0;
}