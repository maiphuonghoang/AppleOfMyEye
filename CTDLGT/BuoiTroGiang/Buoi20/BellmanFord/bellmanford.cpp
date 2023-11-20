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

/** Bellman Ford 
*/
int n, m, s;
vector<pair<int, int>> adj[1005];
int d[1005];

void BellmanFord(int s){
    for(int i = 1; i<=n; i++)
        d[i] = 1e9;
    d[s] = 0;
    for(int i = 0; i<n-1; i++){//n-1 bước 
        //mỗi bước duyệt qua từng đỉnh
        for(int u = 1; u<=n; u++){
            // duyệt qua từng đỉnh kề của đỉnh đó - dsk 
            for (auto it : adj[u]){
                int v = it.second, len = it.first;
                d[v] = min(d[v], d[u] + len);
            }
        }
    }
    f1(i, n) cout << d[i] << " ";

}
void run(){
    cin >> n >> m >> s;
    f0(i, m){
        int x, y, z; cin >> x >> y >> z;
        adj[x].push_back({z, y});
        adj[y].push_back({z, x});
    }
    BellmanFord(s);
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