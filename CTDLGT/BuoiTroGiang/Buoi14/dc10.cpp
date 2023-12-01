#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input0(a) f0(i,n) cin >> a[i]
#define output0(a) f0(i,n) cout << a[i] << " "; el
#define input1(a) f1(i,n) cin >> a[i]
#define output1(a) f1(i,n) cout << a[i] << " "; el
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Đếm số 0
 * Cho mảng a gồm n phần tử chỉ bao gồm các số 0 và 1
 * Các số 0 được đặt trước các số 1. Đếm các số 0
Tìm vị trí số 1 đầu tiên 

6 
0 0 1 1 1 1 
=> 2
*/
int firstPos(int a[], int n){
    int l=0, r=n-1, res=-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid] == 1){
            res = mid;
            r = mid -1;
        }else
            l = mid +1;
    }
    return res;
}
void run(){
    int n; cin >> n;
    int a[n]; input0(a); 
    cout << firstPos(a, n);
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