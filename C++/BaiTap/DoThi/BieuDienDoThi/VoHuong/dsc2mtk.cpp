// DANH SÁCH CẠNH SANG MA TRẬN KỀ 
#include <bits/stdc++.h>
using namespace std;
/*
5 9

1 2 
1 3
1 4 
2 3
2 4
2 5 
3 4 
3 5 
4 5 
=>
0 1 1 1 0
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
0 1 1 1 0
*/

int a[1001][1001];//ma trận kề 

void run(){
    int n, m; cin >> n >> m;
    //n: số đỉnh; m: số cạnh 
    
    //duyệt m cạnh 
    for (int i = 0; i < m; i++){
        //nhập vào 2 đỉnh x, y
        int x, y; cin >> x >> y;
        //có cạnh nối giữa đỉnh x và y 
        a[x][y] = a[y][x] = 1;
    }

    //Liệt kê ma trận kề 
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}