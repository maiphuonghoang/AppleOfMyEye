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
5
1 2 5 3 4 
=> 4
    3 4 5 2 6 7 8 2 
F[] 1 2 3 1 2 3 4 1 
G[] 3 2 1 4 3 2 1 1
*/

void run(){
    int n; cin >> n;
    int a[n+1], F[n+1] = {0}, G[n+1] = {0};
    f1(i,n) cin >> a[i];
    int res = 1;
    F[1] = 1;
    for (int i=2; i<=n; i++){
        if(a[i] > a[i-1])
            F[i] = F[i-1] + 1;
        else 
            F[i] = 1;
        res = max(res, F[i]);//trong TH k xóa số nào 
    }
    G[n] = 1;
    for (int i=n-1; i>=1; i--){
        if(a[i] < a[i+1])
            G[i] = G[i+1] + 1;
        else 
            G[i] = 1;
    }
    f1(i,n) cout << F[i] << " ";el;
    f1(i,n) cout << G[i] << " ";

    //xóa 1 số ở giữa 
    for (int i=2; i<=n-1; i++){
        if(a[i-1]<a[i+1])
            res = max(res, F[i-1] + G[i+1]);
    }
    cout << res << endl;
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