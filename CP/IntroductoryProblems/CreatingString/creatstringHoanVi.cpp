#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
using ll = long long;
#define maxn 1e6
using namespace std;
int mod = 1e9 + 7;
/**
 * https://cses.fi/problemset/task/1622/
*/
void run() {
    string s; cin >> s;
    int n = s.length();
    int a[n];
    set<string> se;
    //HOÁN VỊ THUẬN 
    for (int i=0; i<n; i++) 
        a[i] = i;
    do{
        string tmp = "";
        //in ra cấu hình hiện tại
        for (int i=0; i<n; i++){
            tmp += s[a[i]];
        }
        se.insert(tmp);
    }
    while(next_permutation(a, a+n));//sinh ra cấu hình kế tiếp 
    cout << se.size() << endl;
    for (string s : se) cout << s << endl;
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

