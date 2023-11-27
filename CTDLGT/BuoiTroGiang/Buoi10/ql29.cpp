#include <bits/stdc++.h>
#define el cout << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Biểu thức lớn nhất
 * Cho 4 số nguyên x, y, z, t.
 * Tìm giá trị lớn nhất của x o1 y o2 z o3 t
 * trong đó o1,o2,o3 có thể là các dấu + - 
 * 4 số điền 3 dấu +++ --- 
59 71 80 -3
=> 213
*/
int n, a[100], x[100];
int res = -1e9;
void xuly(){
    int sum = a[1];
    f1(i, n){
        if(x[i] == 1) sum += a[i+1];
        else sum -= a[i+1];
    }
    res = max(res, sum);
}
void ql(int i){
    for(int j=0;j<=1;j++){
        x[i] = j;
        if(i==n) xuly();
        else ql(i+1);
    }
}
void run(){
    for(int i=1; i<=4; i++) cin >> a[i];
    n = 3;
    ql(1);
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
