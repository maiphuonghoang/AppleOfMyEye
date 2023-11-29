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

/** Cho xâu kí tự S chỉ bao gồm các kí tự in thường, hãy kiểm tra xem có thể 
 * sắp đặt lại các kí tự trong xâu sao cho k có 2 kí tự kề nhau nào giống nhau 
n lẻ được đặt tối đa n/2 + 1
n chẵn được đặt tối đa n/2
Công thức tổng quát : (n+1)/2  (n-1)/2+1
Chỉ cần thỏa mãn được ptu có tần xuất lớn nhất là các ptu khác thỏa mãn 

Bài trồng cây: Cách nhau d đơn vị (n-1)/d +1
aqeaaqwq
=> YES
aaaaa
*/

void run(){
    string s; cin >> s;
    int d[256] = {0};
    int max_fre = 0;
    for(char c: s){
        d[c]++;
        max_fre = max(max_fre, d[c]);
    }
    int n = s.length();
    if(max_fre <= (n+1)/2) yes;
    else no;
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