#include <bits/stdc++.h>
#define el cout << endl;
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)

using namespace std;

int a[100] = {0, 1, 3, 5, 2, 4, 6, 8, 7}, n = 8, t[100];

void build (int id, int l, int r){
    if(l==r){
        t[id] = a[l];
        cout << id << ' ' << l << ' ' << r << ' ' << t[id], el;
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2 +1, mid + 1, r);
    t[id] = t[id*2] + t[id*2 +1];
        cout << id << ' ' << l << ' ' << r << ' ' << t[id], el;

}
int get (int id, int l, int r, int u, int v){
    if(r < u || v < l)
        return 0;
    if(u <= l && r <= v) {
        // cout << id << ' ' << l << ' ' << r << ' ' << t[id], el;
        return t[id];
    }
    int mid = (l + r) / 2;
    int t1 = get(id*2, l, mid, u, v);
    int t2 = get(id*2+1, mid+1, r, u, v);
    // cout << id << ' ' << l << ' ' << r << ' ' << t1 + t2, el;
    return t1 + t2;
}
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
int main() {
    build(1,1,n);
    cout << "get", el;
    get(1, 1, n, 2, 5);
    // Tìm tổng đoạn 2-5, thử nó giao với đoạn 1-n, cần thêm id quản lý đoạn 1-n để biết tổng 
    cout << "update", el;
    cout << get(1, 1, n, 2, 5) << " ";
    update(1,1,n,4,10);
    cout << get(1, 1, n, 2, 5);
    return 0;
}