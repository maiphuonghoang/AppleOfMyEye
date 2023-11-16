#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f2(j,m) for (int j = 1; j <= m; j++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Mảng n số nguyên, độ lêch giữa 2 phần tử liền kề trong mảng k vượt quá 1.
 * Cho 1 mảng trong đó 1 số giá trị trong mảng chưa xác định giá trị.
 * Đếm số mảng có các số liền kề k lệch nhau quá 1, các gtri trong mảng chỉ từ 1 tới m.
 * Giá trị 0 biểu thị cho 1 giá trị không xác định 
3 5
2 0 2
=> 3
*/
ll F[10001][10001];
void run(){
    int n, m; cin >> n >> m;
    int a[n+1]; f1(i, n) cin >> a[i];

    //khởi tạo x 0 0 số đầu k là vô định 
    if(a[1] != 0)
        F[1][a[1]] = 1;
    else{ // 0 0 0 số đầu là vô định 
        for (int j=1; j<=m; j++)
            F[1][j] = 1;
    }

    for (int i=2; i<=n; i++){
        // nếu vô định thì bắt đầu điền
        // thử tất cả các giá trị từ 1 tới m 
        if(a[i] == 0){
            for (int j=1; j<=m; j++){
                // tại vị trí i điền gtri j có bao nhiêu cách 
                F[i][j] = F[i-1][j-1] 
                        + F[i-1][j] 
                        + F[i-1][j+1];
                F[i][j] %= mod;
            }
        }else{//nếu cố định rồi thì k được phép thử 
            F[i][a[i]] = F[i-1][a[i]-1] 
                        + F[i-1][a[i]] 
                        + F[i-1][a[i]+1];
            F[i][a[i]] %= mod;
        }
    }
    int res = 0;
    for (int j=1; j<=m; j++)
        res += F[n][j];
    cout << res;
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