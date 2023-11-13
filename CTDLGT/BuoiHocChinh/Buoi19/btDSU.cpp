/*
Có n thành phố và ban đầu k có đường giữa chúng 
Tuy nhiên mỗi ngày 1 con đường mới sẽ được xây dựng và sẽ có tổng cộng m con đường 
Một cụm thành phố là 1 nhóm các thành phố trong đó có 1 tuyến đường giữa 2 thành phố bất kỳ 
bằng cách sử dụng các con đường. Sau mỗi ngày, tìm ra số lượng cụm thành phố 
và kích thước của cụm thành phố lớn nhất 
=>
2 thành phố gộp được thì số lượng thành phố giảm đi 1
cụm có thành phố lớn nhất : dùng mảng size 
*/
/*
5 3
1 2
1 3
4 5
=>
5
4 2
3 3
2 3
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000001;
int n, m, max_current = 1;
int parent[maxn], sz[maxn];

void init(){
    for (int i=1; i<=n; i++){
        parent[i] = i;
        sz[i] = 1; //số lượng đỉnh mà i quản lý 
    }
}
int find(int u){// TỐI ƯU NÉN ĐƯỜNG 
    if(u == parent[u])
        return u;
    else 
        return parent[u] = find(parent[u]);
}
bool Union(int u, int v){//TỐI ƯU GỘP 
    // hạn chế tìm lại cha bằng cách cho tập hợp có size lớn hơn làm đại diện 
    u = find(u);
    v = find(v);
    if(u == v)
        return false; //k gộp được 
    else{
        if(sz[u] < sz[v])
            swap(u, v);//u là thằng có size lớn hơn 
        sz[u] += sz[v];
        parent[v] = u;
        max_current = max({max_current, sz[u], sz[v]});
        return true;
    }
}

void run(){
    cin >> n >> m;
    init();
    int dem = n;//số lượng cụm thành phố ban đầu
    cout << dem << endl;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        if(Union(x, y)) //2 thành phố thuộc 2 cụm khác nhau mới gộp được 
            --dem;
        cout << dem << " " << max_current << endl;
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}
