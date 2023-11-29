#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;

/**Ghi nhầm số  
 * 5 thành 6 hoặc ngược lại
 * Tính tổng nhỏ nhất và lớn nhất mà Tèo có thể nhận được 
891 746
1637 1636
*/
//chuyển từ kí tự này sang kí tự khác 
ll xuly(ll n, char p, char q){
    string s = to_string(n);
    for(int i = 0; i < s.length(); i++)
        if(s[i] == p)
            s[i] = q;
    return stoll(s);
}
void run(){
    ll a, b; cin >> a >> b;
    cout << xuly(a, '5', '6') + xuly(a, '5', '6') << endl;
    cout << xuly(a, '6', '5') + xuly(a, '6', '5') << endl;
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