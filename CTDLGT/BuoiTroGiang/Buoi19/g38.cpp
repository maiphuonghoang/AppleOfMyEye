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
/** Mèo Tom đang ở 1 gốc cây với nhiều lá và cành. Ở các node lá có treo các con cá.
 * Các node trung gian có những con gián và mèo Tom chỉ có thể đi đến các node lá nếu 
 * trên đường đi từ gốc tới node lá không có quá m con gián liên tiếp.
 * Đếm số các tối đa mà mèo có thể ăn được 
            1*            m=1
          /   \
        2        3*
      /  \      /  \
    4*    5     6   7 
Xét ở mỗi đỉnh đang xét có bn con gián liên tiếp

7 1
1 0 1 1 0 0 0 
1 2 
1 3 
2 4 
2 5 
3 6 
3 7 
=> 2
*/
int n, m;
vector<int> adj[100005];
bool used[100005];
int d[100005];//số gián liên tiếp ở mỗi đỉnh 
int res = 0;

void dfs(int u, int lt){
    int ok = 0;//node lá 
    used[u] = true;
    for (int v : adj[u]){
        if(!used[v]){
            ok = 1;
            if(d[v] == 1 && lt+1 <= m)
                dfs(v, lt+1);     
            else if(d[v] == 0)
                dfs(v, 0); 
        }
    }
    if(!ok)//node lá có cá 
        res++;
    
}
void run(){
    cin >> n >> m;
    f1(i, n) cin >> d[i];
    f0(i,n-1){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, d[1]);
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