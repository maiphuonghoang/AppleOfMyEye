//Code này chỉ đúng khi đồ thị liên thông 
#include <bits/stdc++.h>
using namespace std;
/**
7 6 
1 2
2 3
2 4
3 6
6 7 
7 3
=> Yes
7 5 
1 2
2 3
2 4
3 6
6 7 
=> No
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
  
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    DFS(1,0)? (cout << "Yes") : (cout << "No");
    return 0;
}
