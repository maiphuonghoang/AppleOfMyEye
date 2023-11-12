// khi nhập dsc thì union 
// đỉnh có đại diện là chính nó thì là 1 thành phần liên thông 
#include <bits/stdc++.h>
using namespace std;
/*
5 4
4 1
2 1
3 2
4 3
=> 2
*/

int n, m, parent[1000001];


int find(int u){
    while(u != parent[u])
        u = parent[u];
    return u;
}
bool Union(int u, int v){
    u = find(u);//tìm đại diện của đỉnh u
    v = find(v);//tìm đại diện của đỉnh v
    if(u == v)
        return false; //k gộp được 
    else{
        if(u < v)
            parent[v] = u;
        else
            parent[u] = v;
        return true;
    }
}
void run(){
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        parent[i] = i;
    for (int i = 0; i <m; i++){
        int x, y; cin >> x >> y;
        Union(x, y);
    }
    int dem = 0;
    // duyệt qua các đỉnh của đồ thị 
    for (int i=1; i<=n; i++)
        if(i == parent[i])
            ++dem;
    cout << dem << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}
