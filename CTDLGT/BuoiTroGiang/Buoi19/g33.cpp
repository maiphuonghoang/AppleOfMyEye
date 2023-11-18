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

/** Tí đang xây dựng 1 mạng xã hội và mời các bạn mình dùng thử.
 * MXH là hoàn hảo nếu: Với mọi bộ 3 x, y, z nếu x kb với y, y kb với z thì x với z cũng kb với nhau 
 * Giữa 2 đỉnh phải có 1 cạnh nối => Cm n đỉnh có 2Cn cạnh 
 * n-1 cạnh <= n đỉnh <= 2Cn cạnh 
 * Đồ thị hoàn hảo <=> mọi tplt hoàn hảo => Đếm số đỉnh và số cạnh của từng tplt 
 * Số cạnh tính từ đỉnh so với m 
4 3
1 3 
3 4 
1 4
=> Yes
4 4
3 1
2 3
3 4
1 2 
=> No
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
    f0(i, m){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int canh_hoan_hao = 0;
    f1(i, n){
        if(!used[i]){
            cnt = 0;
            dfs(i);
            canh_hoan_hao += cnt*(cnt-1)/2;
        }
    }
    canh_hoan_hao == m ? yes : no; 
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