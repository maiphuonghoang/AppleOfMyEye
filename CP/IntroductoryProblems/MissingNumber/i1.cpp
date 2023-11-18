#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

void run1(){//O(nlogn)
    set<int> se;
    int n; cin >> n;
    int a[n-1];
    f0(i,n-1) {
        cin >> a[i];
        se.insert(a[i]);
    }
    f1(i,n) {
        if(se.count(i) == 0)
            cout << i;
    }
}
void run2(){//O(n)
    ll n; cin >> n;
    ll totalSum = n*(n+1)/2;
    ll givenSum = 0;
    f0(i, n-1){
        int x; cin >> x;
        givenSum += x;
    }
    int missingNumber = totalSum - givenSum;
    cout << missingNumber << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CP\\input.txt", "r", stdin);
    #endif
    run2();
    return 0;
}