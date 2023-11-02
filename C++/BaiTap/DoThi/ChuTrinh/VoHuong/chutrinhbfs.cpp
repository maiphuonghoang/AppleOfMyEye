
#include <bits/stdc++.h>
using namespace std;
/**
8 6 
1 2 
2 3
4 5
4 6
5 6
5 7
=> Yes
BFS không truy vết được giống như DFS vì nó mở rộng theo chiều rộng
*/
int n, m;
vector<int> adj[1001];
bool visited[1001];

int parent[1001];
int top, last;


void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
bool BFS(int u){
    visited[u] = true;
    queue<int> q;//khởi tạo hàng đợi rỗng
    q.push(u);//push đỉnh đầu tiên vào 
    while (!q.empty()){
        //lấy ra đỉnh ở đầu queue
        int v = q.front(); q.pop();
        for (int x : adj[v]){
            if (!visited[x]){//nếu chưa được thăm
                q.push(x);//đẩy vào queue
                visited[x] = true;//đánh dấu đã được thăm;
                parent[x] = v;//cập nhật cha 
            }
            else if(x != parent[x]){
                top = v;
                last = x;
                return true;
            } 
        }
    }
    return false;
    
}

void run(){
    input();
    for (int i = 0; i <= n; i++){
        if(!visited[i]){
            if(BFS(i)){
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
