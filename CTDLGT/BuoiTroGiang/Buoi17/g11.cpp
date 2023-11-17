#include <bits/stdc++.h>
using namespace std;
/* dsc sang dsk
5 10
4 2
4 1
2 5
3 4
1 5
2 3 
5 1
2 1
1 4
4 5
=> 
*/
int n, m;
vector<int> adj[1005];
void run(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i=1; i<=n; i++){
        cout << i << " : ";
        sort(adj[i].begin(), adj[i].end());
        for (int x : adj[i])
            cout << x << " ";
        cout << endl;
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}