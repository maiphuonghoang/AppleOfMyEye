#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
12 11
1 2
1 3 
1 4
2 5
2 7
3 6
4 8
5 9
7 10
8 11
11 12
=> 1 2 3 4 5 7 6 8 9 10 11 12 
*/

vector<int> ke[1001]; //dsk 
bool visited[1001];
int n, m;

void input(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x  = q.front(); q.pop();
        cout << x << " ";
        for (int y : ke[x]){
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

void run(){
    input();
    bfs(1);
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}