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

/** Tích lớn nhất 
 * Tính tích lớn nhất của 2 hoặc 3 phần tử trong dãy gồm các số nguyên 
5
-9 4 3 -3 1
=> 108
4
-9 -6 -5 1
=> 54
*/

void run(){
    int n; cin >> n;
    ll a[n];
    input(a);
    sort(a, a+n);
    if(n>3){
        cout<< max({
            a[0]*a[1],
            a[n-1]*a[n-2],
            a[n-1]*a[n-2]*a[n-3],
            a[0]*a[1]*a[n-1]
        });
    }else{
        cout << max(a[0]*a[1], a[n-1]*a[n-2]);
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