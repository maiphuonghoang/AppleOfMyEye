#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * Tìm đường đi ngắn nhất giữa đỉnh nguồn với mọi đỉnh trên đồ thị 
6 8 1  
1 2 7
1 3 12
2 3 2
2 4 9
3 5 10
4 6 1
5 4 4
5 6 5
=> 0 7 9 16 19 17 
6 8 1 5
1 2 7
1 3 12
2 3 2
2 4 9
3 5 10
4 6 1
5 4 4
5 6 5
=> 19
1 2 3 5
*/
const int maxn = 1001;
const int INF = 1e9;
int n, m, s;//s là đỉnh bắt đầu 
vector <pair<int,int>> adj[maxn];
int pre[maxn];

void input(){
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        // adj[y].push_back({x, w});
    }
}
void dijkstra(int s){
    // Mảng lưu khoảng cách đường đi
    vector<ll> d(n+1, INF);

    vector<bool> visited(n+1, false);
    d[s] = 0;
    pre[s] = s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    // lưu {khoảng cách, đỉnh}
    Q.push({0,s}); //đẩy đỉnh s, khoảng cách từ đỉnh nguồn đến s = 0
    while(!Q.empty()){
        //Chọn ra đỉnh có khoảng cách từ s nhỏ nhất 
        pair<int, int> top = Q.top(); Q.pop();
        int u = top.second;
        int kc = top.first;


        if(kc > d[u]) continue;


        // Relaxation: Cập nhật khoảng cách từ s cho tới mọi đỉnh kề với u
        for (auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }

    }
    for (int i = 1; i<= n; i++) 
            cout << d[i] << " ";

}
void dijkstraPath(int s, int t){
    // Mảng lưu khoảng cách đường đi
    vector<ll> d(n+1, INF);
    d[s] = 0;
    pre[s] = s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    // lưu {khoảng cách, đỉnh}
    Q.push({0,s}); //đẩy đỉnh s, khoảng cách từ đỉnh nguồn đến s = 0
    while(!Q.empty()){
        //Chọn ra đỉnh có khoảng cách từ s nhỏ nhất 
        pair<int, int> top = Q.top(); Q.pop();
        int u = top.second;
        int kc = top.first;

        //Trong queue sẽ tồn tại rất nhiều phiên bản của 1 đỉnh nào đó, có kcach khác nhau thôi  
        if(kc > d[u]) continue;
        // Có thể dùng câu này thay cho câu trên
        // if(visited[u]) continue;//đỉnh này được xét rồi 

        // Relaxation: Cập nhật khoảng cách từ s cho tới mọi đỉnh kề với u
        for (auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
                pre[v] = u; //trước v là u 
            }
        }

    }
    cout << d[t] << endl;
    vector<int> path;
    while(1){
        path.push_back(t);
        if(t==s) break;
        t = pre[t];
    }
    reverse(begin(path), end(path));
    for(int x : path) cout << x << " ";

}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    // dijkstra(s);
    int t = 5;//tìm đường đi từ đỉnh 1 tới 5 
    dijkstraPath(s, t);
    return 0;
}