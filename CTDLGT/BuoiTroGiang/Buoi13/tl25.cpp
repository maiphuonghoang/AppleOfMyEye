#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input(a) f0(i,n) cin >> a[i]
#define output(a) f0(i,n) cout << a[i] << " "
using ll = long long;
using namespace std;

/** Xếp hàng
 * Có n người trong hàng đợi. Mỗi người cần t thời gian cần thiết để phục vụ.
 * 1 người sẽ thất vọng nếu thời gian anh ta chờ đợi nhiều hơn thời gian phục vụ.
 * Thời gian 1 người chờ là tổng thời gian tất cả những người đứng trong hàng đợi 
 * trước mặt anh ta được phục vụ. 
 * Nếu hoán đổi 1 số người trong hàng đợi thì có thể giảm số người thất vọng
 * Tìm ra con số tối đa mà những người k thất vọng có thể đạt được bằng cách 
 * hoán đổi những người trong hàng đợi  
 *
Để những người có thời gian phục vụ ít lên trước 
1  2  3  8  12 14
ok ok ok ok  x ok

7
4 3 17 4 5 14 20
=> 3
6
1 2 3 8 12 14
=> 5
*/

void run(){
    int n; cin >> n;
    int a[n]; input(a);
    sort(a, a+n);
    ll t = 0, cnt = 0; 
    for(int i=0; i<n; i++){
        if(a[i] >= t){
            cnt++; //phục vụ
            //thời gian chờ của ông đứng sau sẽ mất thêm
            t += a[i]; 
        }
    }
    cout << cnt << endl;
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