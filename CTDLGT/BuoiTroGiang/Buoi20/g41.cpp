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

/** Sửa đường 
 * Có n thành phố và m đường giữa chúng. K may, tình trạng của những con đường quá kém 
 * nên chúng k thể được sử dụng. Nhiệm vụ của bạn là sửa chữa 1 số con đường để có 1 con đường tốt
 * giữa 2 thành phố bất kỳ. Đối với mỗi con đường, bạn biết chi phí sửa chữa của nó và bạn nên tìm 
 * giải pháp sao cho tổng chi phí càng nhỏ càng tốt
5 6 
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4 
=> 14
*/
struct edge{
    int st, ed, w;
};
int n, m;
int parent[100005], sz[100005];
bool cmp(edge a, edge b){
    return a.w < b.w;
}

void init(){
    f1(i, n){
        parent[i] = i;
        sz[i] = 1;
    } 
}
int find(int u){
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u]);
}
bool Union(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return false;
    if(sz[x] > sz[y]){
        parent[y] = x;
        sz[x] += sz[y];
    }
    else{
        parent[x] = y;
        sz[y] += sz[x];
    }
    return true;
}
void run(){
    cin >> n >> m;
    vector<edge> canh;
    vector<edge> MST;
    f0(i, m){
        int x, y, z; cin >> x >> y >> z;
        canh.push_back(edge{x, y, z});
    }
    init();
    sort(canh.begin(), canh.end(), cmp);
    ll cost = 0;
    for(edge e : canh){
        if(Union(e.st, e.ed)){
            cost += e.w;
            MST.push_back(e);
        }
    }
    if(MST.size() == n-1) cout << cost << endl;
    else cout << "IMPOSSIBLE";
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