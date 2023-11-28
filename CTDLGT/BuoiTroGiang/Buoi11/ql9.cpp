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

/** MáY ATM
 * 1 máy ATM hiện có n (n<=30) tờ tiền có giá trị t[1], t[2],...t[n].
 * Hãy tìm cách trả ít tờ nhất với số tiền đúng bằng S (các tờ tiền có 
 * giá trị bất kỳ và có thể bằng nhau, mỗi tờ tiền chỉ được dùng 1 lần)
6 30
10 4 10 5 8 8 
=> 4
*/
int n, s, x[100] ,a[100], res = 1e9;
void ql(int i, int bd, int sum){
    for(int j=bd; j<=n; j++){
        if(sum + a[j] <= s){
                cout << i << endl;
            if(sum + a[j] == s)
                res = min(res, i);
            else ql(i+1, j+1, sum + a[j]);
        }
        //các ptu đằng sau > sum rồi thì bỏ qua hết 
        else return; 
    }
}
void run(){
    cin >> n >> s;
    f1(i,n) cin >> a[i];
    sort(a+1, a+n+1);
    ql(1, 1, 0);
    if(res == 1e9) cout << -1;
    else cout << res;
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
