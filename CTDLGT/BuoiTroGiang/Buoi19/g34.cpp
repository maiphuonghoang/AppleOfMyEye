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

/** Có k người đứng tại vị trí nào đó trong n địa điểm cho trước.
 * Các địa điểm được nối với nhau bởi m đoạn đường 1 chiều 
 * Mọi người muốn cùng tụ họp tại 1 điểm nào đó. Tuy nhiên với 
 * các đường đi cho trước, chỉ có 1 số địa điểm nào đó có thể 
 * được chọn là điểm họp mặt. Cho trước k,n,m và vị trí ban đầu 
 * của k người cùng với m đường đi 1 chiều, xác định xem có bn điểm 
 * có thể xem là điểm họp mặt   
Địa điểm được chọn là địa điểm ông nào cũng đi đến được 
        1--------->2  người 
        |          |
        |          |
        V          V
        4<---------3  người 
dfs từ những vị trí có người đứng 
dfs(2) 2 3 4
dfs(3) 3 4
3, 4 xuất hiện 2 lần nghĩa là cả 2 người đều đến được 

2 4 4
2
3
1 2
1 4
2 3
3 4
=> 2 
1 0
2 1
3 2
4 2
*/
int n, m, k;
vector<int> adj[100005];
bool used[100005];
int dem[100005];

void dfs(int u){
    dem[u]++;//đỉnh tổng cộng được đi qua bn lần 
    used[u] = true;
    for (int v : adj[u])
        if(!used[v])
            dfs(v);      
}
void run(){
    cin >> k >> n >> m;
    int nguoi[k];
    for (int &x : nguoi) cin >> x;
    f0(i,m){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int x : nguoi){
        memset(used, false, sizeof(used));
        dfs(x);
    }
    f1(i, n) cout << i << " " << dem[i] << endl;
    int res = 0;
    f1(i, n) if(dem[i] == k) res++;
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