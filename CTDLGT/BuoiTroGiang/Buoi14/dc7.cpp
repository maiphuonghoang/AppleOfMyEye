#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input0(a) f0(i,n) cin >> a[i]
#define output0(a) f0(i,n) cout << a[i] << " "
#define input1(a) f1(i,n) cin >> a[i]
#define output1(a) f1(i,n) cout << a[i] << " "
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Floor
 * Cho mảng đã được sắp xếp A[] gồm n phần tử k có 2 phần tử giống nhau và số X
 * Tìm K=floor(X) là phần tử lớn nhất trong mảng A <= X
9 8
1 2 3 4 5 6 7 8 9
=> 8
*/
int floor(int a[], int n, int x){
    int l = 0, r = n-1, res = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid] <= x){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res; 
}
void run(){
    int n, x; cin >> n >> x;
    int a[n]; input0(a);
    cout << a[floor(a, n, x)];

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