#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 200005
using ll = long long;
using namespace std;

int n, a[maxn];

struct Node{
    ll sum, pre, suf, ma;
} t[maxn*4];

Node merge(const Node &a, const Node &b){
    Node ans;
    ans.ma = max({a.ma, b.ma, a.suf + b.pre});
    ans.pre = max(a.pre, a.sum + b.pre);
    ans.suf = max(b.suf, b.sum + a.suf);
    ans.sum = a.sum + b.sum;
    return ans;
}

void update(int id, int l, int r, int pos, int val){
    if(pos < l || r < pos) return;
    if(l==r) {
        t[id] = {val, max(0, val), max(0,val), val};
        return;
    }
    int m = (l + r) / 2;
    update(id*2, l, m, pos, val);
    update(id*2 + 1, m+1, r, pos, val);
    t[id] = merge(t[id*2], t[id*2+1]);
}
Node get(int id, int l, int r, int u, int v){
    if(r<u || l>v) return Node({0, 0, 0, 0});
    if(u <= l && r <= v) return t[id];
    int m = (l + r) / 2;
    Node t1 = get(id*2, l, m, u, v);
    Node t2 = get(id*2 + 1, m+1, r, u, v);
    return merge(t1, t2);
}
void run(){
    cin >> n; int q; cin >> q;
    for (int i = 1; i <=n; ++i){
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    while(q--){
        int pos, val; cin  >> pos >> val; 
        update(1, 1, n, pos, val);
        cout << t[1].ma; el;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}