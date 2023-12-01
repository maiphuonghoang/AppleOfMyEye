#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input0(a) f0(i,n) cin >> a[i]
#define output0(a) f0(i,n) cout << a[i] << " "; el
#define input1(a) f1(i,n) cin >> a[i]
#define output1(a) f1(i,n) cout << a[i] << " "; el
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Số Fibonaci thứ N 
 * 1<= N <= 10^10
dùng powMod để có O(logn)
     5          
|1 1|   =  |8 5|    |F[n+1]  F[n]  |
|1 0|      |5 3|    |F[n]    F[n-1]|
mũ n lên ma trận cơ sở 

58
=> 286725742
722019349 286725742
286725742 435293607
*/
struct Matrix{
    ll f[2][2];
};
Matrix operator * (Matrix a, Matrix b){
    Matrix c;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            c.f[i][j] = 0;
            for(int k=0; k<2; k++){
                c.f[i][j] += (a.f[i][k] * b.f[k][j]) %mod;
                c.f[i][j] %= mod;
            }
        }
    }
    return c;
}
Matrix powMod(Matrix a, ll n){
    if(n==1) return a; // a^1 
    Matrix x = powMod(a,n/2);
    if(n%2==0)
        return x*x;
    return a*x*x;
    //k được mod ở đây vì là nạp chồng toán tử nhân 
}
void run(){
    ll n; cin >>n;
    Matrix a;
    a.f[0][0] = a.f[1][0] = a.f[0][1] = 1;
    a.f[1][1] = 0;
    Matrix res = powMod(a, n);
    cout << res.f[1][0] << endl;
    for (int i=0; i<2; i++){
        for(int j=0; j<2; j++)
            cout << res.f[i][j] << " ";
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