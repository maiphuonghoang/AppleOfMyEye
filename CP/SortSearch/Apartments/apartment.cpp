#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input(a,n) f0(i,n) cin >> a[i];
using ll = long long;
using namespace std;

/**
 * https://cses.fi/problemset/task/1084
*/

void run(){
    int n, m, x; cin >> n >> m >> x;
    int a[n], b[m];
    input(a,n); input(b, m);
    sort(a,a + n); sort(b,b + m);
    int i = 0, j = 0;
    int cnt = 0;
    while(i<n && j<m){
        if(a[i] >= b[j] - x && a[i] <= b[j] + x) {
            cnt++;
            i++;
            j++;
        }else if(a[i] < b[j] - x || a[i] < b[j] + x){
            i++;
        }else{
            j++;
        }
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CP\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}