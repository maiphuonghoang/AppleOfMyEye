#include <bits/stdc++.h>
using namespace std;
/** Đếm Số Thành Phần Liên Thông Của Đồ Thị Vô Hướng
 * VD1: 
10 8
1 2 
2 3
2 4
3 6
6 7
3 7
5 8
8 9
=>
Cac dinh thuoc thanh phan lien thong thu 1 :
1 2 3 6 7 4
Cac dinh thuoc thanh phan lien thong thu 2 :
5 8 9
Cac dinh thuoc thanh phan lien thong thu 3 :
10
So thanh phan lien thong cua do thi = 3
Do thi khong lien thong
 
 * VD2:
10 10
1 2 
2 3
2 4
3 6
6 7
3 7
3 8
5 8
5 10
8 9
Cac dinh thuoc thanh phan lien thong thu 1 :
1 2 3 6 7 8 5 10 9 4
So thanh phan lien thong cua do thi = 1
Do thi lien thong
*/

int n, m; 
vector<int> adj[1001];//dsk 
bool visited[1001];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u){
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs(v);
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    cout << u << " ";
    visited[u] = true;
    while (!q.empty()) {
    {
        int v = q.front();
        q.pop();
        for (int x : adj[v]){
            if (!visited[x]){
                cout << x << " ";
                q.push(x);
                visited[x] = true;
            }
        }
    }
    
}
}
void connectedComponent(){
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            ans++;
            cout << "\nCac dinh thuoc thanh phan lien thong thu " << ans << " : \n";
            // dfs(i);
            bfs(i);
        }
    }
    cout << "\nSo thanh phan lien thong cua do thi = " << ans << endl;
    if(ans == 1) 
        cout << "Do thi lien thong" << endl;
    else cout << "Do thi khong lien thong" << endl;
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    connectedComponent();
    return 0;
}