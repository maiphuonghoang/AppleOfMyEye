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
=>Khoang cach duong di ngan nhat 4
6 6
Aooxoo
oxoooo
oxoooo
xxooxx
Bxooxo
oxoxxx
=> Khong co duong di
*/
int n, m;
int iA,jA;//lưu tọa độ đỉnh bắt đầu A
int iB,jB;//lưu tọa độ đỉnh kết thúc B 

char a[1001][1001];
int d[1001][1001];//d[i][j]: lưu số bước đi từ ô bắt đầu tới ô ij

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    a[i][j] = 'x';
    d[i][j] = 0;
    while(!q.empty()){
        pair<int, int> top = q.front(); q.pop();
        //duyệt các đỉnh kề 
        for (int k = 0; k < 4; k++){
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if(i1>=1 && i1<=n && j1>=1 && j1<=m 
               && a[i1][j1] != 'x'
            ){
                d[i1][j1] = d[top.first][top.second] + 1;
                if(a[i1][j1] == 'B')
                    return;
                q.push({i1, j1});
                a[i1][j1] = 'x';
            }
        }
    }
}    

void run(){
    cin >> n >> m;
    for (int i = 1; i <=n; i++)
        for (int j = 1; j <=n; j++){
            cin >> a[i][j];
            if(a[i][j] == 'A'){
                iA = i; jA = j;
            }
            else if(a[i][j] == 'B'){
                iB = i, jB = j;
            }
    }
    bfs(iA, jA);
    if(!d[iB][jB])
        cout << "Khong co duong di" << endl;
    else 
        cout << "Khoang cach duong di ngan nhat = " << d[iB][jB] << endl;
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}