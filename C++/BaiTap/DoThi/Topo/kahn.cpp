#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
vector<int> adj[maxn];
vector<int> topo;
int in[maxn];
int n, m;
/**
7 7 
1 2
2 3
2 4
3 5
4 5
1 6
7 6
=> 1 7 2 6 3 4 5
*/
void input(){
    cin >> n >> m;
    for (int i = 0; i <m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;// tăng bán bậc vào của đỉnh y
    }
} 
void kaln(){
    queue<int> q;
    // đưa đỉnh có bậc là 0 vào queue
    for (int i = 1; i <= n; i++){
        if(in[i] == 0) q.push(i);
    }
    // chừng nào hàng đợi còn chưa rỗng 
    while (!q.empty())
    {
        // lấy&xóa đỉnh ở đầu hàng đợi (Xóa đỉnh u khỏi đồ thị)
        int u = q.front(); q.pop();
        topo.push_back(u);//đưa đỉnh bị xóa vào topo
        // duyệt các đỉnh kề với đỉnh u và giảm bán bậc vào của các đỉnh đấy 
        for (int v : adj[u]){
            in[v]--;
            // nếu thấy bậc 0 thì lại đẩy vào queue   
            if(in[v] == 0) q.push(v);
        }
    }
    for (int x : topo) cout << x << " " ;
 
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    kaln();
    return 0;
}