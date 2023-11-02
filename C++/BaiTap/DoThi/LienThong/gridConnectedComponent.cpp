//Liên thông với DFS,BFS input là mảng 
#include <bits/stdc++.h>
using namespace std;
/*
6 6
xxxooo
ooxooo
oxxxxo
ooooox
xxoxox
xoxxox
=> 4
*/
int n, m;
char a[1001][1001];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void dfs(int i, int j){//chỉ số hàng, chỉ số cột của ô đang xét 
    cout << i << " " << j << endl;
    //đánh dấu visited bằng cách chuyển x thành o
    a[i][j] = 'o';
    //duyệt các đỉnh kề (4 ô xung quanh)
    for (int k = 0; k < 4; k++){
        // i1,j1 là 1 trong 4 ô xung quanh của i,j
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        //check i1,j1 vẫn phải nằm trên lưới và có đường đi(chưa được thăm)
        if(i1>=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1] == 'x')
            dfs(i1,j1);
    }
}
void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    cout << i << " " << j << endl;
    a[i][j] = 'o';
    while(!q.empty()){
        pair<int, int> top = q.front(); q.pop();
        for (int k = 0; k < 4; k++){
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1] == 'x'){
                cout << i << " " << j << endl;
                q.push({i1, j1});
                a[i1][j1] = 'o';
            }
        }
    }

}
void input(){
    cin >> n >> m;
    for (int i = 1; i <=n; i++)
        for (int j = 1; j <=n; j++)
            cin >> a[i][j];
}
void gridConnectedComponent(){
    int cnt = 0;
    for (int i = 1; i <=n; i++)
        for (int j = 1; j <=n; j++){
            if(a[i][j] == 'x'){
                cout << "Thanh phan lien thong thu " << cnt + 1 << " : " << endl;
                // dfs(i,j); 
                bfs(i, j);
                ++cnt;
            }
        }
    cout << cnt << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    gridConnectedComponent();
    return 0;
}