#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
10 10
1 10
1 2
1 3 
1 4
2 5
2 7
3 6
4 8
5 9
7 10
9 10
=> 
dfs 1 2 5 9 10
bfs 1 2 7 10 
*/

vector<int> ke[1001]; //dsk 
bool visited[1001];
int n, m, s, t;
int parent[1001];

void input(){
    cin >> n >> m >> s >> t;
    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    // Trong quá trình mở rộng thuật toán thì ưu tiên đỉnh có số thứ tự nhỏ hơn trước 
    // => sort dsk của từng đỉnh 
    for (int i=1; i<=n; i++){
        sort(ke[i].begin(), ke[i].end());
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
                parent[y] = x;
            }
        }
    }
}
void dfs(int u){
    visited[u] = true;
    for (int v : ke[u])
        if(!visited[v]) {
            dfs(v);
            parent[v] = u;
        }
}
void run(){
    input();
    dfs(s);
    // bfs(s);
    if(!visited[t]) //k có đường đi từ s tới t 
    {
        cout << "-1 ";
    }
    else//truy vết đường đi 
    {
        vector<int> res;
        while(t != s){
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        for (int x : res) cout << x << " ";
    }
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}