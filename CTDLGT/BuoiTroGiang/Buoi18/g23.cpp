#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f2(j,m) for (int j = 1; j <= m; j++)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/**
 * Đồ thị liên thông mạnh (Từ 1 đỉnh có thể đi đến tất cả các đỉnh còn lại)
 * Brute force O(n^2)
6 14
3 4 
3 1 
2 5 
2 6 
4 6 
2 3
5 6
1 5
1 2
3 5 
4 5
6 3
4 2
1 4
=> Yes
*/
int n, m;
vector<int> adj[1005];
bool used[1005];
int cnt; //đếm xem loang được bao nhiêu đỉnh 

void dfs(int u){
    cnt++;
    used[u] = true;
    for(int v : adj[u])
        if(!used[v])
            dfs(v);       
}
int check(){
    f1(i,n){
        cnt = 0;
        memset(used, 0, sizeof(used));
        dfs(i);
        if(cnt!=n) return 0;
    }
    return 1;
}
void run(){
    cin >> n >> m;
    f0(i, m){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    if(check()) yes; else no;

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