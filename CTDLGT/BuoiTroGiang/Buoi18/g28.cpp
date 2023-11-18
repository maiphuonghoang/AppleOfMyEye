
#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/**
 * In ra thứ tự các đỉnh đại diện (đỉnh kề với nhiều đỉnh nhất trong 1 tplt)
 * có số thứ tự nhỏ nhất (2 đỉnh cùng có số lượng kề = nhau thì lấy đỉnh có STT nhỏ hơn) 
 * trong đồ thị => Bậc 
 5    3  1
 |     \ |
 8___2___4      
 |
 6      7  9  10

10 6
4 3
4 1
8 5
8 6
4 2
8 2
=> 4 7 9 10
*/

int n, m;
vector<int> adj[100005];
bool used[100005];
int bac[100005];
int nhomTruong;
void dfs(int u){
    if (bac[u] > bac[nhomTruong] || bac[u] == bac[nhomTruong] && u < nhomTruong)
        nhomTruong = u;
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
        bac[x]++; bac[y]++;
    } 
    vector<int> v;
    f1(i, n){
        if(!used[i]){
            nhomTruong = i;
            dfs(i);
            v.push_back(nhomTruong);
        }
    }
    sort(v.begin(), v.end());
    for (int x: v) cout << x << " ";
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