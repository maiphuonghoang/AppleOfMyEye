
#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Đếm số lượng mảng con chẵn lẻ 
 * F[i]: số lượng số lẻ thời điểm i - số lượng số chẵn thời điểm i 
4
1 2 1 2
*/

void run(){
    int n; cin >> n;
    int a[n+1], F[n+1] = {0};
    map<int, int> mp;
    // if(a[i] % 2 == 1) 
    //     F[i] = F[i-1] + 1;
    // else
    //     F[i] = F[i-1] - 1;
    int t = 0;
    ll cnt = 0;
    mp[0] = 1; //đúng ngay cả mảng 
    f1(i,n){
        cin >> a[i];
        if(a[i] % 2 == 1) t++;
        else t--;
        F[i] = t;
        cnt += mp[F[i]];
        mp[F[i]]++;
    }
    cout << cnt;
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