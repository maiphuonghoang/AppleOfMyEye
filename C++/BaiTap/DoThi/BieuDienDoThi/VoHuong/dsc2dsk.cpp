// DANH SÁCH CẠNH SANG DANH SÁCH KỀ 
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
1 : 2 3 4 
2 : 1 3 4 5
3 : 1 2 4 5
4 : 1 2 3 5
5 : 2 3 4
*/

vector<int> adj[1001];//danh sách kề 
//adj[i] lưu danh sách kề của đỉnh i 

void run(){
    int n, m; cin >> n >> m;
    //n: số đỉnh; m: số cạnh 
    
    //duyệt m cạnh 
    for (int i = 0; i < m; i++){
        //nhập vào 2 đỉnh x, y
        int x, y; cin >> x >> y;
        //cho x vào dsk của y, cho y vào dsk của x 
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //Liệt kê danh sách kề 
    for (int i = 1; i<=n; i++){
        cout << i << " : " ;
        for (int x : adj[i])
            cout << x << " ";
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