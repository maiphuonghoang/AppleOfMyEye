#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000001;
int n, parent[maxn], sz[maxn];

void init(){
    cin >> n;
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
    /*
    else{
        int tmp = find(parent[u]);
        parent[u] = tmp;
        return tmp;
    }
    */
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
        return true;
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    return 0;
}
