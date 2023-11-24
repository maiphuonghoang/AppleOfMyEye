#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define nhap_mang for(int &x : a) cin >> x
#define input(a) for(int &x : a) cin >> x
#define xuat_mang for(int x : a) cout << x << " "
using ll = long long;
using namespace std;

/**
 * Đưa ra các phần tử của mảng theo khuôn dạng 
 * lớn nhất, nhỏ nhất, lớn thứ 2, nhỏ thứ 2
2
7
7 1 2 3 4 5 6
8
1 6 9 4 3 7 8 2 
=> 
7 1 6 2 5 3 4 
9 1 8 2 7 3 6 4
*/
void run1(){//O(nlogn)
    int n; cin >> n;
    int a[n]; nhap_mang;
    sort(a, a+n);
    int l = 0, r = n-1;
    while(l<=r){
        if(l==r){
            cout << a[l] << " ";
            break;
        } 
        else{
            cout << a[r] << " " << a[l] << " ";
            ++l; --r;
        }
    }
    el;
}
//----------------------------------------------------------------
/**Couting sort
 * Sắp xếp mảng chỉ bao gồm các số 0, 1, 2
2 
5
1 1 0 0 2
6
1 1 1 0 0 2
=> 
0 0 1 1 2 
0 0 1 1 1 2
*/
void run2(){//O(n)
    int n; cin >> n;
    int a[n]; 
    int cnt[3] = {0};
    for(int i=0; i<n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i=0; i<3; i++){
        for(int j=0; j<cnt[i]; j++)
            cout << i << " ";
    }
    el;
}
//----------------------------------------------------------------
/**Cặp số có tổng bằng K 
2
4 4 
2 2 2 2
3 3 
1 2 3 
=> 6 1
*/
int a[1000001];
void run3(){//O(n)
    int n, k; cin >> n >> k;
    map<int, int> mp;
    f0(i, n){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0;
    for (int i=0; i<n; i++){
        ans += mp[k-a[i]];
        // tính chính nó 1 lần 
        if(a[i]*2==k)
            ans--;
    }
    cout << ans/2 << endl;
}
void run4(){//O(n^2)
    int n, k; cin >> n >> k;
    f0(i, n) cin >> a[i];
    ll ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] + a[j] == k)
                ++ans;
        }
    }
    cout << ans << endl;
}
int first_pos(int a[], int l, int r, int x){
    int res = -1;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m] == x) {
            res = m + 1;
            r = m - 1;//****
        }
        else if(a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return res;
}
int last_pos(int a[], int l, int r, int x){
    int res = -1;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m] == x) {
            res = m + 1;
            l = m + 1;//****
        }
        else if(a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return res;
}
void run(){//Tìm kiếm nhị phân 
    int n, k; cin >> n >> k;
    f0(i, n) cin >> a[i];
    sort(a, a+n);
    ll ans = 0;
    for(int i = 0; i<n-1; i++){
        //với mỗi a[i] tìm số lần xh của k-a[i], chỉ xét từ sau nó 
        int l = first_pos(a, i+1, n-1, k-a[i]);
        int r = last_pos(a, i+1, n-1, k-a[i]);
        if(l != -1) ans += r-l+1;
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    // run();
    int t; cin >> t;
    while(t--){
        run();
    }
    return 0;
}