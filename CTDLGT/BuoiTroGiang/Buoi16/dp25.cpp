#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f2(j,m) for (int j = 1; j <= m; j++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/* Đếm số các phép Insert, Delete, Replace ít nhất thực hiện trên string1 để trở thành string2 
geek gesek
=>
*/
int F[105][105];
void run(){
    string s1,s2; cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    s1 = "0" + s1;
    s2 = "0" + s2;
    // Khởi tạo 
    //xâu 1 có i kí tự, xâu 2 có 0 kí tự thì mất i lần delete 
    for (int i=1; i<=n; i++) F[i][0] = i;
    //xâu 1 có 0 kí tự, xâu 2 có j kí tự thì mất j lần insert
    for (int j=1; j<=m; j++) F[0][j] = j;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if(s1[i] != s2[j])
                F[i][j] = min({F[i-1][j], F[i][j-1], F[i-1][j-1]}) + 1;
            else
                F[i][j] = F[i-1][j-1];
        }
    }
    cout << F[n][m] << endl;
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