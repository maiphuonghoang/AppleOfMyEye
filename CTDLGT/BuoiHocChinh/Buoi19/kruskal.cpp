#include <bits/stdc++.h>
using namespace std;
// Cây là đồ thị không có chu trình 
/*
Sắp xếp các cạnh theo trọng số tăng dần
Chọn cạnh có trọng số nhỏ nhất
Kiểm tra khi đưa vào trong cây khung có tạo thành chu trình k
Duyệt n-1 cạnh thì kết thúc 
*/
/*
6 9
1 2 1
1 3 2
3 2 3
2 4 4
2 5 7
3 5 5
4 5 3
4 6 2
5 6 2
=>
11
1 2 1
1 3 2
4 6 2
5 6 2
2 4 4
*/

/* Bài toán 
n thành phố, m đường
Sửa đường sao cho tất cả thành phố kết nối với nhau 
Tìm giải pháp sao cho chi phí sửa chữa nhỏ nhất 
=> Tìm cây khung cực tiểu 
*/

struct edge{
    int x, y, w;
};
int n, m; 
int sz[10001], parent[10001];
vector<edge> dscanh;

void init(){
    for (int i=1; i<=n; i++){
        sz[i] = 1;
        parent[i] = i;
    }
}
int find(int u){
    if(u == parent[u])
        return u;
    else return parent[u] = find(parent[u]);
}
bool Union(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)
        return false;
    if(sz[u] > sz[v]){
        parent[v] = u;
        sz[u] += sz[v];
    }else{
        parent[u] = v;
        sz[v] += sz[u];
    }
    return true;
}
void input(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int x, y, w; cin >> x >> y >> w;
        dscanh.push_back((edge){x, y, w});
    }
}
void kruskal(){
    // B1: Sắp xếp dsc theo trọng số tăng dần
    sort(dscanh.begin(), dscanh.end(), [](edge a, edge b)->bool{return a.w < b.w;});
    // B2: Lặp 
    int d = 0;
    vector<edge> MST; //cạnh chọn vào cây khung
    for (int i=0; i<m; i++){
        if(MST.size() == n - 1)
            break; //đã duyệt qua tất cả các đỉnh  
            edge e = dscanh[i];
            //Check MST + e có tạo thành chu trình 
            if(Union(e.x, e.y)) //có thể gộp
            {
                MST.push_back(e);
                d += e.w;
            }
    }
    cout << d << endl;
    for (auto it : MST)
        cout << it.x << " " << it.y << " " << it.w << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    input();
    init();
    kruskal();
    return 0;
}