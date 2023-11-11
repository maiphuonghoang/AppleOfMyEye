// Nếu từ đỉnh u mà mở rộng ra được đỉnh v đã được thăm rồi 
// mà v không phải cha trực tiếp u thì (v->u) là cạnh ngược 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
5 4
1 2
2 3
2 4
5 1
=> No  
*/
vector<int> ke[1001];
bool visited[1001];
int color[1001];
int n, m;

void input(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
}

bool dfs(int u){
    color[u] = 1;//xám 
    for (int v : ke[u]){
        if(color[v] == 0){
            if(dfs(v))
                return true;
        }
        else if(color[v] == 1)
            return true;
    }
    color[u] = 2;
    return false;
}

void run(){
    input();
    cout << dfs(1);
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}