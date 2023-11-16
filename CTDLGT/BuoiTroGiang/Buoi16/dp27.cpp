#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f2(j,m) for (int j = 1; j <= m; j++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/* Bạn được cung cấp 1 số nguyên n. Trên mỗi bước có thể trừ 1 trong các chữ số khỏi số.
Cần thực hiện bao nhiêu bước để số đó = 0
27 => 5 
*/
// Đệ quy không nhớ từ dưới lên 
int tinh1(int n){
    if(n==0) return 0;
    int m = n;
    int res = 1e9;
    // duyệt qua tất cả các chữ số của n
    while(m){
        int r = m%10;
        if(r != 0)
            res = min(res, tinh1(n-r) + 1);
        m /= 10;
    }
    return res;
}
void run1(){
    int n; cin >> n;
    cout << tinh1(n) << endl;
}
//-----------------------------------------------
// Đệ quy có nhớ từ dưới lên 
int F[100001];
int tinh2(int n){
    if(n==0) return 0;
    if(F[n] != 0) return F[n];
    int m = n;
    int res = 1e9;
    // duyệt qua tất cả các chữ số của n
    while(m){
        int r = m%10;
        if(r != 0)
            res = min(res, tinh2(n-r) + 1);
        m /= 10;
    }
    F[n] = res;//ghi nó lại 
    return F[n];
}
void run2(){
    int n; cin >> n;
    cout << tinh2(n) << endl;
}
//----------------------------------------------------------------
// Đệ quy có nhớ từ trên xuống dưới 
void run3(){
    int n; cin >> n;
    for(int i =1; i <=n; i++){
        int m = i;
        F[i] = 1e9;
        while(m){ 
            int r = m%10;
            if(r != 0)
                F[i] = min(F[i], F[i-r] + 1);
            m /= 10;
        }
    }
    cout << F[n] << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run3();
    run2();
    run1();
    return 0;
}