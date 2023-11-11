#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
10 6
10 1
5 2
10 5
10 6
5 3
10 4
=> 6
*/

vector<int> ke[1001];
bool visited[1001];
int n, m, s, t;
vector<pair<int, int>> dscanh;

void input(){
    cin >> n >> m >>s >> t;
    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        dscanh.push_back({x, y});
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void dfs(int u, int s, int t ){
    visited[u] = true;
    for (int v : ke[u]){
        // có thể cặp (u,v) đang chuẩn bị xét là cặp (s, t) => k gọi dfs
        // nếu xét phải cạnh muốn xóa thì k xét 
        if((u == s && v == t) || (u == t && v == s))
            continue;
        if(!visited[v]) 
            dfs(v, s, t);
    }
}
int tplt(int s, int t){
    int count = 0;
    for (int i = 1; i <=n; i++){
        if(!visited[i]){
            count++;
            dfs(i, s, t);
        }
    }
    return count;
}

// O(E*(E+V))
// E lần gọi thuật toán dfs 
void canh_cau(){
    int cc = tplt(0, 0);//để k xóa cạnh nào 
    int dem = 0;
    for (auto it : dscanh)
    // duyệt qua từng cạnh 
    {
        int x = it.first, y = it.second;
        memset(visited, false, sizeof(visited));
        if(cc < tplt(x, y))
            dem++;
    }
    cout << dem << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    input();
    canh_cau();
    return 0;
}