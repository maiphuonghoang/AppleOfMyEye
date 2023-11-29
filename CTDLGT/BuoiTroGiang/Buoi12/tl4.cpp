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

/** Chia tập con 
 * Chia mảng a thành 2 mảng con kích cỡ k và n-k 
 * sao cho hiệu giữa tổng 2 mảng con là lớn nhất
Dồn những số to vào tập to 
6 4
3 10 10 7 5 2 
=> 27
*/

void run(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;
    sort(a, a+n);
    k = min(k, n-k);
    ll s1=0, s2=0;
    for(int i=0;i<n; i++){
        if(i<k) s1 += a[i];
        else s2 += a[i];
    }
    cout << s2 - s1 << endl;
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