#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
9 8
1 2
1 6 
2 3
2 4
3 5
6 7
7 8
7 9
=> 1 2 3 5 4 6 7 8 9 
*/

vector<int> ke[1001]; //dsk 
bool visited[1001];
int a[1001][1001];//mtk
vector<pair<int, int>> dscanh;
int n, m;

// O(V+E)
void dfsDsk(int u){
    cout << u << " ";
    visited[u] = true;
    for (int v : ke[u])
        if(!visited[v]) 
            dfsDsk(v);
}

// O(V*V)
void dfsMtk(int u){
    cout << u << " ";
    visited[u] = true;
    // duyệt dsk của đỉnh u : duyệt cái dòng thứ u trong ma trận kề a 
    for (int i = 1; i <= n; i++){
        if(a[u][i] == 1){
            if(!visited[i])
                dfsMtk(i);
        }
    }
}

// O(V*E)
void dfsDsc(int u){
    cout << u << " ";
    visited[u] = true;
    // duyệt dsk của đỉnh u : duyệt tất cả cạnh trong dsc
    // so khớp cạnh nào chứa đỉnh u 
    // xét đỉnh đầu/ đỉnh cuối nếu là u thì gọi dfs tới đỉnh còn lại đó
    for (auto it : dscanh){
        if(it.first == u){
            if(!visited[it.second])
                dfsDsc(it.second);
        }
        if(it.second == u){
            if(!visited[it.first])
                dfsDsc(it.first);
        }
    }
}
void run(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));

    // đếm số thành phần liên thông : số lần gọi dfs 
    int dem = 0;
    for (int i = 1; i<=n; i++){
        if(!visited[i]){
            dem++;
            dfsDsk(i);
        }
    }
    cout << dem << endl;
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}