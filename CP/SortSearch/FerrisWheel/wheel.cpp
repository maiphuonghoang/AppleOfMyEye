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
 * https://cses.fi/problemset/task/1090/
Kết hợp nhỏ nhất và lớn nhất vào 1 cặp 
*/

void run(){
    int n, x; cin >> n >> x;
    int a[n]; input(a,n);
    sort(a, a+n);
    int i = 0, j = n-1;
    int cnt = 0;
    while(i<=j){
        if(a[i] + a[j] <= x){
            cout << a[i] << " " << a[j] << endl;
            i++;
            j--;
            cnt++;
        }else{
            j--;
            cnt++;
        }
    }
    cout << cnt << endl;
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