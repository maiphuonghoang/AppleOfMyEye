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

/** Subset sum problem
 * Cho dãy a có n phần tử. Xác định xem có thể chia mảng a thành 2 tập 
 * sao cho tổng của 2 tập bằng nhau hay không  
 * Tìm dãy có tổng = s/2, dãy con 
4
1 2 3 4
=> Yes 
*/
int n, s = 0, x[100], a[100], ok = 0;
void ql(int i, int bd, int sum){
    if(ok) return;
    for(int j=bd; j<=n; j++){
        if(sum + a[j] <= s){
            x[i] = a[j];
            if(sum + a[j] == s)
                ok = 1;
            else ql(i+1, j+1, sum + a[j]);
        }
    }

}
void run(){
    cin >> n;
    f1(i,n){
        cin >> a[i];
        s += a[i];
    }
    if(s%2 == 1){
        cout << 0;
        return;
    }
    s /= 2;
    sort(a+1, a+n+1);
    ql(1, 1, 0);
    cout << ok;
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
