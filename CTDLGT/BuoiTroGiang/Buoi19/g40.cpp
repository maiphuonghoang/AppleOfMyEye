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

/** Tìm cặp
 * Bạn được cung cấp 1 cây gốc với các nút và 1 là nút gốc. Có 1 đường đi duy nhất
 * giữa 2 nút bất kì. Gọi d(i, j) là số cạnh trong 1 đường đi ngắn nhất giữa 2 nút i, j.
 * Tìm số lượng cặp i,j sao cho d(i,j) = d(1,i) - d(1,j)  
    Thẳng tuột thì đúng 
            1
         /     \ 
        2       3
     /    \     |
    4     5     6
          |
          7
    d[7,2] = d[1,7] - d[1,2]
    Đếm số lượng đỉnh thẳng tuột với nhau = tổng số lượng con cháu của đỉnh
10
9 10 5 9 7 4 4 5 2 3 6 7 7 8 3 6 1 2 
*/
int n, m, st;
vector<int> adj[100005];
bool used[100005];
int res = 0;

int dfs(int u){
    int cnt = 1;
    used[u] = true;
    for (int v : adj[u])
        if(!used[v]){
            cnt += dfs(v);      
        }
    res += cnt;
    return cnt;
}
//----------------------------------------------------------------
int sz[10005];

int dfs2(int u){
    sz[u] = 1;
    used[u] = true;
    for (int v : adj[u])
        if(!used[v]){
            sz[u] += dfs(v);      
        }
    res += sz[u];
    return sz[u];
}
void run(){
    cin >> n;
    f0(i, n-1){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    // dfs2(1);
    cout << res;
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