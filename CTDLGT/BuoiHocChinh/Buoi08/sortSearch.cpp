#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**B1
3 7
3 2 5 
=> 8
*/
bool checkSanPham(int a[], int n, int k, ll time){
    ll dem = 0;
    for (int i = 0; i < n;i++){
        dem += time/a[i];
        if(dem >= k)
            return true;
    }
    return false;
}
void factoryMachine(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    ll l = 0, r = 1ll * (*max_element(a, a+n)) * k;
    ll ans = -1;
    while(l<=r){
        ll m = (l+r)/2;
        if(checkSanPham(a, n, k, m)){
            ans = m;
            r = m - 1;
        }
        else 
            l = m + 1;
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/**
4 10
10 15 12 13
=> 10
*/
bool checkKhucGo(int a[], int n, int h, ll m){
    int dem = 0;
    for (int i = 0; i < n; i++){
        if(a[i] > m){
            dem += a[i] - m;
        }
    }
    return dem >= h;
}
void chatCayXayNha(){
    int n, h; cin >> n >> h;
    int a[n];
    for (int &x: a) cin >> x;

    ll ans = -1;
    ll l = 0, r = *max_element(a, a+n);
    while(l<=r){
        ll m = (l+r)/2;
        if(checkKhucGo(a, n, h, m)){
            ans = m;
            l = m + 1;
        }
        else 
            r = m - 1;           
    }
    cout << ans << endl;   
}
//----------------------------------------------------------------

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    chatCayXayNha();
    return 0;
}