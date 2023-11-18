#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/**
 * Thứ tự sắp xếp Topo
 * Topo: cha đứng trước con 
 * Dfs: tất cả con xong => cha xong 
 *      theo thứ tự đứng duyệt xong 
 * Bfs: xóa dần đỉnh (k có bán bậc vào)
 *      k có tiên quyết là bắt đầu luôn, 
 *      xóa đỉnh đó và các cạnh và duyệt qua đỉnh kề để giảm bán bậc vào 
6 5
1 2 
2 3
1 4
4 5 
2 6
=> Dfs 1 4 5 2 6 3 
   Bfs 1 2 4 3 6 5 
*/

int n, m;
vector<int> adj[100005];
bool used[100005];
stack<int> st;

void dfs(int u){
    used[u] = true;
    for (int v : adj[u])
        if(!used[v]){
            dfs(v);
        }
    st.push(u);
}
void runDfs() {
    cin >> n >> m;
    f0(i, m){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    } 
    vector<int> v;
    f1(i, n){
        if(!used[i]){
            dfs(i);
        }
    }
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    
}
//----------------------------------------------------------------
/*
5 5
1 3
2 3
3 4
4 5
5 2
=> Co chu trinh
*/
int bbv[100005];
void Kahn(){
    queue<int> q;
    f1(i, n){
        if(bbv[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while (!q.empty())  {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v : adj[u]){
            bbv[v]--;
            if(bbv[v] == 0)
                q.push(v);
        }
    }
    if(topo.size() != n)//toàn những đỉnh có bbv=1
        cout << "Co chu trinh";
    else{
        for (int x : topo)
            cout << x << " ";
    }
}
void runBfs(){
    cin >> n >> m;
    f0(i, m){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        bbv[y]++;
    } 
    Kahn();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    runDfs();
    return 0;
}