
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
1 4
2 4
3 4
4 4
5 8
6 8
7 7
8 4
9 9
10 10
*/

int n, m;
vector<int> adj[100005];
bool used[100005];
int parent[100005], bac[100005];

void init(){
    f1(i, n) parent[i] = i;
}
int find(int u){
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u]);
}
void Union(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    else{
        if(bac[x] > bac[y] || bac[x] == bac[y] && x < y)
            parent[y] = x;
        else{
            parent[x] = y;
        } 
    }
}

void run() {
    cin >> n >> m;
    init();
    vector<pair<int, int>> edges;
    f0(i, m){
        int x, y; cin >> x >> y;
        edges.push_back({x, y});
        bac[x]++; bac[y]++;
    } 
    for(auto e : edges)
        Union(e.first, e.second);
    f1(i, n)
        cout << i << " " << parent[i] << endl;
    // nhóm trưởng là nó = parent của nó 
    f1(i, n)
        if(i == parent[i]) cout << i << " ";

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