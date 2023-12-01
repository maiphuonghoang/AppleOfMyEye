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

/** Lũy thừa ma trận 
 * Cho ma trận vuông A[][] cỡ nxn
 * Tính kết quả A^k và tổng các phần tử cột cuối cùng 
2 3
712 141
55 619
=> sum = 441039817
376787593 188740908 
73622340 252298909 


2 2
216 71
923 906
=> sum = 966031  
112189 79662 
1035606 886369
*/
ll n, k;
struct Matrix{
    ll f[2][2];
};
Matrix operator * (Matrix a, Matrix b){
    Matrix c;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            c.f[i][j] = 0;
            for(int k=0; k<n; k++){
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
    cin >> n >> k;
    Matrix a;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> a.f[i][j];
    }
    Matrix res = powMod(a, k);
    for (int i=0; i<2; i++){
        for(int j=0; j<2; j++)
            cout << res.f[i][j] << " ";
        el;
    }
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum += res.f[i][n-1];
        sum %= mod;
    }
    cout << "sum = " <<sum << endl;   
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