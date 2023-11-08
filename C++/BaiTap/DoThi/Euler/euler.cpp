#include <bits/stdc++.h>
using namespace std;

/**
5 6
1 2
2 3
3 1
2 4
4 5
2 5 
=> 1 2 4 5 2 3 1
*/
int n, m;
const int maxn = 1001;
set<int> adj[maxn];
int degree[1001];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x]++; degree[y]++;
    }
}
void euler(int v){
    stack<int> st;
    vector<int> EC;
    st.push(v);
    while(!st.empty()){
        // Lấy đỉnh ở đầu stack 
        int x = st.top();
        if(adj[x].size() != 0){
            // Chọn đỉnh đầu tiên trong danh sách kề của đỉnh x 
            int y = *adj[x].begin();// phần tử đầu tiên trong set
            st.push(y); //đẩy vào stack
            adj[x].erase(y); // xóa cạnh (x, y)
            adj[y].erase(x);
        }
        else{//dsk đã rỗng
            st.pop(); // xóa đỉnh đó khỏi stack 
            EC.push_back(x); // đẩy vào Euler Cycle
        }
    }
    reverse(begin(EC), end(EC));
    for (int x : EC) cout << x << " ";
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    input();
    euler(1);
    return 0;
} 