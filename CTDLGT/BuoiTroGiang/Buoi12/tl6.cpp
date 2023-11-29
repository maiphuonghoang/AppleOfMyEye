#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input(a) f0(i,n) cin >> a[i]
using ll = long long;
using namespace std;

/** Max product of two array 
 * Cho mảng a, b đều có n phần tử. Tìm max của biểu thức 
 * P = a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1] bằng cách 
 * tráo đổi vị trí các phần tử của cả mảng a và b 
Lớn chơi với lớn, bé chơi với bé 
7
9 4 5 3 9 4 10
9 5 3 1 10 1 5 
=> 270
*/

void run(){
    int n; cin >> n;
    int a[n], b[n];
    input(a); input(b);
    sort(a, a+n);
    sort(b, b+n);
    ll sum = 0;
    for(int i=0; i<n; i++)
        sum += 1ll*a[i]*b[i];
    cout << sum << endl;
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