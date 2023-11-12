#include <bits/stdc++.h>
using namespace std;

// Đếm số lượng thành phần liên thông mạnh 
/*
9 9 
1 2 
2 4
4 3 
3 1
4 6
6 7
7 8 
8 9
9 7
=> scc = 4
5 
1 3 4 2 
6 
7 9 8 
*/
/*
8 11
1 2
2 3
3 4
4 1
3 5 
5 2
5 6
6 7
7 8
8 5
8 6
=> scc = 1
1 4 3 2 5 8 7 6 
*/

const int maxn = 1001;
int n, m;
vector<int> ke[maxn], t_ke[maxn];
bool visited[maxn];
stack<int> st;

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        t_ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void dfs1(int u){
    visited[u] = true;
    for (int v : ke[u]){
        if(!visited[v])
            dfs1(v);
    }
    st.push(u);//lấy thứ tự sắp xếp topo 
}
void dfs2(int u){
    cout << u << " ";
    visited[u] = true;
    for (int v : t_ke[u]){
        if(!visited[v])
            dfs2(v);
    }
}
void kosaraju(){
    for (int i=1; i<n; i++){
        if(!visited[i])
            dfs1(i);
    }
    memset(visited, false, sizeof(visited));
    int scc = 0;
    while (!st.empty())
    {
        int top = st.top(); st.pop();
        if(!visited[top]){
            ++scc;
            dfs2(top);
            cout << endl;
        }
    }
    cout << scc << endl;
    if(scc == 1) cout << "Do thi lien thong manh";
    else cout << "Do thi k lien thong manh";
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    input();
    kosaraju();
    return 0;
}