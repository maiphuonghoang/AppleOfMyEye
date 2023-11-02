#include <bits/stdc++.h>
using namespace std;
/**
6 6
Aooxoo
oxoooo
oxoooo
ooooxx
Boooxo
oooxxx
=> Yes 
DFS
1 1
1 2
1 3
2 3
2 4
2 5
1 5
1 6
2 6
3 6
3 5
3 4
3 3
4 3
4 2
4 1
3 1
2 1
5 1
BFS
1 1
1 2
2 1
1 3
3 1
2 3
4 1
2 4
3 3
4 2
5 1

*/
int n, m;
int s,t;//lưu tọa độ đỉnh bắt đầu A
char a[1001][1001];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

bool dfs(int i, int j){
    cout << i << " " << j << endl;
    if(a[i][j] == 'B'){
        return true;
    }
    a[i][j] = 'x';
    // duyệt các đỉnh kề
    for (int k=0; k< 4; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        //nằm trên lưới và có đường đi 
        if(i1>=1 && i1<=n && j1>=1 &&j1<=m && a[i1][j1] != 'x'){
            //KL có đường đi 
            if(dfs(i1, j1)) return true;
        }
    }
    return false;
}
bool bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    cout << i << " " << j << endl;
    a[i][j] = 'x';
    while(!q.empty()){
        pair<int, int> top = q.front(); q.pop();
        //duyệt các đỉnh kề 
        for (int k = 0; k < 4; k++){
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1] != 'x'){
                cout << i1 << " " << j1 << endl;
                if(a[i1][j1] == 'B')
                    return true;
                q.push({i1, j1});
                a[i1][j1] = 'x';
            }
        }
    }
    return false;
}    

void input(){
    cin >> n >> m;
    for (int i = 1; i <=n; i++)
        for (int j = 1; j <=n; j++){
            cin >> a[i][j];
            if(a[i][j] == 'A'){
                s = i; t = j;
            }
        }
    // if(dfs(s, t)) 
    if(bfs(s, t))
        cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    return 0;
}