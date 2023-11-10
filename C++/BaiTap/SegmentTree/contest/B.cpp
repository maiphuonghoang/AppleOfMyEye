#include <bits/stdc++.h>
#define el cout << endl;
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 200005
using namespace std;

int n, q, a[maxn];
long long t[maxn*4];

// nlogn
void build (int id, int l, int r){
    if(l==r){
        t[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2 +1, mid + 1, r);
    t[id] = t[id*2] + t[id*2 +1];

}
// logn
long long get (int id, int l, int r, int u, int v){
    if(r < u || v < l)//nằm ngoài 
        return 0;
    if(u <= l && r <= v) {//nằm trong 
        return t[id];
    }
    // giao 
    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}
// logn
void update (int id, int l, int r, int pos, int val){
    if(pos < l || r < pos) //k chứa pos
        return;
    if(l == r) {//đoạn chứa pos l=r=pos
        t[id] = val;
        a[l] = val;
        return;
    }
    // x nằm trong [l,r], xem nằm bên trái hay phải 
    int mid = (l + r) / 2;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid + 1, r, pos, val);
    t[id] = t[2*id] + t[2*id+1];
}
void run (){
    cin >> n >> q;
    f1(i, n) cin >> a[i];
    build(1,1,n);
    while (q--){
        int type, pos, val, u, v;
        cin >> type; 
        // Nếu t=1, nhập x, v; gán ax = v.
        if(type == 1){
            cin >> pos >> val;
            update(1, 1, n, pos, val);
        } 
        // Nếu t=2, nhập x; tính tổng các số từ a1 đến ax.
        if(type == 2){
            cin >> u >> v;
            cout << get(1, 1, n, u, v), el;
        } 
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}