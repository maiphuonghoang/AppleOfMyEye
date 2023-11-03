#include <bits/stdc++.h>
using namespace std;

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
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif

    return 0;
}