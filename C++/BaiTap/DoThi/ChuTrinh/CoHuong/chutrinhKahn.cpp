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
3 7  
=> No
7 7
1 2
1 5
2 3
4 2
3 6
6 7
7 3 
=> Yes
*/
int n, m;
vector<int> adj[1001];
int degree[1001];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        degree[y]++;//bán bậc vào của đỉnh 
    }
}
bool Kahn(){
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if(degree[i] ==0) q.push(i);
    }
    int cnt = 0;
    while (!q.empty()){
        //duyệt qua đỉnh kề 
        int v = q.front(); q.pop();
        cnt++;
        for (int x : adj[v]){
            degree[x]--;
            if(degree[x] == 0)
                q.push(x);
        }
    }
    cout << cnt << endl;
    if(cnt == n) return false;//k có chu trình 
    return true;
}
void run(){
    input();   
    if(Kahn()) cout << "Yes";
    else cout << "No";
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}
