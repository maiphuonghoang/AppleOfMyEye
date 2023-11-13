#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
// Khoảng cách từ 1 đỉnh đến mọi đỉnh còn lại trên đồ thị vô|có hướng k có cạnh âm 
/*
6 8
1 2 1
2 3 1
1 3 5
2 4 4
3 5 2
5 4 2 
4 6 2
5 6 7
=> 0 1 2 5 4 7 
1->1 = 0; 1->2 = 1; 1->3 = 2
*/
const int maxn = 100001; 
int n, m;
vector<ii> adj[maxn];//lưu cạnh kề và trọng số 
bool taken[maxn];

void input(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        // adj[y].push_back({x,w});
    }
}
void dijkstra(int s){
    vector<int> d(n+1, 1e9);
    d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push({0, s});
    while(!Q.empty()){
        // Chọn ra đỉnh u có đường đi ngắn nhất => relaxation
        ii top = Q.top(); Q.pop();
        int u = top.second, kc = top.first;
        if(kc > d[u]) continue;//đây là 1 phiên bản k phải ngắn nhất nằm trong queue
        // relax
        for (auto it : adj[u]){
            int v = it.first, w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    for (int i=1; i<=n; i++) cout << d[i] << " ";
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    input();
    dijkstra(1);
    return 0;
}