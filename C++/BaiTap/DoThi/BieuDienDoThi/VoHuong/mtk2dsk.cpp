//MA TRẬN KỀ SANG DANH SÁCH KỀ  
//Đồ thị có hướng 
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
1 : 2 3 4 
2 : 1 3 4 5
3 : 1 2 4 5
4 : 1 2 3 5
5 : 2 3 4
*/

int a[1001][1001];
vector<int> adj[1001];

void run(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            if(a[i][j])
                adj[i].push_back(j); 
                // adj[i].push_back(j); không cần vì lát sẽ duyệt đến a[j][i]
    }

    for (int i = 1; i <= n; i++){
        cout << i << " : ";
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