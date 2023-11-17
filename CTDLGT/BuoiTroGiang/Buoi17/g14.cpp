#include <bits/stdc++.h>
using namespace std;

/**
 * Giữa s và t có tồn tại đường đi k 
 * => 2 đỉnh có đường đi với nhau thuộc cùng thành phần liên thông 
 * Tìm cách lưu lại tplt giữa 2 đỉnh để k dfs nhiều lần 
5 3
5 4
4 1
4 3
3 
4 5 
4 2
3 4
=>
Yes
No
Yes
*/

int n, m, s, t;
vector<int> adj[1005];
bool used[1005];
int tplt[1005];
int cnt = 0;

void dfs(int u){
    used[u] = true;
    tplt[u] = cnt;
    for(int v : adj[u])
        if(!used[v])
            dfs(v);       
}
void run(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <=n; i++)
        sort(adj[i].begin(), adj[i].end());
    for (int i=1; i<=n; i++){
        if(!used[i]){
            cnt++;     
            dfs(i);
        }
    }
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        if(tplt[x] == tplt[y]) cout << "Yes"<<endl;
        else cout << "No" << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}