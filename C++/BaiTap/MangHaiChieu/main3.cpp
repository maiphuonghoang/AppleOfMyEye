#include <bits/stdc++.h>
using namespace std;

/**Quay ma trận theo chiều kim đồng hồ
3 3 
1 2 3
4 5 6
7 8 9 
=>
4 1 2 
7 5 3
8 9 6
pre = 4;
cur = 1;
pre = 1;

2 2 
1 2 5 6
=> 5 1 6 2
*/
void quayChieuKimDongHo(){
    int n, m; cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];    
    int h1 = 0, h2 = n-1, c1 = 0, c2 = m-1;

    while (h1 < h2 && c1 < c2){
        //đưa ptu ngay dưới ptu đầu lên làm ptu đầu tiên 
        int pre = a[h1+1][c1];
        //xây dựng dòng đầu tiên 
        for (int i=c1; i<=c2; i++){
            int cur = a[h1][i];
            a[h1][i] = pre;
            //gán pre = cur, gtri ptu là pre 
            pre = cur;//cho các bước sau dịch mỗi ptu sang 
        }
        h1++;
        //xây dựng cột bên phải 
        for (int i=h1; i<=h2; i++){
            int cur = a[i][c2];
            a[i][c2] = pre;
            pre = cur;
        }
        c2--;
        if(h1<=h2){
            //xây dựng dòng cuối cùng 
            for (int i=c2; i>=c1; i--){
                int cur = a[h2][i];
                a[h2][i] = pre;
                pre = cur;
            }   
            h2--;         
        }  
        if(c1<=c2){
            //xây dựng cột bên trái  
            for (int i=h2; i>=h1; i--){
                int cur = a[i][c1];
                a[i][c1] = pre;
                pre = cur;
            }   
            c1++;         
        }   
    } 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
