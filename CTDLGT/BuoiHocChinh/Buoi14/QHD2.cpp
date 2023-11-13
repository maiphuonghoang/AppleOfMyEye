#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * 1 chiếc cầu thang có n bậc. Mỗi bước bạn được phép bước lên trên tối đa k bước 
 * Có bao nhiêu cách bước để đi hết cầu thang
 * F[i] = tổng xích ma (j=1->k) F[i-j]
7 3 
=> 44
4 2
=> 5
*/
int mod = 1e9+7;
void staircase(){
    int n, k; cin >> n >> k;
    ll F[100000] = {0};
    F[0] = 1;
    for (int i = 1; i <= n; i++){//duyệt bậc thang 1 tới bậc thang n
        for (int j = 1; j <= min(i, k); j++){//với mỗi bậc thang xét có thể đi bn bậc 
            if(i - j >= 0){
                F[i] += F[i-j];
                F[i] %= mod;
            }
        }
    }
    cout << F[n] << endl;
}
//-------------------------------------------------------------------
/** Dãy con tăng dài nhất LIS
 * Tìm dãy con (không nhất thiết các phần tử phải liên tiếp)
 * tăng chặt (ptu đứng sau > đứng trước) dài nhất của mảng a có n phần tử 
 * F[i]: độ dài dãy con tăng dài nhất kết thúc tại chỉ số i 
 * F[1] = 1
 * Với mỗi ptu ở chỉ số i xét tất cả ptu đứng trước nó 
 * nếu a[i] > a[j] có thể thêm vào dãy F[i] = F[j]max + 1 
 * O(n^2) n<= 10^4
*/
void LIS(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    int f[n];
    for (int i=0; i<n; i++){
        f[i] = 1;
        for (int j=0; j<i; j++){
            if(a[i] > a[j]){
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    //độ dài max 
    cout << *max_element(f, f+n) << endl;
}
/**
 * Tổng lớn nhất của dãy con tăng dần 
 * F[i]: tổng lớn nhất của dãy con tăng đàn kết thúc ở chỉ số i 
 * F[i] = a[i]
 * Với mỗi ptu ở chỉ số i xét tất cả ptu đứng trước nó 
 * nếu a[i] > a[j] thêm vào tổng F[i] = F[j]max + a[i] 
8
2 12 3 15 16 11 4
=> 93
1 101 2 3 100 4 5
=> 106 
*/
void sumLIS(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    ll f[n];
    for (int i=0; i<n; i++){
        f[i] = a[i];
        for (int j=0; j<i; j++){
            if(a[i] > a[j]){
                f[i] = max(f[i], f[j] + a[i]);
            }
        }
    }
    //độ dài max 
    cout << *max_element(f, f+n) << endl;
}
/**
 * Tổng không liền kề 
 * Tính tổng lớn nhất của dãy con trong mảng với điều kiện 
 * trong dãy con k có 2 phần tử liền kề nhau 
 * F[i] tổng không liền kề lớn nhất kết thúc ở chỉ số i 
7
314 514 148 451 896 589 296 
=> 1706
*/
void sumKhongLienKe(){
    int n; cin >> n;
    int a[n+1];
    for (int i=1; i<=n; i++) cin >> a[i];
    ll f[n + 1] = {0};
    f[1] = a[1];
    for (int i=2; i<=n; i++){
        f[i] = max(f[i-1], f[i-2] + a[i]);
        //f(i - 1) k có a[i], f[i-2] có a[i]
    }
    cout << f[n] << endl;
}
//----------------------------------------------------------------
/**
 * Ngân hàng có n tờ tiền có mệnh giá khác nhau được lưu vào mảng C[].
 * Tìm cách đổi số tiền là S sao cho số tờ tiền cần dùng là ít nhất.
 * Được sử dụng 1 mệnh giá không giới hạn số lần 
 * F(s) số lượng tờ tiền tối thiểu để tạo ra lượng tiền s
 * 1 3 4
 * F(s) = min(F(s-1)+1, F(s-3)+1, F(s-4)+1)
 * F(0) = 0 //k cần đồng xu nào cũng có lượng tiền là 0 
tờ tiền 1, 3, 4, sum = 10
s  0  1  2  3  4  5  6  7  8  9  10
f  0  1  2  1  1  2  2  2  2  3  3
f(7) = min (f(6), f(4), f(3))+1
*/
void coin(){//for each 
    int n, s; cin >> n >> s;
    int coin[n];

    for (int i=0; i<n; i++) cin >> coin[i];

    int f[100001] = {0};
    f[0] = 0;

    // Khi xét lượng tiền từ 0 tới s, xét qua các đồng xu và cập nhật 
    for (int i = 1; i<= s; i++){
        f[i] = 1e9;
        int cnt = 0;
        for (int c : coin){//for each thì mảng bắt đầu từ 0
            cnt++;
            if(i >= c){
                f[i] = min(f[i], f[i-c] + 1);
            }
        }
    }
    if(f[s] == 1e9) cout << "-1" << endl;
    else cout << f[s] << endl;
}
void coin2(){//for int 
    int n, s; cin >> n >> s;
    int coin[n];

    for (int i=1; i<=n; i++) cin >> coin[i];

    int f[s+1] = {0};
    f[0] = 0;

    // Khi xét lượng tiền từ 0 tới s, xét qua các đồng xu và cập nhật 
    for (int i = 1; i<= s; i++){
        f[i] = 1e9;
        int cnt = 0;
        for (int j = 1; j<=n; j++){
            cnt++;
            if(i >= coin[j]){
                f[i] = min(f[i], f[i-coin[j]] + 1);
            }
        }
    }
    if(f[s] == 1e9) cout << "-1" << endl;
    else cout << f[s] << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    coin2();
    return 0;
}