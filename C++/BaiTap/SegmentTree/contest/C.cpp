#include <bits/stdc++.h>
#define maxn 100005
#define f1(i,n) for (int i = 1; i <= n; i++)
using namespace std;
/*
    Lấy 2 số lớn nhất trong đoạn l->r
*/
int n, m;
long long a[maxn];
int t[maxn*4];

int add(int i, int j){
    return a[i] > a[j] ? i : j;
}
void build (int id, int l, int r){
    if(l==r) return t[id] = l, void();
    int m = (l + r)/2;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    t[id] = add(t[id*2], t[id*2+1]);
}
void update(int id, int l, int r, int p){
    if(p > r || p < l) return;
    if(l == r) return t[id] = p, void();
    int m = (l + r) / 2;
    update(id*2, l, m, p);
    update(id*2+1, m + 1, r, p);
    t[id] = add(t[id*2], t[id*2+1]);

}
int get(int id, int l, int r, int u, int v){
    if(r<u || l>v) return 0;
    if(u <= l && r <= v) return t[id];
    int m = (l + r)/2;
    int t1 = get(id*2, l, m, u, v);
    int t2 = get(id*2+1, m+1, r, u, v);
    return add(t1, t2);
}
long long Mul(long long a, long long b, long long MOD){
    if(b==0) return 0;
    long long t = Mul(a, b/2, MOD) * 2;
    if(b%2) t += a;
    return t%MOD;
}
void run(){
    cin >> n;
    f1(i, n) cin >> a[i];
    build(1,1,n);
    cin >> m;
    a[0] = 1;
    while(m--){
        int t, u; long long v;
        cin >> t >> u >> v;
        if(t){
            long long M; cin >> M;
            int p1 = get(1,1,n,u,v);
            int p2 = add(get(1,1,n,u,p1-1), get(1,1,n,p1+1,v));
            cout << Mul(a[p1], a[p2], M);
            cout << endl;
        }else{
            a[u] = v;
            update(1,1,n,u);
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

