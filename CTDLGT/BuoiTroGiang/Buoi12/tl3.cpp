#include <bits/stdc++.h>
#define el cout << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Tính tổng lớn nhất của dãy a
 * max = Xích ma(n-1, i=0) a[i] * i
 * sort mảng thì sẽ có được chỉ số tăng và giá trị tăng 
 * In ra kết quả với phép chia module  
6   
8 1 7 9 8 1
=> 116
*/

void run(){
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    sort(a, a+n);
    ll res = 0;
    for(int i=0;  i<n; i++){
        res += 1ll * a[i] * i;
        res %= mod;
    }
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