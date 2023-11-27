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
AA AB AC BA BB BC CA CB CC 
11 12 13 21 22 23 31 32 33

D 3
=>
111 112 113 114 121 122 123 124 131 132 133 134 141 142 143 144 
211 212 213 214 221 222 223 224 231 232 233 234 241 242 243 244
311 312 313 314 321 322 323 324 331 332 333 334 341 342 343 344 
411 412 413 414 421 422 423 424 431 432 433 434 441 442 443 444

*/
int n, k, a[100], x[100], ok;
void in(){
    f1(i,k) cout << char(x[i] + 'A' - 1);
    el;
}
void sinh(){
    int i = k;
    while(i>=1 && x[i] == n){
        i--;
    }
    if(i==0) ok = 0;
    else{
        x[i]++;
        for(int j=i+1; j<=k; j++)
            x[j] = 1;
    }
}
void run(){
    char c; cin >> c >> k;
    n = c - 'A' +1;
    for(int i=1; i<=k; i++) x[i] = 1;
    ok = 1;
    while(ok){
        for(int i=1; i<=k; i++)
            cout << x[i];
        el;
        sinh();
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