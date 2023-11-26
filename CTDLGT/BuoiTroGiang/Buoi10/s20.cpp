#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;

/** Xâu nhị phân đối xứng chẵn 
 * Liệt kê các xâu nhị phân thuận nghịch có độ dài chẵn theo thứ tự từ điển 
 * với chiều dài k quá n kí tự 
 * 2 < n < 30
4
00
0000
0110
1001
11
1111
*/
int x[100], ok;
void sinh(int n){
    int i = n;
    while(i>=1 && x[i]){
        x[i] = 0;
        i--;
    }
    if(i == 0) ok = 0;
    else x[i] = 1;
}
void run(){
    int k; cin >> k;
    vector<string> v;
    for(int n=1; n<= k/2; n++){
        ok = 1;
        while(ok){
            string s = "";
            for(int i=1; i<=n; i++)
                s += to_string(x[i]);
            //lật ngược 
            for(int i=n; i>=1; i--)
                s += to_string(x[i]);
            v.push_back(s);
            sinh(n);
        }
    }
    sort(v.begin(), v.end());
    for(string s : v) cout << s << endl;
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