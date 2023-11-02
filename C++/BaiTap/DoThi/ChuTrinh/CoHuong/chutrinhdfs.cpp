
#include <bits/stdc++.h>
using namespace std;
/**
7 7
1 2
1 5
2 3
4 2
3 6
6 7
7 3
=> Yes
7 7
1 2
1 5
2 3
4 2
3 6
6 7
3 7 
=> No
*/
int n, m;
vector<int> adj[1001];
int color[1001];
int parent[1001];
int top, last;

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(color, 0, sizeof(color));
}
bool DFS(int u){
    color[u] = 1;//màu xám 
    for (int v: adj[u]) {
        if(color[v] == 0){//màu trắng
            if(DFS(v)) return true;
        }
        else if(color[v] == 1) return true;
    }
    color[u] = 2;//màu đen 
    return false;
}
void run(){
    input();
    for (int i = 0; i <= n; i++){
        if(color[i] == 0){
            if(DFS(i)){
                cout << "Yes" << endl;
                return ;
            }
        }
    }
    //duyệt xong tất cả thành phần liên thông của đồ thị rồi mới KL là no 
    cout << "No"<< endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}
