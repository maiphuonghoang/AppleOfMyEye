#include <bits/stdc++.h>
using namespace std;
/*
10 11
1 2
1 3 
1 5 
1 10 
2 4
3 6 
3 7 
3 9 
6 7 
5 8
8 9
=> 
1 2 3 5 10 4 6 7 9 8
*/
vector<int> adj[1001];
bool visited[1001];

void input(){
    int n, m; cin >> n >> m; //số đỉnh và số cạnh
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void bfs(int u){ 
    //Bước khởi tạo queue rỗng
    queue<int> q;
    q.push(u);//push đỉnh đầu tiên vào  
    visited[u] = true;//đánh dấu đỉnh u đã được thăm 

    //Bước lặp
    while (!q.empty())
    {
        int v = q.front();//lấy đỉnh ở đầu queue 
        q.pop();// xóa nó đi 
        cout << v << " ";//Thăm v
        // duyệt các đỉnh kề với v mà chưa được thăm và đẩy vào queue, đánh dấu 
        for (int x : adj[v]){//danh sách kề của v 
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }

    }
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    bfs(3);
    return 0;
}