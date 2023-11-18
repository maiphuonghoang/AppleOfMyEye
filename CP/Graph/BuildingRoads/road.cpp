#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
using ll = long long;
#define maxn 1e6
using namespace std;
int mod = 1e9 + 7;
/**
 * https://cses.fi/problemset/task/1666
 * Xây dựng số lượng cạnh ít nhất sao cho 3 tplt thành 1 tplt 
 * Lấy đỉnh đại diện cho tplt (dfs thì là đại diện)
*/
int n, m;
vector<int> adj[100005];
bool used[100005];
int tplt[100005];

void dfs(int u){
    used[u] = true;
    for (int v : adj[u])
        if(!used[v]){
            dfs(v);
        }
}
void run() {
    cin >> n >> m;
    f0(i, m){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    } 
    int cnt = 0;
    vector<int> v;
    f1(i, n){
        if(!used[i]){
            v.push_back(i);
            cnt++;
            tplt[cnt] = i;
            dfs(i);
        }
    }
    cout << cnt - 1 << endl;
    //In 1
    for (int i=1; i<cnt; i++){
        cout << tplt[i] << " " << tplt[i+1] << endl;
    }
    //In 2
    for(int i=1; i<v.size(); i++)
        cout << v[i-1] << " " << v[i] << endl;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CP\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}
