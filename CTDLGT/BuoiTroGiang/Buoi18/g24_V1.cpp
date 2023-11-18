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
 * Kiểm tra cây trên đồ thị vô hướng 
 * 1 đồ thị n đỉnh là 1 cây, nếu như nó có đúng n-1 cạnh và
 * giữa 2 đỉnh bất kì chỉ tồn tịa duy nhất 1 đường đi 
 * Cây là đồ thị không có chu trình, liên thông  
 * 2 CÁCH CHỨNG MINH 
 * 1. N-1 CẠNH + LIÊN THÔNG (đếm xem đi qua bn đỉnh)
 * 2. N-1 CẠNH + K CÓ CHU TRÌNH 
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
    dfs(1);
    if(cnt == n) return 1;
    return 0;
}
void run(){//C1
    cin >> n >> m;
    f0(i, m){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    (m == n - 1 && check())? yes : no;
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