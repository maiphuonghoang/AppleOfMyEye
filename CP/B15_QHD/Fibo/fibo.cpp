#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;

/*

*/

int fibo1(int n){//top down 
    if(n==1 || n==2) return 1;
    return fibo1(n-1) + fibo1(n-2);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int f[maxn];
void fibo2(){
    int n;
    f[1] = 1; f[2] = 1;
    for (int i=1; i<=n; i++)
        f[i+2] = f[i] + f[i+1]; //bottom up 
    // hoặc
    for (int i=3; i<=n; i++)
        f[i] = f[i-1] + f[i-2];
    cout << f[n];
    //hoặc 
    int f1 = 1, f2 = 1, f;
    for (int i=3; i<=n; i++){
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    cout << f;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int fiboDp(int n){
    if(n == 1 || n == 2) 
        return 1;
    if(f[n] != -1) 
        return f[n];
    return fiboDp(n-1) + fiboDp(n-2);
}
void fiboDp(){
    int n;
    for (int i=1; i<=n; i++){
        f[i] = -1;
    }
    cout << f[n];

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CP\\input.txt", "r", stdin);
    #endif
    
    return 0;
}