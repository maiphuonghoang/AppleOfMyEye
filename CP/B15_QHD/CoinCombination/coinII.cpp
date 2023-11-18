#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define maxn 1000006
using namespace std;
/*
F[i][s]: số cách tạo ra tổng s chỉ dùng i số đầu tiên 
*/

int mod = 1000000007;
int a[102], n, x;
long long f[maxn];
void run(){
    cin >> n >> x;
    f1(i, n) cin >> a[i];
    f[0] = 1;
    f1(i, n){
        f1(s, x) 
            if(s >= a[i])
                f[s] = (f[s]+f[s-a[i]]) % mod;
    }
    cout << f[x];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}