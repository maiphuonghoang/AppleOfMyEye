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

/** Số may mắn
 * 1 số là số may mắn nếu biểu diễn thập phân của nó chỉ chứa 
 * các chữ số may mắn là 4 và 7.
 * Vd 47, 744, 4 là số may mắn
 *    5, 17, 467 k là số may mắn 
 * Tìm số may mắn bé nhất có tổng các chữ số = n 
 * sum = 4*x + 7*y
 * => max y & min x <=> nhiều số 7 thì số lượng chữ số là ít nhất  
16 => 4444
14 => 77 
11 => 47
*/

void run(){
    int sum; cin >> sum;
    int d4 = -1, d7 = -1;
    for(int d7=sum/7; d7>=0; d7--){
        if((sum-d7*7)%4 == 0){
            d4 = (sum - d7*7) / 4;
            break;
        }
    }
    if(d4 != -1){
        for(int i=0; i<d4; i++)
            cout << 4;
        for(int i=0; i<d7; i++)
            cout << 7;
    }else cout << -1;
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