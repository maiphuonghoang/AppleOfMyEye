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

/** Cây khung dfs 
7 12 3
6 3 6 2 5 3 5 4 7 3 5 2 7 1 4 3 2 1 6 4 7 2 3 2
=> 
3->2
2->1
1->7
2->5
5->4
4->6
Cây khung bfs
9 18 4
9 3 5 4 5 1 5 2 7 5 4 3 8 5 4 2 2 1 9 1 7 2 8 6 9 7 4 1 6 1 9 1 6 3 7 1 
=>
4->1
4->2
4->3
4->5
1->6
1->7
1->9
5->8
*/
int n, m, st;
vector<int> adj[100005];
bool used[100005];

void dfs(int u){
    used[u] = true;
    for (int v : adj[u])
        if(!used[v]){
            cout << u << "->" << v << endl;
            dfs(v);      
        }
}
void bfs(int st){
    queue<int> q;
    q.push(st);
    used[st] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if(!used[v]){
                cout << u << "->" << v << endl;
                used[v] = true;
                q.push(v);
            }
    }
}
void run(){
    cin >> n >> m >> st;
    f0(i, m){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    f1(i, n) sort(adj[i].begin(), adj[i].end());
    // dfs(st);
    bfs(st);
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