//----------------------------------------------------------------
/**Đưa ra số các giá trị giống nhau ở tất cả các hàng 
4
2 3 2 3 
1 2 3 2
2 6 2 3
5 2 5 3
=> Kết quả là 2 tương ứng với số 2,3 xuất hiện ở tất cả các hàng 
Đánh dấu những ptu xh ở hàng 1 mp[2]=1, mp[3]=1
sang hàng 2 chỉ xét những ptu map = 1 ở hàng 1 rồi gán mp[2]=2, mp[3]=2
sang hàng 3 chỉ xét những ptu map = 2 ở hàng 2 rồi gán mp[2]=3, mp[3]=3
*/
void giaTriXhTatCaDong(){
    int n; cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];   
    
    map<int, int> mp;
    //những ptu dòng đầu có tần xuất là 1
    for (int i = 0; i < n; i++)
        mp[a[0][i]] = 1;

    //duyệt từ dòng 2 tới dòng cuối 
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++)
            if(mp[a[i][j]] == i)
                mp[a[i][j]]++;
    int cnt = 0;
    for (auto it: mp) 
        if(it.second == n)
            cnt ++;
    cout << cnt << endl;
}
//----------------------------------------------------------------
/**Ma trận a chỉ gồm 0 và 1. Ta gọi mỗi miền của ma trận a là nhóm các số 1 
 * được bao quanh bởi các số 0. Tìm số miền của ma trận
5 5 
1 1 0 0 0
0 1 0 0 1
1 0 0 1 1
0 0 0 0 0
1 0 1 1 0
=> 4  
2 ô 1 được liên kết với nhau nếu chung đỉnh 
gọi đệ quy để loang ra tất cả những ô 1 xung quanh đánh dấu là 0 
(0,0) (0,1) (1,1) (2,0)
(1,4) (2,3) (2,4)
(4,0)
(4,2) (4,3)
Số lượng đảo là số lần gọi đệ quy 
*/
int n, m , a[105][105];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
void dfs(int i, int j){
    cout << "(" << i << "," << j << ") " << endl;
    a[i][j] = 0;
    //xét 1 trong 8 ô xung quanh của a[i][j]
    for (int k = 0; k < 8; k++){
        int imoi = dx[k] + i;
        int jmoi = dy[k] + j;
        //chỉ số dòng phải nằm từ 0 đến n-1, chỉ số cột từ 0 tới m-1; và phải có đường đi 
        if (imoi>=0 && imoi<n && jmoi>=0 && jmoi< m && a[imoi][jmoi]) //check ô xq có đường đi k 
            dfs(imoi, jmoi);
    }
}
void countIsland(){
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];  

    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(a[i][j] == 1){//đây là 1 miền 
                cnt++;
                dfs(i, j);
            }     
    cout << cnt << endl;
}
//----------------------------------------------------------------
/** Ma trận a chỉ gồm ký tự O, X. Hãy thay thêd các miền bao quanh O bằng X.
 * 1 miền các ký tự O bị bao quanh bởi kí tự X nếu các kí tự X xuất hiện ở 
 * phía dưới, trên, trái, phải các kí tự O
6 6 
O O O X X X
X X X O O O
X O X O X X
O X X X X O
O O O O X X
X X X X X O
=> 
(1,1) (1,2) (1,3)
(2,6) (2,5) (2,4) (3,4)
(4,1)
(5,1) (5,2) (5,3) (5,4)
(4,6)
(6,6)
O O O X X X
X X X O O O
X X X O X X
O X X X X O
O O O O X X
X X X X X O
Duyệt 4 biên, ô O sẽ loang ra tất cả các ô O khác kề với ô này 
Sau đó ptu nào trên mảng vẫn là O (các ô ở biên k loang tới)
chứng tỏ đã bị bao quanh bởi X
Còn những ptu bị ở  biên loang đến k bị bao quanh bởi X
*/
char c[100][100];
pair<int, int> path[4] = {{-1,0}, {0,-1}, {0,1},{1,0}};
void ff(int i, int j){
    cout << "(" << i << "," << j << ") " << endl;
    c[i][j] = '*';
    for (int k = 0; k < 4; k++){
        int ike = i + path[k].first;
        int jke = j + path[k].second;
        if (ike>=1 && ike<=n && jke>=1 && jke<= m && c[ike][jke] == 'O') 
            ff(ike, jke);
    }
}
void thayTheXO(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> c[i][j];
    
    //duyệt hàng 1 tới hàng n
    for (int i = 1; i <= n; i++){
        //các ptu trên cột 1 và cột m là chữ O
        if(c[i][1] == 'O') ff(i,1);
        if(c[i][m] == 'O') ff(i,m);
    }
    //duyệt cột 1 tới cột m 
    for (int j = 1; j <= m; j++){
        //các ptu trên cột 1 và cột m là chữ O
        if(c[1][j] == 'O') ff(1,j);
        if(c[n][j] == 'O') ff(n,j);
    }

    //duyệt cả mảng, khác kí tự * thì đều là X
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(c[i][j] != '*')
                cout << "X ";
            else 
                cout << "O ";
        }
        cout << endl;
    }

}
//----------------------------------------------------------------
/**Ma trận a chỉ gồm các số 0 và 1. Tìm cấp của ma trận vuông con lớn nhất 
 * có các phần tử đều = 1
6 5
0 1 1 0 1
1 1 0 1 0
0 1 1 1 0
1 1 1 1 0
1 1 1 1 1
0 0 0 0 0 
=> 3 
Xét 3 ô xung quanh 
(i-1, j-1) (i-1, j)
(i, j-1)    (i, j)
để chọn ô dp[i,j] nhỏ nhất 
*/
void maxSquare(){
    int n,m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j]; 
    
    int dp[n][m];//hàng đầu tiên và cột đầu tiên là kqua giống với ma trận ban đầu 
    for (int i = 0; i < n; i++)
        dp[i][0] = a[i][0];
    for (int j = 0; j < m; j++) {
            dp[0][j] = a[0][j];
        }
    for (int i = 1; i < n; i++) 
        for (int j = 1; j < m; j++)
            if(a[i][j])
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]))+1;
            else
                dp[i][j] = 0;
    //tìm cỡ lớn nhất trong dp[]
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res = max(res, dp[i][j]);
    cout << res << endl;
}
//----------------------------------------------------------------
/**Ma trận a chỉ gồm các số 0 và 1. Hãy tìm hình chữ nhật lớn nhất 
 * có các phần tử đều bằng 1 
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
=> 8 
*/
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    thayTheXO();
    return 0;
}
