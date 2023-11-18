#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;
/** Quần đảo chìm 
 * Khi 1 hòn đảo bị nhấn chìm, 1 số hòn đảo khác có thể bị ngắt kết nối 
 * Ban đầu tất cả các hòn đảo trên thành phố đều được kết nối với nhau.
 * Đếm số hòn đảo khi bị nhấn chìm sẽ ngắt kết nối với bộ phận thành phố (đỉnh trụ)
6 8
1 3
6 1
6 3
4 1
6 4
5 2
3 2 
3 5
=> 1
*/
int n, m;
vector<int> adj[100005];
bool used[100005];
int cnt = 0;

void dfs(int u){
    cnt++;
    used[u] = true;
    for (int v : adj[u])
        if(!used[v])
            dfs(v);      
}
void run(){
    cin >> n >> m;
    f0(i,m){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int res = 0;
    f1(i, n){
        memset(used, false, sizeof(used));
        used[i] = true;
        cnt = 0;
        if(i==1) dfs(2);
        else dfs(1);
        if(cnt != n-1) res++;
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}