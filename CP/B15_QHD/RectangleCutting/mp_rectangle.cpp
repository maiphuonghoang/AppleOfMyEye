#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f2(j,m) for (int j = 1; j <= m; j++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/*
https://cses.fi/problemset/task/1744
*/
int F[505][505];
int rec(int n, int m){
    if(n == m) return 0;
    if(F[n][m] != 0) return F[n][m];
    int res = 1e9;
    for (int i=1; i<m; i++)
        res = min(res, rec(n,i) + rec(n, m-i) + 1);
    for (int i=1; i<n; i++)
        res = min(res, rec(i, m) + rec(n-i, m) + 1);
    return F[n][m] = res;//lưu lại 
}
void run(){
    int a, b; cin >> a >> b;
    cout << rec(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CP\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}