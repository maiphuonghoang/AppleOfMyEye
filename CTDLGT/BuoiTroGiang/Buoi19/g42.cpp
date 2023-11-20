
#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** n thành phố và ban đầu k có đường giữa chúng. Tuy nhiên mỗi ngày 1 con đường được 
 * xây mới và có tổng cộng m con đường. Sau mỗi ngày tìm số lượng cụm thành phố và 
 * kích thước cụm thành phố lớn nhất 
5 3 
1 2
1 3 
4 5 
=> 
4 2
3 3
2 3
*/

int n, m;
bool used[100005];
int parent[100005], sz[100005];
int size_max = 1;

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
        sz[x] += sz[y];
        parent[y] = x;
    }
    else{
        sz[y] += sz[x];
        parent[x] = y;
    }
    size_max = max({size_max, sz[x], sz[y]});
    return true;
}

void run() {
    cin >> n >> m;
    init();
    int cnt = n;
    f0(i, m){
        int x, y; cin >> x >> y;
        if(Union(x, y)) cnt--;
        cout << cnt << " " << size_max << endl;
    }
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