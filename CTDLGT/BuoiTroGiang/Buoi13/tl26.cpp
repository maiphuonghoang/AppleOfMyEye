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

/** Tìm trị tuyệt đối nhỏ nhất giữa 2 phần tử bất kỳ trong mảng 
 * 2 ptu liên tiếp sẽ gần nhau nhất  
6
-2 3 6 17 19 5
=> 1
*/

void run(){
    int n; cin >> n;
    int a[n]; input(a);
    int min_abs = 1e9;
    sort(a, a+n);
    for(int i=1; i<n; i++)
        min_abs = min(min_abs, a[i] - a[i-1]);
    cout << min_abs << endl;
}
//----------------------------------------
/* 
    [5, 10, 7]
    min = 2^0 * 10 + 2^1 * 7 + 2^2 * 5
*/ 
void run2(){
    int n; cin >> n;
    int a[n]; input(a);
    ll res = 0;
    sort(a, a+n);
    ll h = 1;
    for(int i=0; i<n; i++){
        res += h*a[i];
        h*=2;
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