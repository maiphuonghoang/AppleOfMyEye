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

set<int> ke[1001];
bool visited[1001];
int n, m;
vector<pair<int, int>> dscanh;

void input(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        dscanh.push_back({x, y});
        ke[x].insert(y);
        ke[y].insert(x);
    }
}

void dfs(int u){
    visited[u] = true;
    for (int v : ke[u])
        if(!visited[v]) {
            dfs(v);
        }
}
int tplt(){
    int count = 0;
    for (int i = 1; i <=n; i++){
        if(!visited[i]){
            count++;
            dfs(i);
        }
    }
    return count;
}

// O(E*(E+V))
void canh_cau(){
    int cc = tplt();//số thành phần liên thông ban đầu 
    int dem = 0;
    for (auto it : dscanh)
    // duyệt qua từng cạnh 
    {
        // loại bỏ cạnh (x, y) ra khỏi đồ thị 
        int x = it.first, y = it.second;
        ke[x].erase(y);
        ke[y].erase(x);
        memset(visited, false, sizeof(visited));
        if(cc < tplt())
            dem++;
        // khôi phục lại 
        ke[x].insert(y);
        ke[y].insert(x);
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