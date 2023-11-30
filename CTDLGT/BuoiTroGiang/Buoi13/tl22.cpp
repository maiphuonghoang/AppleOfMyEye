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

/** Tích của 3 số
 * Kiểm tra có thể viết N = a*b*c hay không,
 * trong đó a, b, c là 3 số nguyên dương >= 2 khác nhau 
5
11 NO
32 NO
18 NO
24 YES
12 NO

2^2.3^1 
2^1.3^2
=> ktm 
2^2.3^2
2^3.2^1
=> tm 
n = e1^p1.e2^p2.e3^p3.e4^p4
n = e1^p1.e2^p2.e3^p3
n = e1^p1.e2^p2
    p1 + p2 >= 4 là phân tích được 
n = e1^p1
    p1 >= 6
*/

int phanTich(int n){
    int e = 0, p = 0;   
    for(int i=2; i<sqrt(n); i++){
        if(n%i==0){
            e++;//số lượng thừa số nguyên tố  
            int mu = 0;
            //chia hết cho 1 số thì chia hết cỡ cho số đó 
            while(n%i == 0){
                n /= i;
                mu++;
            }
            p += mu;//tổng số mũ 
        }
    }
    if(n!=1){
        e++; p++;
    }
    if(e>=3) return 1;
    if(e>=2 && p>=4) return 1;
    if(e==1 && p>=6) return 1;
    return 0;
}
void run(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        phanTich(n)? yes : no;
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