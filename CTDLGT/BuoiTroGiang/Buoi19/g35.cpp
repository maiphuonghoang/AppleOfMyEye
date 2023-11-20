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

/** Đồ thị 2 phía 
5 4 
1 2 
3 2 
4 3 
4 5 
=> Yes
*/
int n, m;
vector<int> adj[100005];
int color[100005];
//1,2 => màu; 0=> false
int ok = 1;

void dfs(int u){
    if(!ok) return;
    for (int v : adj[u])
        if(color[v] == 0){
            color[v] = 3 - color[u];
            dfs(v);    
        }else if(color[v] == color[u])
            ok = 0;

}

void run(){
    cin >> n >> m;
    f0(i, m){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    f1(i, n){
        if(!color[i]){
            color[i] = 1;
            dfs(i);
        }
    }
    ok? yes: no;
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