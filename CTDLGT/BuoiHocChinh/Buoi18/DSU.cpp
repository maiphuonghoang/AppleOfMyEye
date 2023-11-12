#include <bits/stdc++.h>
using namespace std;

int n, parent[1000001];

void init(){
    cin >> n;
    for (int i=1; i<=n; i++)
        parent[i] = i;
}
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
    init();
    cout << Union(6,7) << endl;
    cout << Union(5,6) << endl;
    cout << Union(4,5) << endl;
    cout << Union(4,7) << endl;
    cout << Union(2,5) << endl;
    for (int i=1; i<=n; i++)
        cout << i << " " << parent[i] << endl;
/*
1
1
1
0
1
1 1
2 2
3 3
4 2
5 4
6 5
7 6
*/
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}
