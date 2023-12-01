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

/** Gấp đôi dãy số
 * 1 dãy số tự nhiên bắt đầu từ con số 1 và thực hiện n-1 phép biến đổi 
 * gấp đôi dãy số như sau: Với dãy số A hiện tại, dãy số mới có dạng A,x,A
 * trong đó x là số tự nhiên bé nhất chưa xuất hiện trong A
 * VD với 3 bước biến đổi ta có [1] [1 2 1] [1 2 1 3 1 2 1] [1 2 1 3 1 2 1]4[1 2 1 3 1 2 1]
 * Xác định số thứ k trong dãy số cuối cùng 
 * 
[1]
[1] 2 [1]                               vị trí trung tâm của bố = 2^1 = 2 
[1 2* 1] 3 [1 2 1]                      vị trí trung tâm của ông = 2^2 = 4 
[1 2* 1 3 1 2 1] 4 [1 2** 1 3 1 2 1]    vị trí trung tâm của cụ = 2^(4-1) = 8 
10 cụ = 2 cụ
2 cụ = 2 ông 
2 ông = 2 bố    bố x bố = ông 
vị trí trung tâm của bố                 con x con = bố 

[1 2 1 3 1 2 1 4 1 2 1 3* 1 2 1] 5 [1 2 1 3 1 2 1 4 1 2 1 3* 1 2 1]   2^(5-1) = 16
(5, 28) = (5, 12)
        = (4, 12)
        = (4, 4)
        = (3, 4)  trung tâm lần lặp t3 ở vị trí 2^(3-1) = 4
        => trung tâm = 3
*/
int tinh(int n, int k){
    ll x = pow(2, n-1);
    //vị trí cần tìm trùng với vị trí trung tâm 
    if(k==x) return n;

    //nếu nằm bên phải >
    if(k > x) return tinh(n-1, k-x);

    //nếu nằm bên trái 
    return tinh(n-1, k);
}

void run(){
    int n; ll k;
    cin >> n >> k;
    cout << tinh(n, k) << endl;
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