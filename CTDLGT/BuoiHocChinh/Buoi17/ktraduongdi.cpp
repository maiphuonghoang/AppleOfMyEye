#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
5 3
5 4 
4 1 
4 3 
3 
4 5
4 2 
3 4 
=>
1 -1 1
*/

vector<int> ke[1001]; //dsk 
bool visited[1001];
int n, m;

int tplt[1001];//duongdi2()
int dem = 0;//duongdi2()

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
        tplt[x] = dem;
        for (int y : ke[x]){
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

void duongdi1(){
    // Check từ x đến y có đường đi k thì gọi bsf(x) rồi check y đã được visted chưa 
    input();
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        memset(visited, false, sizeof(visited));
        bfs(x);
        if(visited[y]) cout << "1\n";
        else cout << "-1\n"; 
    }

    // Nhược: mỗi lần truy vấn phải gọi lại bfs 
}

void duongdi2(){
    // xác định điểm thuộc thành phần liên thông thứ mấy
    // những đỉnh thuộc cùng thành phần liên thông thì sẽ có đường đi 
    // mỗi lần truy vấn chỉ cần xem thành phần liên thông tương ứng của 2 đỉnh đó có giống nhau k O(1)
    input();
    for (int i = 1; i <=n; i++){
        if(!visited[i]){
            dem++;
            bfs(i);
            // loang đến đâu thì đánh dấu stt tplt cho đỉnh đó 
        }
    }
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        // check 2 đỉnh có thuộc cùng tplt k 
        if(tplt[x] == tplt[y]) cout << "1\n";
        else cout << "-1\n";
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    duongdi2();
    return 0;
}