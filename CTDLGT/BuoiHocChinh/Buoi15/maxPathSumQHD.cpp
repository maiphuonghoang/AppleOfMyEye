#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * Maximum path sum 
 * Cho A[n x m]. Bạn được phép đi xuống dưới, sang phải và đi xuống 
 * ô chéo dưới về bên phải. Khi đi qua ô (i,j) điểm nhận được là A[i, j].
 * Tìm đường đi từ ô (1,1) tới ô (n,m) sao cho tổng điểm là lớn nhất 
5 5
1 0 31 5 25
28 26 32 46 7
26 40 36 13 15
7 26 14 6 11
42 45 11 10 21 
=> 208
*/

int a[505][505];
ll F[505][505];
int n, m;
//khai báo ở ngoài để mấy ô khác có gtri 0
void path1(){
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];

    // đường nhỏ nhất trong 3 ô TỚI ô (i,j) + thêm nó  
    /*      |
        ___i,j
          /
    */
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            F[i][j] = max({F[i-1][j], F[i][j-1], F[i-1][j-1]}) + a[i][j];
    
    cout << F[n][m] << endl;
}
//----------------------------------------------------------------
/**
 * Cho A[n x n]. Tìm 1 đường đi từ dòng 1 tới dòng N sao cho các phần tử 
 * trên đường đi đó là lớn nhất có thể. Từ ô hiện tại chỉ có thể đi xuống
 * ô dưới bên trái, ô dưới bên phải hoặc ô dưới của ô hiện tại.
 * Tìm 1 đường đi có tổng các số trên đường đi là lớn nhất 
5 
5 1 8 6 7
6 0 0 3 7
3 4 1 5 3
9 8 9 2 2 
5 3 4 5 3 
=> 
dòng đầu tiên của bảng phương án giống bảng a
xây dựng từ dòng thứ 2 
tìm max ở dòng cuối của bảng phương án là kqua 
*/
void path2(){
    cin >> n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];

    // đường nhỏ nhất trong 3 ô TỚI ô (i,j) + thêm nó  
    /*    \  |  /
            i,j
    */
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            F[i][j] = max({F[i-1][j-1], F[i-1][j], F[i-1][j+1]}) + a[i][j];

    ll ans = 0;
    for (int i=1; i<=n; i++)
        ans = max(ans, F[n][i]);
    cout << ans << endl;
    
    cout << *max_element(F[n] + 1, F[n] + n + 1) << endl;//cách tìm max nữa s
}
/**
 * Cho A[n x n]. Tìm 1 đường đi từ cột 1 tới cột N sao cho các phần tử 
 * trên đường đi đó là lớn nhất có thể. Từ ô hiện tại chỉ có thể đi
 * sang phải, ô dưới bên phải hoặc ô trên bên phải của ô hiện tại.
 * Tìm 1 đường đi có tổng các số trên đường đi là lớn nhất 
 * Note: có các ptu có giá trị âm, lưu ý khi max 
5
2 -8 2 9 0
-5 6 6 -1 6
3 5 0 2 9 
9 -8 9 7 0 
-4 6 1 -2 0
=> 35
dòng đầu|cuối truy xuất đến những ô k hợp lệ => set số rất nhỏ 
CỘT đầu tiên của bảng phương án giống bảng a vì đi theo cột 
*/
void path3(){
    cin >> n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];

    // đường nhỏ nhất trong 3 ô TỚI ô (i,j) + thêm nó  
    /*  \    
     ___ i,j
        /
    */
    for (int i=1; i<=n; i++){
        F[0][i] = -1e18;
        F[n+1][i] = -1e18;
    }
    //cột đầu tiên của bảng phương án giống mảng ban đầu 
    for (int i=1; i<=n; i++)
        F[i][1] = a[i][1]; 

    for (int i=2; i<=n; i++)//i là cột 
        for (int j=1; j<=n; j++)//j là hàng 
            F[j][i] = max({F[j+1][i-1], F[j][i-1], F[j-1][i-1]}) + a[j][i];

    ll ans = -1e18;
    for (int i=1; i<=n; i++)
        ans = max(ans, F[i][n]);//cột cuối 
    cout << ans << endl;   
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    path3();
    return 0;
}