
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

/** Maximum path sum 
 * Tìm chi phí lớn nhất đi từ ô (1,1) tới (n,n) của ma trận 
 * Chỉ được đi sang phải hoặc xuống dưới 
          |
          |
    ---> con
Chọn cha
chi phí F[con] = max_F[cha] + a[i][j] 
3 3
1 2 2
3 10 2
5 7 2
=> 23
*/
int a[505][505], F[505][505];
void run1(){
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
            cin >> a[i][j];
    }    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            F[i][j] = max(F[i-1][j], F[i][j-1]) + a[i][j];
            //F[0][0] = 0 do khởi tạo ở ngoài 
        }
    }
    cout << F[n][m] << endl;
}
//----------------------------------------------------------------
/** Maximum path sum 
 * Tìm chi phí lớn nhất đi từ dòng 1 tới dòng N của ma trận 
 * Từ ô hiện tại chỉ có thể đi xuống ô dưới bên trái, ô dưới 
 * bên phải hoặc ô dưới của ô hiện tại 
       cha 
     /  |  \        \  |  /
    /   |   \        \ | /
                      con 
5
5 1 8 6 7 
6 0 0 3 7 
3 4 1 5 3 
9 8 9 2 2 
5 3 4 5 3
=> 33
Tìm max của dòng cuối 
*/
void run2(){
    int n, m; cin >> n; m = n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
            cin >> a[i][j];
    }    
    //duyệt từng dòng một 
    //duyệt từ trên xuống dưới, từ trái qua phải 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            F[i][j] = max({F[i-1][j-1], F[i-1][j], F[i-1][j+1]}) + a[i][j];
        }
    }
    cout << *max_element(F[n]+1, F[n]+m+1) << endl;
}
//----------------------------------------------------------------
/** Maximum path sum 
 * Tìm chi phí lớn nhất đi từ cột 1 tới cột N của ma trận 
 * Từ ô hiện tại chỉ có thể đi sang phải, ô trên bên phải
 * hoặc đi xuống ô dưới bên phải 
 *         /            \
 *        /              \
      cha ----       ----- con 
          \              /
           \            /
5
2 -8 2 9 0
-5 6 6 -1 6 
3 5 0 2 9 
9 -8 9 7 0 
-4 6 1 -2 0 
=> 40
Tìm max của dòng cuối 
*/
void run(){
    int n, m; cin >> n; m = n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
            cin >> a[i][j];
    }    
    //khởi tạo
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=m+1; j++)
            F[i][j] = -1e9;
    }   
    //cột đầu tiên
    for(int i=1; i<=n; i++)
        F[i][1] = a[i][1];
    //duyệt từng CỘT một 
    //C1 duyệt từ trái qua phải, đi từ dưới lên trên
    for(int j=2; j<=m; j++){
        for(int i=1; i<=n; i++){
            F[i][j] = max({F[i-1][j-1], F[i][j-1], F[i+1][j-1]}) + a[i][j];
        }
    }
    //C2 hoặc duyệt từ trái qua phải, đi từ trên xuống dưới 
    /*
    for(int j=2; j<=m; j++){
        for(int i=n; i>=1; i--){
            F[i][j] = max({F[i-1][j-1], F[i][j-1], F[i+1][j-1]}) + a[i][j];
        }
    }
    */
    ll res = -1e9;
    for(int i=1; i<=n; i++){
        if(res < F[i][m])
            res = F[i][m];
        //res = max(res, F[i][m]);
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
/*   \   /
       x
     /   \
4 hướng k giải quyết được bằng cách này 
*/