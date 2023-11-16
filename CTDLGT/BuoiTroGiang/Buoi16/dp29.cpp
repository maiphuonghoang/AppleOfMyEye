#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f2(j,m) for (int j = 1; j <= m; j++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Đếm số các cách các số 1,2..n có thể chia thành 2 tập có tổng phần tử bằng nhau  
 * Các ptu trong tập k xét đến thứ tự 
 * In ra kết quả sau khi chia dư với 1e9+7
=> Đếm số cách tạo ra tổng n, dãy con có tổng bằng s 
7 => 4
*/
int F[250005];
void run1(){
    int n; cin >> n;
    int sum = n*(n+1)/2;
    if(sum %2 == 0){
        sum /= 2;
        F[0] = 1;
        for (int i=1; i<=n; i++){
            for (int j=sum; j>=1; j--){
                if(j >= i)
                    F[j] += F[j-i];
            }
        }
        cout << F[sum]/2 << endl;
    }
    else cout << 0;
}
//có mudule
void run2(){
    //F[14] tm s=14 và có 7 trong đó 
    int n; cin >> n;
    int sum = n*(n+1)/2;
    int res = 0;
    if(sum %2 == 0){
        sum /= 2;
        F[0] = 1;
        for (int i=1; i<=n; i++){
            for (int j=sum; j>=1; j--){
                if(j >= i){
                    F[j] =F[j] + F[j-i];

                    //có lấy 
                    if(i==n && j==sum)
                       res = F[j-i];
                }
                F[j] %= mod;
            }
        }
        cout << res << endl;
    }
    else cout << 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run2();
    return 0;
}