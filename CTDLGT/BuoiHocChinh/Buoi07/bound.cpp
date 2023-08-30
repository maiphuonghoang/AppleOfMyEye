#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void pointer(){
    int n; cin >> n;
    int a[n];
    for (int &x:a) cin >> x;
    cout << a << endl;
    for (int i = 0; i < n; i++)
        cout << &a[i] << " ";  cout << endl;
    cout << (a + 3) << endl; 
    cout << *(a + 3) << endl;

    sort(a, a  + n);
    auto it = a + 3;
    cout << it - a << endl;

}
/**
 * Đếm số lượng cặp số có tổng = k
*/
void twoSumEqual(){//O(nlogn)
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a+n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        //a[j] = k - a[i]
        auto it1 = lower_bound(a + i + 1, a+n, k-a[i]);
        auto it2 = upper_bound(a + i + 1, a+n, k-a[i]);
        ans += it2 - it1;
    }
    cout << ans << endl;
}
/**
 * Đếm số lượng cặp số có tổng < k
lower[aj] rồi dịch sang trái 1 cái là ra vị trí cuối cùng của ptu < a[j]
*/
void twoSumLesser(){//O(nlogn)
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a+n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(a + i + 1, a+n, k-a[i]);
        --it;
        ans += it - (a + i);
    }
    cout << ans << endl;
}
/**
 * Đếm số lượng cặp số có tổng > k
*/
void twoSumLesser(){//O(nlogn)
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a+n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(a + i + 1, a+n, k-a[i]);
        ans += a + n - it;
        //cuối dãy - upper 
    }
    cout << ans << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    pointer(); 
    return 0;
}