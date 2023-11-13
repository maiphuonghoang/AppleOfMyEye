#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
/*
Chọn cạnh ngắn nhất, 1 đỉnh thuộc V, 1 đỉnh thuộc MST
(đảm bảo việc chọn cạnh đấy k tạo thành chu trình)
 => hàng đợi ưu tiên lưu pair, first lưu trọng số và second lưu đỉnh 
O((V+E)*logV)
*/
/*
5 6 
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
=> 14 
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
        adj[y].push_back({x,w});
    }
}
void prim(int s){
    taken[s] = true; //đưa đỉnh đầu vào MST  
    priority_queue<ii, vector<ii>, greater<ii>> Q;//min heap 
    // đỉnh nối được với s chưa thuộc MST thì đưa vào hàng đợi ưu tiên
    for (auto it : adj[s]){
        int t = it.first;
        if(!taken[t])
            Q.push({it.second, t});
    }
    int d = 0, dem = 0;
    while(!Q.empty()){
        // Lấy ra cạnh ngắn nhất ở đỉnh hàng đợi 
        pair<int, int> top = Q.top(); Q.pop();
        int u = top.second, w = top.first;
        if(!taken[u]){//vì có thể còn những cạnh đã thuộc MST trong queue từ lần trước đó 
            dem++;
            d += w;
            taken[u] = true;
            for (auto it : adj[u]){
                if(!taken[it.first])
                    Q.push({it.second, it.first});
            }
        }
    }  
    if(dem == n-1)
        cout << d << endl;
    else cout << "Impossible";
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    input();
    prim(1);
    return 0;
}