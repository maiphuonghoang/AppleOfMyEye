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

/** Độ cao của cây h[v] = h[u] + 1
7
1 2
2 3 
3 4 
1 5 
5 6 
1 7 
=> 0 1 2 3 1 2 1 
*/
int n;
vector<int> adj[100005];
bool used[100005];
int height[100005];

void dfs(int u){
    used[u] = true;
    for (int v : adj[u])
        if(!used[v]){
            height[v] = height[u] + 1;
            dfs(v);      
        }
}
void run(){
    cin >> n;
    f0(i,n-1){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    height[1] = 0;
    dfs(1);
    f1(i, n) cout << height[i] << " ";
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