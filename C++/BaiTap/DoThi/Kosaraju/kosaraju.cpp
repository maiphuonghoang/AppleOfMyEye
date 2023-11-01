// Strongly connected component 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * B1: Gọi DFS trên đồ thị ban đầu và lưu thứ tự thăm xong 1 đỉnh vào 1 stack
 * B2: Xây dựng đồ thị lật ngược của đồ thị ban đầu: Transpose graph
 * B3: Lần lượt pop các đỉnh trong stack ở B1 và gọi DFS cho những đỉnh chưa được thăm 
 * để liệt kê các thành phần liên thông mạng  
2
8 9
1 2
2 3
3 4 
4 1 
3 5
6 6
6 7 
7 8
8 6

6 9
1 2 2 4 3 1 3 2 3 5 4 3 5 4 5 6 6 3
=>
4 5 3 2 1 8 7 6
6 8 7
1 4 3 2
5
No
6 5 3 4 2 1
1 3 4 2 5 6
Yes
*/
const int maxn = 1001;
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
void dfsG(int u){
    visited[u] = true;
    for (int v: adj[u])
        if (!visited[v]) dfsG(v);
    //đã duyệt xong đỉnh u 
    cout << u << " ";
    st.push(u);
}
void dfsTG(int u){
    visited[u] = true;
    cout << u << " ";
    for (int v: r_adj[u]){
        if (!visited[v]) dfsTG(v);
    }

}
void SCC(){
    memset(visited, false, sizeof(visited));
    //B1: Gọi DFS trên đồ thị ban đầu  
    for (int i = 1; i <=n; i++){
        if(!visited[i]) 
            dfsG(i);
    }
    cout << endl;
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    while(!st.empty()){
        int u = st.top(); st.pop();
        if(!visited[u]){
            ++cnt;//đếm xem có bn SCC 
            dfsTG(u);
            cout << endl;
        }
    }
    cnt == 1? cout << "Yes" : cout << "No";
}
void run(){
    int t; cin >> t;
    while(t--){
        input();
        SCC();
        //reset dsk 
        for (int i=1; i<=n; i++){
            adj[i].clear();
            r_adj[i].clear();
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}