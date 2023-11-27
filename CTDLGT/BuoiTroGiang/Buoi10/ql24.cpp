#include <bits/stdc++.h>
#define el cout << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Cho chữ cái c in hoa và số nguyên k. Hãy liệt kê tất cả các xâu 
 * có k ký tự khác nhau được tạo bởi các chữ cái tính từ A đến ký tự c.
 * Các ký tự được phép lặp lại nhưng không tính các xâu là hoán vị của 
 * xâu nào đó đã liệt kê trước đó 
 *
C 2
=>
AA
AB
AC
BA
BB
BC
CA
CB
CC 
*/
int n, k, a[100], x[100];
void in(){
    f1(i,k) cout << char(x[i] + 'A' - 1);
    el;
}
void ql(int i){
    for(int j=1; j<=n; j++){
        x[i] = j;
        if(i == k) in();
        else ql(i+1);
    }   
}
void run(){
    char c; cin >> c >> k;
    n = c - 'A' +1;
    ql(1);
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