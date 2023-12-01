
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

/** Frog
 * 1 con ếch có thể nhảy 1,2,3 bước để có thể lên đến đỉnh cần đến.
 * Đếm số cách con ếch có thể nhảy đến đỉnh 
 * 1<N<40
5
=> 13

*/
ll F[45];
void run(){
    int n; cin >> n;
    F[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++)
            if(i >= j)
                F[i] += F[i-j];
    }
    cout << F[n];
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