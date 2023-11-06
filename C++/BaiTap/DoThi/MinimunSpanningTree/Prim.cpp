#include <bits/stdc++.h>
using namespace std;
/*
6 9
1 2 9
1 3 4 
2 3 1 
2 4 6
3 5 2
4 5 3
4 6 10
5 6 8
=> Chieu dai cuc tieu = 18
// các cạnh được chọn và trọng số
3 1 4
2 3 1
5 3 2
4 5 3
6 5 8
*/
const int maxn = 1001;
int n, m;
vector<pair<int, int>> adj[maxn]; //lưu đỉnh kề và trọng số của 1 đỉnh
bool used[maxn];// đánh dấu đỉnh thuộc tập V hay Vmst
//used[i] = true: i thuộc tập V(mst), used[i] = false: i thuộc tập V

struct edge{
    int x, y, w;
};
void inputV1(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    memset(used, false, sizeof(used));
}
void primV1(int u){
    // Khởi tạo cây khung rỗng có chiều dài = 0
    vector<edge> MST;
    int d = 0;
    // Thêm đỉnh u vào Vmst, loại đỉnh u khỏi tập đỉnh V ban đầu 
    used[u] = true;

    // Lặp khi V # rỗng
    while (MST.size() < n-1)//tất cả các đỉnh thuộc tập Vmst
    {
        // Chọn ra cạnh e ngắn nhất 
        //e = (x, y): x thuộc V, y thuộc Vmst
        int min_w = INT_MAX;
        int X, Y;//lưu 2 đỉnh của cạnh e 
        for (int i = 1; i <= n; i++){//duyệt tất cả các đỉnh của đồ thị 
            if(used[i] == true)//nếu đỉnh i thuộc Vmst
            {
                // Duyệt danh sách kề của nó 
                for (pair<int, int> it : adj[i]){
                    // lấy ra các đỉnh thuộc V
                    int j = it.first;
                    int trongso = it.second;
                    if(used[j] == false && trongso < min_w){
                        min_w = trongso;
                        X = j; Y = i;//lưu lại cạnh e
                    }
                }
            }
        }
        //lấy được cạnh ngắn nhất rồi thì đẩy vào MST 
        MST.push_back({X, Y, min_w});
        d += min_w;
        used[X] = true;// Thêm đỉnh x vào tập đỉnh của cây khung + Xóa X khỏi tập đỉnh ban đầu
    }
    cout << "Chieu dai cuc tieu = " << d << endl;
    for (edge e : MST)
        cout << e.x <<" "<< e.y << " " << e.w << endl;
    
}
void runV1(){
    inputV1();
    primV1(1);
}
//----------------------------------------------------------------
// C2: Tìm cạnh ngắn nhất bằng hàng đợi ưu tiên 
int parent[maxn], d[maxn];
void inputV2(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    memset(used, false, sizeof(used)); 
    for (int i = 1; i <= n; i++)
        d[i] = INT_MAX; 
}
void primV2(int u){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    // hàng đợi lưu {độ dài, đỉnh kề} để sắp xếp sẵn theo trọng số 
    vector<edge> MST;
    int res = 0;
    Q.push({0, u});
    while(!Q.empty()){
        pair<int, int> top = Q.top(); Q.pop();
        int dinh = top.second; 
        int trongso = top.first;
        if(used[dinh] == true) continue;//đỉnh đã thuộc Vmst 
        //chỉ xét những đỉnh chưa thuộc Vmst
        res += trongso;
        used[dinh] = true;
        if(u != dinh)//loại đỉnh bắt đầu ra vì k có đỉnh nào nối với đỉnh này 
            MST.push_back({dinh, parent[dinh], trongso});
        // duyệt tất cả đỉnh kề với nó
        for (auto it : adj[dinh]){
            int y = it.first, w = it.second;
            if(used[y] == false && w < d[y]){
                Q.push({w, y});
                d[y] = w;
                parent[y] = dinh;
            }
        }
    }
    cout << "Chieu dai cuc tieu = " << res << endl;
    for (edge e : MST)
        cout << e.x <<" "<< e.y << " " << e.w << endl;
}
void runV2(){
    inputV2();
    primV2(1);
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    runV2();
    return 0;
}