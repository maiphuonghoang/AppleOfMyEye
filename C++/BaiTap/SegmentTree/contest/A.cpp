#include <bits/stdc++.h>
#define maxn 200005
using namespace std;

int n, q;
long long t[maxn*4];

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
    // n lần update, k cần dùng build 
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(1, 1, n, i, x);
    }
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
            cin >> v;
            cout << get(1, 1, n, 1, v) << "\n";
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