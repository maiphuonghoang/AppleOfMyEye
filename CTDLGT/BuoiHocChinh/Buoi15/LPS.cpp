#include <bits/stdc++.h>
using namespace std;
/** Xâu con đối xứng dài nhất 
 * F[i][j] true/false 
 * F[i][i] = 1
 * s[i] == s[j] && F[i+1][j-1]
 * Xét xâu có độ dài 1, 2,...n
 * Truy xuất thì dựa vào bảng và substring 
abccbxaabba
=> 4
2 5 bccb 8 11 abba 
*/
void LPS(){
    string s; cin >> s;
    int n = s.size();
    s = "@" + s; //để xét mảng từ 1 đến n 
    int F[n+1][n+1];
    memset(F, false, sizeof(F));
    int ans = 1;
    // base case: length = 1
    for(int i=1; i<=n; i++)
        F[i][i] = true;
    // xét tất cả chiều dài từ 1->n, sinh ra tất cả xâu con độ dài n 
    for (int len=2; len<=n; len++){
        // xét hết vị trí bắt đầu 
        for (int i=1; i<=n-len+1; i++){
            // chỉ số cuối là j
            // n - (n-len+1) + 1 = len
            int j = i+len-1; //từ i tới i+len-1 có độ dài len 
            if(len == 2)
                F[i][j] = (s[i] == s[j]);
            else
                F[i][j] = (s[i] == s[j]) && F[i+1][j-1];
            
            if(F[i][j]) ans = max(ans, len);
        } 
    }
    for (int i=1; i<=n;i++){
        for (int j=1; j<=n; j++){
            if(F[i][j]==1 && (j-i+1 == ans)){
                cout << i << " " << j << " " << s.substr(i, j-1) << " ";
            }
        }
    }
    cout << ans << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    LPS();
    return 0;
}