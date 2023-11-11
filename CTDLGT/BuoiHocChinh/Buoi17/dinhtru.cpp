#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int> ke[1001];
bool visited[1001];
int n, m;

void input(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x  = q.front(); q.pop();
        for (int y : ke[x]){
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}
void dfs(int u){
    visited[u] = true;
    for (int v : ke[u])
        if(!visited[v]) {
            dfs(v);
        }
}
int tplt(){
    int count = 0;
    for (int i = 1; i <=n; i++){
        if(!visited[i]){
            count++;
            dfs(i);
        }
    }
    return count;
}
void dinh_tru(){
    int cc = tplt();//số thành phần liên thông ban đầu 
    for (int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        if(cc < tplt())
            cout << i << ' ';
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif

    return 0;
}