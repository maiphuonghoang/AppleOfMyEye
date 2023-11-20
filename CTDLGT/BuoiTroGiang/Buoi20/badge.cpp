#include <bits/stdc++.h>
#define el cout << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/*
đã used mà quay lại 
3
2 3 2
=> 2 2 3 
*/
int res, d[1005], p[1005];
void xuly(int u){
    d[u]++;
    if (d[u] == 2)
        res = u;
    else
        xuly(p[u]);
}

void run(){
    int n; cin >> n;
    f1(i, n) cin >> p[i];
    f1(i, n){
        memset(d, 0, sizeof(d));
        xuly(i);
        cout << res << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}