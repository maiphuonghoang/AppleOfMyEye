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

/** Xâu con chung dài nhất
 * 
ZHFTDFHF
TFISHROW
=> 3
*/
int F[1001][1001];
void run(){
    string s1, s2; cin >> s1 >> s2;
    int n = s1.length(); int m = s2.length();
    s1 += "0" + s1;
    s2 += "0" + s2;

    F[0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i] == s2[j])
                F[i][j] = F[i-1][j-1] + 1;
            else
                F[i][j] = max(F[i-1][j], F[i][j-1]);
        }
    }
    cout << F[n][m] << endl;
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