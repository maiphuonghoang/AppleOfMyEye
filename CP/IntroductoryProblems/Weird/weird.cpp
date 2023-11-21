
#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
using ll = long long;
#define maxn 1e6
using namespace std;
int mod = 1e9 + 7;
/**
 * 
*/
void run() {
    ll n; cin >> n;
    cout << n << " ";
    while(n > 1){
        if(n%2==0) n /= 2;
        else n = n*3 + 1;
        cout << n << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}
