#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
using ll = long long;
#define maxn 1e6
using namespace std;
int mod = 1e9 + 7;
/**
 * https://cses.fi/problemset/task/1069
*/
void run() {
    string s; cin >> s;
    int ans = 0;
    map<char, int> mp;
    for (int i = 0; i < s.length(); i++) {
        if(i>0 && s[i] != s[i-1])
            mp[s[i]] = 1;
        else mp[s[i]]++;
        ans = max(ans, mp[s[i]]);
    }
    cout << ans;
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
