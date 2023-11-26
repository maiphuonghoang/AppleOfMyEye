#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;

/** Xâu nhị phân thuận nghịch 
 * Liệt kê các xâu nhị phân thuận nghịch có độ dài n theo thứ tự từ điển
 * Lấy 1 nửa rồi reverse nửa còn lại 
 * Sinh xâu nhị phân thuận nghịch có độ dài n/2
 * n Lẻ: 10  10|0|01 sinh ra 1 nửa rồi ở giữa chèn vào 0 1
 *           10|1|01
4
=>
0000
0110
1001
1111
*/
int n, x[100], ok;
void sinh(){
    int i = n/2;
    while(i>=1 && x[i]){
        x[i] = 0;
        i--;
    }
    if(!i) ok = 0;
    x[i] = 1;
}
void run(){
    cin >> n;
    if(n%2==0){
        ok = 1;
        while(ok){
            for(int i=1; i<=n/2; i++)
                cout << x[i];
            //lật ngược 
            for(int i=n/2; i>=1; i--)
                cout << x[i];
            el; 
            sinh();
        }
    }else{
        ok = 1;
        while(ok){
            for(int u=0; u<=1; u++){
                for(int i=1; i<=n/2; i++)
                    cout << x[i];
                cout << u;
                //lật ngược 
                for(int i=n/2; i>=1; i--)
                    cout << x[i];
                sinh();
            }
            el; 
        }
    }
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