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
3 5
=> 4
*/
int n, m, F[1005][1005];
int tinh(int n, int m){
    if(n==m)// là hình vuông rồi 
        return 0;
    if(F[n][m] != 0) return F[n][m];
    int res = 1e9;
    // cắt dọc
    for (int i = 1; i < m; i++)
        res = min(res, tinh(n, i) + tinh(n, m-i) + 1);
    
    //cắt ngang 
    for (int i=1; i<n; i++)
        res = min(res, tinh(i, m) + (n-i, m) + 1);

    return F[n][m] = res;
}
void run(){
    int n, m;
    cin >> n >> m;
    cout << tinh(n,m);
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