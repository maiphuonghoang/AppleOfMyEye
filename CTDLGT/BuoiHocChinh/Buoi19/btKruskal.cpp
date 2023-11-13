#include <bits/stdc++.h>
using namespace std;

/* Bài toán 
n thành phố, m đường
Sửa đường sao cho tất cả thành phố kết nối với nhau 
Tìm giải pháp sao cho chi phí sửa chữa nhỏ nhất 
=> Tìm cây khung cực tiểu 
Đồ thị có nhiều thành phần liên thông thì k tạo cây con cực tiểu 
*/
/*
5 6 
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
=> 14 
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
    long long d = 0;
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
    if(MST.size() < n-1) //k kết nối được tất cả các đỉnh trên đồ thị 
        cout << "Impossible";
    cout << d << endl;

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