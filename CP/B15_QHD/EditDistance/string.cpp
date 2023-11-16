#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
using ll = long long;
#define maxn 1e6
using namespace std;
int mod = 1e9 + 7;
/**
 * https://cses.fi/problemset/task/1639/
*/
int F[5005][5005];
void run() {
    string s1, s2; cin >> s1 >> s2;
    s1 = "0" + s1;
    s2 = "0" + s2;
    int n = s1.length(), m = s2.length();
    // F[i][j]: số bước thay đổi ít nhất tính đến 
    // thời điểm i của xâu s1 , tính đến thời điểm j của xâu s2 
    for (int i = 1; i <= n; i++)
        F[i][0] = i;
    for (int j = 1; j <= m; j++)
        F[0][j] = j;
    for (int i = 1; i <= n; i++){
        for (int j=1; j<=m; j++){
            if(s1[i] != s2[j])
                F[i][j] = min({F[i][j-1], F[i-1][j-1], F[i-1][j]}) + 1;
            else
                F[i][j] = F[i-1][j-1] ;
        }
    }
    cout << F[n][m] << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CP\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}
