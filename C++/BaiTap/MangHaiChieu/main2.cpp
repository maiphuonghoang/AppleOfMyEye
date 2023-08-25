#include <bits/stdc++.h>
using namespace std;

/** Đi xuống / Chéo phải / Chéo trái  
4 6
10 10 2  0  20 4
1  0  0  30 2  5
0  10 4  0  2  0
1  0  2  20 0  4
=> 74
20 30 4 20
Đi dọc 
*/
void maximumPathSum(){
    int n, m; cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++){
            if(j==0)
                a[i][j] += max(a[i-1][j], a[i-1][j+1]); 
            else if(j==m-1)
                a[i][j] += max(a[i-1][j-1], a[i-1][j]); 
            else 
                a[i][j] += max(max(a[i-1][j-1], a[i-1][j]), a[i-1][j+1]); 
        }
    cout << *max_element(a[n-1], a[n-1]+m)<<endl;
    int res = INT_MIN;
    for (int i = 0; i < m; i++)
        res = max(a[n-1][i], res);
    cout << res;
} 
//----------------------------------------------------------------
/**Tìm đường đi với tổng nhỏ nhất từ ô (1,1) tới ô (m,n)
 * Chỉ được di chuyển xuống dưới hoặc sang phải 
2 3
1 2 3
4 5 6
Đi ngang  
*/
void minimumPathSum(){
    int n, m; cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int dp[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            //ô đầu 
            if(i==0&&j==0) 
                dp[i][j] = a[i][j];
            //cột đầu 
            else if(j==0)
                dp[i][j] = dp[i-1][j] + a[i][j];
            //dòng đầu 
            else if(i==0)
                dp[i][j] = dp[i][j-1] + a[i][j];
            else
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];
        }
    cout << dp[n-1][m-1] << endl;

}
//----------------------------------------------------------------
/**
4
9 -2 -8 0
-6 -2 0 9
4 -5 6 1
1 3 4 9
*/
int major[402][402]={0}, minor[402][402] ={0};
void cheoChinhcheoPhuMaTranVuongCon(){
    int n; cin >> n ;
    int a[n+1][n+1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    //đường chéo chính 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if(i==1||j==1) 
                major[i][j] = a[i][j];
            else 
                major[i][j] = a[i][j] + major[i-1][j-1];
    //đường chéo phụ 
    for (int i = 1; i <= n; i++)
        //chạy từ phải sang 
        for (int j = n; j >=1; j--)
            if(i==1||j==n) 
                minor[i][j] = a[i][j];
            else 
                minor[i][j] = a[i][j] + minor[i-1][j+1];    
    
    long long ans = -1e18;
    for (int i = n; i >=1; i--){
        for (int j = n; j >=1; j--){
            //cỡ lớn nhất có thể của ma trận vuông 
            int tmp = min(i,j);
            int hang = i - tmp;
            int cot = j - tmp;
            for (int k = 0; k< min(i,j); k++){
                long long hieu = 0ll + major[i][j] - major[hang+k][cot+k] 
                                - (minor[i][cot+k+1] - minor[hang+k][j+1]);
                ans = max(ans, hieu);
            }
        }
    }
    cout << ans << endl;
}
//----------------------------------------------------------------
/** a[i][j] = 1, thay tất cả các phần tử của hàng i, cột j bởi 1
2
2 3 
0 0 0
0 0 1
3 4
1 0 0 1
0 0 1 0 
0 0 0 0
=>
0 0 1 
1 1 1

1 1 1 1
1 1 1 1
1 0 1 1
*/
void bienDoiNhiPhan(){
    int t; cin >> t;
    while (t--){       
        int n, m; cin >> n >> m;
        int a[n][m], b[n][m]; 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                cin >> a[i][j];    
                b[i][j] = a[i][j];
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if(a[i][j]){
                    //duyệt các cột của hàng i
                    for (int k = 0; k < m; k++)
                        b[i][k] = 1;
                    //duyệt các hàng của cột j
                    for (int k = 0; k < n; k++)
                        b[k][j] = 1;
                }      
            }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                cout << b[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
}
//----------------------------------------------------------------
/** Ma trận a có n hàng và 3 cột chỉ gồm 0,1
 * Đếm có bn hàng mà số lượng số 1 nhiều hơn số lượng số 0
3
1 1 0
1 1 1
1 0 0
=> 2
*/
void count(){
    int n, m = 3; cin >> n;
    int a[n][m]; 
    int ans = 0;
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = 0; j < m; j++){
            cin >> a[i][j];    
            //tổng các phần tử trên hàng i
            sum += a[i][j];
        }
        if(sum >= 2) ++ans; 
    }
    cout << ans << endl;   
}
//----------------------------------------------------------------
/**Ma trận vuông cấp n, các phần tử đã được sắp xếp theo hàng và theo cột. 
 * Tìm phần tử nhỏ nhất thứ k của ma trận 
4 7 
10 20 30 40
15 25 35 45
24 29 37 48
32 33 39 50
*/
void phanThuNhoNhatThuK(){
    int n, k; cin >> n >> k;
    int a[n*n];
    for (int i= 0; i<n*n; i++) 
        cin >> a[i];
    sort(a, a+n*n);
    k--;
    cout << a[k] << endl;    
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    phanThuNhoNhatThuK();
    return 0;
}