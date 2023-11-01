#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * There are n cities and m flight connections. Your task is to check if you can travel 
 * from any city to another city using the available flights.
 * There are m lines describing the flights. All flights are one-way flights
4 5
1 2 
2 3
3 1
1 4
3 4
=> 
No
4 2 
Kiểm tra xem đồ thị có liên thông mạnh không và thêm điều kiện: in ra 2 thành phố a và b không thể đi giữa 2 tpho này 

*/
const int maxn = 10001;
int n, m;
vector<int> adj[maxn];//dsk của G
vector<int> r_adj[maxn];//dsk của TG 
bool visited[maxn];
stack<int> st;

void input(){
    cin >> n >> m;
    for (int i = 0; i <m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }
}
/*lưu lại 1 đỉnh của từng thành phần liên thông để có thể lấy 1 trong những đỉnh này in ra */
void dfsG(int u){
    visited[u] = true;
    for (int v: adj[u])
        if (!visited[v]) dfsG(v);
    //đã duyệt xong đỉnh u 
    st.push(u);
}
void dfsTG(int u){
    visited[u] = true;
    for (int v: r_adj[u])
        if (!visited[v]) 
            dfsTG(v);
}
void SCC(){
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <=n; i++){
        if(!visited[i]) 
            dfsG(i);
    }
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    vector<int> point; 
    while(!st.empty()){
        int u = st.top(); st.pop();
        if(!visited[u]){
            point.push_back(u);//lưu đỉnh đại diện cho các tplt 
            ++cnt;//đếm xem có bn SCC 
            dfsTG(u);
        }
    }
    if(cnt == 1) cout << "Yes" << endl;
    else {
        cout << "No" << endl;
        cout << point[1] << " " << point[0] << endl;
    }
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    SCC();
    return 0;
}