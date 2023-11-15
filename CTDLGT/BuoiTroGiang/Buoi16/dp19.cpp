#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;
// QHD từ dưới lên trên, xây dựng con -> cha 
/*
4
....
.*..
...*
*...
=> 3
*/
int n, m;
char a[1001][1001];
int F[1001][1001];
// void input (){
//     cin >> n;
//     m = n;
//     for (int i=1; i <=n; i++)
//         for (int j=1; j <= m; j++)
//             cin >> a[i][j];
// }
// void run(){
//     F[0][1] = 1;
//     for (int i=1; i <=n; i++)
//         for (int j=1; j <= m; j++){
//             // thuộc ma trận, k phải là bẫy 
//             if(a[i][j] == '.')
//                 F[i][j] = F[i-1][j] + F[i][j-1];    
//             else    
//                 F[i][j] = 0;
//             F[i][j] %= mod;
//         }
//     cout << F[n][m];
// }
void input (){
    cin >> n >> m;
    for (int i=1; i <=n; i++)
        for (int j=1; j <= m; j++)
            cin >> a[i][j];
    for (int i=1; i <=n; i++)
        for (int j=1; j <= m; j++)
            cout << a[i][j];
}
void run(){
    int res = 0;
    for (int i=1; i <=n; i++)
        for (int j=1; j <= m; j++){
            if(a[i][j] == 1)
                // số lượng ô của hình vuông lớn nhất nó quản lý được    
                F[i][j] = max(F[i-1][j], F[i-1][j-1], F[i][j-1]) + 1;
            else //a[i][j] == 0
                F[i][j] = 0;
            res = max(res, F[i][j]);
        }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    input();
    run();
    return 0;
}