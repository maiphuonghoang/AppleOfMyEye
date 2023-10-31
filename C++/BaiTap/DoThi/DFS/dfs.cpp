#include <bits/stdc++.h>
using namespace std;
/*
9 9
1 2
1 3 
1 5 
2 4 
3 6 
3 7 
3 9 
5 8 
8 9
=> 1 2 4 3 6 7 9 8 5 
*/
vector<int> adj[1001];//dsk 
bool visited[1001];//kiểm tra 1 đỉnh đã được thăm hay chưa

void input(){
    int n, m; cin >> n >> m;
    for (int i=0; i < m; i++){
        int x, y; cin >> x >> y;
        //chuyển dsc sang dsk 
        adj[x].push_back(y);
        adj[y].push_back(x);//có hướng thì bỏ dòng này đi 
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u){
    cout << u << " ";
    visited[u] = true;//đánh dấu u đã được thăm 
    for (int v : adj[u]){
        if(!visited[v]){//nếu đỉnh v chưa được thăm 
            dfs(v);
        }
    }//duyệt danh sách kề của đỉnh u 
}
//-------------------------------------------------------------
int a[1001][1001];

int n=9;
void inputMtk(){
    /*
0 1 1 0 1 0 0 0 0 
1 0 0 1 0 0 0 0 0 
1 0 0 0 0 1 1 0 1 
0 1 0 0 0 0 0 0 0 
1 0 0 0 0 0 0 1 0 
0 0 1 0 0 0 0 0 0 
0 0 1 0 0 0 0 0 0 
0 0 0 0 1 0 0 0 1
0 0 1 0 0 0 0 1 0
    */
    for (int i = 1; i<=n; i++)
        for (int j = 1; j <=n; j++)
            cin >> a[i][j];
    memset(visited, false, sizeof(visited));
}
void dfsMtk(int u){
    cout << u << " ";
    visited[u] = true;//đánh dấu u đã được thăm 
    // duyệt danh sách kề của đỉnh u 
    for (int v = 1; v<=n; v++){
        if(a[u][v] == 1 && !visited[v]){
            dfsMtk(v);
        }    
    }
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    dfs(1);
    inputMtk();
    dfsMtk(1);
    return 0;
}