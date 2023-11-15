#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f2(j,m) for (int j = 1; j <= m; j++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/*
1807
=> 2915
*/

void run(){
    string s; cin >> s;
    int n = s.length();
    s = "0" + s;
    ll F[n+1] = {0};
    ll sum = 0;
    for (int i=1; i<=n; i++){
        F[i] = F[i-1] * 10 + i * (s[i] - '0');
        sum += F[i];
    }
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