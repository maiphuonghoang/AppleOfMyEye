//MA TRẬN KỀ SANG DANH SÁCH CẠNH 
//Đồ thị vô hướng 
#include <bits/stdc++.h>
using namespace std;
/*
5
0 1 1 1 0
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
0 1 1 1 0
=>
1 2 
1 3
1 4 
2 3
2 4
2 5 
3 4 
3 5 
4 5 
*/
int a[1001][1001];//mtk 
vector<pair<int, int>> edge; //danh sách cạnh 

void run(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(a[i][j] && i<j)
                edge.push_back({i, j});  
        }
    }

    //duyệt danh sách cạnh 
    for (auto it : edge)
        cout << it.first << " " << it.second << endl;

    
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}