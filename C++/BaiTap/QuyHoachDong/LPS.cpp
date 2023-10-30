// Xâu con đối xứng dài nhất 
#include <bits/stdc++.h>
using namespace std;
/**
abbcaac
1 1 0 0 0 0 0 
0 1 0 0 0 0 0
0 0 1 0 0 1 0
0 0 0 1 1 0 0
0 0 0 0 1 0 0
0 0 0 0 0 1 0
0 0 0 0 0 0 1
4
*/
void longestPalindromeSubstring(){
    string s; cin >> s;
    int n = s.size();

    s += "x";//để xét từ chỉ số 1
    bool F[n+1][n+1];
    memset(F, false, sizeof(F));

    //xâu con có độ dài là 1 
    for (int i = 1; i <= n; ++i) 
        F[i][i] = true;
    
    int ans = 1;
    //xét các xâu con có độ dài từ 2 cho tới n 
    for (int len = 2; len <= n; len++){
        for (int i = 1; i <= n-len+1; i++){//chỉ số bắt đầu
            int j = i+len-1;//chỉ số kết thúc 
            if(len == 2 && s[i] == s[j])
                F[i][j] = true;
            else{//len > 2
                F[i][j] = F[i+1][j-1] && (s[i] == s[j]);
            }

            if(F[i][j]) {
                ans = max(ans, len);
                cout << "ans = "<< ans<< " len = "<< len << endl;
            }
        }
    }
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n;j++)
            cout << F[i][j] << " ";
        cout << endl;
    }
    cout << ans << endl;

}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    longestPalindromeSubstring();
    return 0;
}