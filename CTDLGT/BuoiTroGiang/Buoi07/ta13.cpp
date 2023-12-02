#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define input0(a, n, m) for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j]
#define output0(a, n, m) for (int i = 0; i < n; i++){for (int j = 0; j < m; j++) cout << a[i][j]; el;} 
#define input1(a, n, m) for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j]
#define output1(a, n, m) for (int i = 1; i <= n; i++){for (int j = 1; j <= m; j++) cout << a[i][j]; el;} 
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Nhân ma trận 
 * 
3 4 5 
1 2 3 4 
5 6 7 8 
9 10 11 12
1 2 3 4 5 
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
=> 
110 120 130 140 150 
246 272 298 324 350 
382 424 466 508 550 
*/
int n, m, p;
ll a[55][55], b[55][55];
void run(){
    cin >> n >> m >> p;
    input0(a,n,m); input0(b,m,p);

    //ma trận tích phải có n hàng và p cột 
    ll c[n][p];
    for(int i=0; i<n; i++){
        for(int j=0; j<p;j++){
            //mỗi phần tử của c = tổng (ptu hàng i mta * ptu cột j mtb)
            //lặp m lần 
            //c[3][3] = a[3][1]*b[1][3] + a[3][2]*b[2][3] ...
            c[i][j] = 0;
            for(int k=0; k<m; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<p;j++)
            cout << c[i][j] << " ";
        el;
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