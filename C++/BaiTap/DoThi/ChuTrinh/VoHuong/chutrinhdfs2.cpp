//Code này đúng ngay cả khi đồ thị k liên thông 
#include <bits/stdc++.h>
using namespace std;
/**
8 6 
1 2 
2 3
4 5
4 6
5 6
5 7
=> Yes
*/
int n, m;
vector<int> adj[1001];
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
//check xem có là cạnh ngược không 
bool DFS(int u, int parent){
    visited[u] = true;
    for (int v : adj[u]){
        if(!visited[v])
        {
            if(DFS(v, u)) 
                return true;//có chu trình thì KL true
            //không có chu trình thì thôi vì chưa KL luôn được  
            //SAI return DFS(v,u); KL luôn 1 nhánh nhỏ mà không duyệt tiếp các nhánh khác 
        }//MUST HAVE {}
        else //v đã được thăm 
            //v không là cha trực tiếp của đỉnh đang xét 
            if (v != parent) 
                return true;//là cạnh ngược          
    }

    //đã duyệt xong tất cả đỉnh kề 
    return false;//không có chu trình 
}
void run(){
    input();
    for (int i = 0; i <= n; i++){
        if(!visited[i]){
            if(DFS(i,0)){
                cout << "Yes";
                return ;
            }
        }
    }
    //duyệt xong tất cả thành phần liên thông của đồ thị rồi mới KL là no 
    cout << "No";
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}
