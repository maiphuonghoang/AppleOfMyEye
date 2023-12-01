#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input(a) f0(i,n) cin >> a[i]
#define output(a) f0(i,n) cout << a[i] << " "
using ll = long long;
using namespace std;

/** Cái túi 
 *W <= 1000, N<= 1000
6 22
39 44 4 59 91 70 
47 26 92 33 6 69
*/
int F[1001][1001];
void run(){
    int n, W; cin >> n >> W;
    int w[n+1], v[n+1];
    f1(i, n) cin >> w[i];
    f1(i, n) cin >> v[i];
    F[0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(j >= w[i]) //lấy nó
                F[i][j] = max(v[i] + F[i-1][j-w[i]], F[i-1][j]);
            else
                F[i][j] = F[i-1][j]; 
        }       
    }
    cout << F[n][W] << endl;
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