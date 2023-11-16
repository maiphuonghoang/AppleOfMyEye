#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f2(j,m) for (int j = 1; j <= m; j++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/*
1 
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
*/
int F[101][101];
void run(){
    int n; cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            if(j == 1 || j == i) F[i][j] = 1;
            else 
                F[i][j] = F[i-1][j-1] + F[i-1][j];
            cout << F[i][j] << " ";
        }
        el;
    }
}
//--------------------------------------
// Đệ quy thuần, chạy rất lâu 
int tinh(int i, int j){
    if(i==j || j==1) return 1;
    return tinh(i-1, j) + tinh(i-1, j-1);
}
int tinh2(int i, int j){
    if(i==j || j==1) return 1;
    if(F[i][j] != 0) 
        return F[i][j];
    return F[i][j] = tinh2(i-1, j) + tinh2(i-1, j-1);
}
void run2(){
    int n; cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++)
            cout << tinh2(i, j) << " ";
        el;
    }

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run2();
    return 0;
}