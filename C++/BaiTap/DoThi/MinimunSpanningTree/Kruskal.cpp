#include <bits/stdc++.h>
using namespace std;

/**
6 9
1 2 12 
1 3 4 
2 3 1 
2 4 5
2 5 3
3 5 2
4 5 3
4 6 10
5 6 8
=> MST: 18
2 3 1
3 5 2
4 5 3
1 3 4
5 6 8
*/

const int maxn = 1001;
int n, m;
int parent[maxn], size[maxn];

struct edge{
    int u, v;
    int w;
};
vector<edge> canh;


void make_set(){
    for (int i = 1; i < n; i++){
        parent[i] = i;
        size[i] = 1;
    }
}
int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}
bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;//không thể gộp a và b vào với nhau
    if(size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
    return true;
}
void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        edge e;
        e.u = x; e.v = y; e.w = w;
        canh.push_back(e);//đẩy cạnh vào danh sách cạnh 
    }
}
bool cmp(edge a, edge b){
    //comparator theo chiều dài tăng dần
    return a.w < b.w;
}
void kruskal(){
    //B1: Tạo cây khung cực tiểu rỗng 
    vector<edge> mst;
    int d = 0;
    //B2: Sort danh sách cạnh theo chiều dài tăng dần 
    sort(canh.begin(), canh.end(), cmp);
    //B3: Lặp
    for (int i = 0; i < m; i++){//duyệt qua tất cả cạnh 
        if(mst.size() == n-1) break;
        edge e = canh[i]; //chọn cạnh e là cạnh nhỏ nhất 
        if(Union(e.u, e.v))//có thể gộp 2 đỉnh của cạnh này vào mà nó k tạo thành chu trình 
        {
            mst.push_back(e); //đẩy cạnh e vào cây khung
            d += e.w;
        }
    }
    //Trả về kết quả 
    if(mst.size() != n-1) cout << "Do thi khong lien thong. Khong ton tai cay khung" << endl;
    else {
        cout << "MST: " << d << endl;
        for (auto it : mst){
            cout << it.u << " " << it.v << " " << it.w << endl;
        }
    }
}
void run(){
    input();
    make_set();
    kruskal();
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}