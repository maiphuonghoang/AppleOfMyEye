//Xâu Con Chung Dài Nhất 
#include <bits/stdc++.h>
using namespace std;
void longestCommonSubsequence(){
    string X, Y; cin >> X >> Y;
    int n = X.size(), m = Y.size();
    int F[n+1][m+1];
    for(int i = 0; i<=n; i++){
        for (int j = 0; j <= m; j++){
            if(i==0 || j==0) 
                F[i][j] = 0;
            else{
                if(X[i-1] == Y[j-1])
                    F[i][j] = F[i-1][j-1] + 1;
                else
                    F[i][j] = max(F[i-1][j], F[i][j-1]);
            }
        }
    }
    cout << F[n][m] << endl;
} 
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    longestCommonSubsequence();
    return 0;
}
