#include <bits/stdc++.h>
using namespace std;
/*
4 6 
2 1 4 3 
3 3 4 2 
=> 8

0 0 0 0 0 0 0 
0 0 3 3 3 3 3
0 3 3 6 6 6 6
0 3 3 6 6 7 7
0 3 3 6 6 7 8
*/

void caiTui(){
    int n, S; cin >> n >> S;
    int w[n+1], v[n+1];
    for (int i=1; i<=n; i++) cin >> w[i];
    for (int i=1; i<=n; i++) cin >> v[i];
    int dp[n+1][S+1];
    memset(dp, 0, sizeof(dp));

    for (int i=1; i<=n; i++){
        for (int j=1; j<=S; j++){
            //Không lựa chọn đồ vật thứ i vào trong túi 
            dp[i][j] = dp[i-1][j];
            //Có thể đưa đồ vật thứ i vào trong túi
            if(j >= w[i]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j -w[i]] + v[i]);
            }
        }
    }
    for (int i=0; i<= n; i++){
        for (int j = 0; j<=S; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << dp[n][S];
    
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    caiTui();
    return 0;
}