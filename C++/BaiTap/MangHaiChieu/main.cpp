#include <bits/stdc++.h>
using namespace std;
/**
 * Liệt kê các số nguyên tố trong ma trận theo thứ tự xuất hiện, in ra 1 lần
1
3 3
1 7 8 
2 3 3 
7 5 2
=> 7 2 3 5
*/
bool isPrime(int n){
    for (int i=2; i<=sqrt(n); i++)
        if(n%i == 0) 
            return false;
    return n>1;
}
void showPrime(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        int a[500][500];
        for (int i=0; i< n; i++)
            for (int j=0; j< m; j++)
                cin >> a[i][j];
        map<int, int> mp; 
        for (int i=0; i< n; i++)
            for (int j=0; j< m; j++){
                if(isPrime(a[i][j]) && mp[a[i][j]] == 0){
                    cout << a[i][j] <<" ";
                    mp[a[i][j]] = 1;
                }
            }
        cout << endl;
    
    }

}
//----------------------------------------------------------------
/**Tìm phần tử lớn nhất trong mâ trận và liệt kê các vị trí xuất hiện của nó
3 4
1 2 8 3
2 3 8 8 
1 5 2 3  
=> max_val: 8
A[1][3]
A[2][3]
A[2][4]
*/
void posMax(){
    int n, m; cin >> n >> m;
    int a[500][500];
    int max_val = INT_MIN;
    for (int i=0; i< n; i++)
        for (int j=0; j< m; j++){
            cin >> a[i][j];
            // if(a[i][j] > max_val) 
            //     max_val = a[i][j];
            max_val = max(a[i][j], max_val);
        }
    cout << "max_val: " << max_val << endl; 
    for (int i=0; i< n; i++)
        for (int j=0; j< m; j++)
            if(a[i][j] == max_val)
                cout <<"A["<< i + 1 <<"]["<<j + 1<<"] "<< endl;
        
}
//----------------------------------------------------------------
/**Tìm hàng có tổng phần tử lớn nhất 
4 4
1 2 3 4 
2 3 4 9 
1 2 8 6
8 4 1 5 
=> 18
2 4 
*/
void sumRowMax(){
    int n, m; cin >> n >> m;
    int a[500][500];
    long long ans = INT_MIN;
    vector<int> row;//lưu các hàng có tổng lớn nhất 
    for (int i=0; i< n; i++){
        long long sum = 0;
        for (int j=0; j< m; j++){
            cin >> a[i][j];
            sum += a[i][j];
        }    
        if(sum > ans){
            ans = sum;
            //xóa tất cả các hàng trong vector 
            row.clear();
            row.push_back(i);
        }else if(sum == ans)
            row.push_back(i);
    }
    cout << ans << endl;
    for (int x : row) cout << x+1 << " ";

}
/**Tìm cột có nhiều số Fibo nhất, cùng số lượng thì in ra cột có tổng các số Fibo lớn nhất 
4 4
1 2 3 5
2 2 5 8
10 1 2 3
21 13 3 3   
=> 4
5 8 3 3
*/
set<long long> fibo;
void initFibo(){
    long long f[93];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < 93; i++)
        f[i] = f[i-1] + f[i-2];
    for (int i = 0; i < 93; i++)
        fibo.insert(f[i]);
}
void countSumFibo(){
    initFibo();
    int n, m; cin >> n >> m;
    long long a[500][500];
    for (int i=0; i< n; i++)
        for (int j=0; j< m; j++)
            cin >> a[i][j];  

    int ans = -1, cot;
    long long sum = 0;
    for (int i=0; i< m; i++){
        long long tmp = 0;
        int dem = 0;
        for (int j=0; j< n; j++)
            if(fibo.count(a[j][i]) == 1){
                dem++;
                tmp += a[j][i];
            }
        if(dem > ans){
            cot = i;
            ans = dem;
            sum = tmp;
        }
        else if(dem == ans){
           if(sum < tmp){
                cot = i;
                sum = tmp;
           }
        }    
    }
    cout << cot + 1<<endl;
    for (int i = 0; i<n; i++)
        if(fibo.count(a[i][cot])==1)
            cout << a[i][cot] << " ";
} 
//----------------------------------------------------------------
/**Tổng các phần tử thuộc tam giác dưới của ma trận vuông 
3 
1 2 3 
4 5 6 
7 8 9   
*/
void sumTamGiac(){
    int n; cin >> n;
    long long a[500][500];
    for (int i=0; i< n; i++)
        for (int j=0; j< n; j++)
            cin >> a[i][j];
    long long sum = 0;
    //tam giác dưới 
    for (int i=0; i< n; i++)
        for (int j=0; j<=i; j++)
            sum += a[i][j]; 
    cout << sum << endl;  
    //tam giác trên 
    for (int i=0; i< n; i++)
        for (int j=i; j<n; j++)
            cout << a[i][j] << " " ; 
}
//----------------------------------------------------------------
/**Thay thế phần tử của ma trận bằng tổng 8 phần tử ở 
 * các ô xung quanh cùng cạnh với nó 
3 3
1 2 3
4 5 6
7 8 9
=>
12 21 16 
27 45 33
24 39 28
Thay ptu 5 = 1+2+3+4+5+6+7+8+9 = 45
*/
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
//i + dx[0] & j + dy[0]
void thayTheTong8(){
    int n, m; cin >> n >> m;
    int a[500][500];
    for (int i=0; i< n; i++)
        for (int j=0; j< m; j++)
            cin >> a[i][j];
    
    int res[500][500];
    for (int i=0; i< n; i++){
        for (int j=0; j< m; j++){
            int sum = a[i][j];
            for (int k=0; k< 8; k++){
                int imoi = i + dx[k];
                int jmoi = j + dy[k];
                //check chỉ số mới có nằm trong ma trận k 
                if(imoi>=0&&imoi<n &&jmoi>=0&&jmoi<m)
                    sum+= a[imoi][jmoi];              
            }
            res[i][j] = sum;
        }
    }
    for (int i=0; i< n; i++){
        for (int j=0; j< m; j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}
//----------------------------------------------------------------
/**Biên của ma trận
 * Cho ma trận vuông a[n][n]. Hãy in các phần tử thuộc vùng biên 
4 
1 2 3 4
5 6 7 8 
1 2 3 4
5 6 7 8 
=>
1 2 3 4 
5     8
1     4
5 6 7 8
*/
void boundary(){
    int n; cin >> n;
    long long a[500][500];
    for (int i=0; i< n; i++)
        for (int j=0; j< n; j++)
            cin >> a[i][j];    
    for (int i=0; i< n; i++){
        for (int j=0; j< n; j++)
            if(i==0||i == n-1||j==0||j == n-1)
                cout << a[i][j] << " ";
            else cout << "  ";
        cout << endl;
    }
}
/**In ma trận hình con rắn
10-20-30-40
          |  
50-60-70-80
 |
27-29-47-48
          |
32-33-39-50
hàng chẵn in từ trái qua phải, hàng lẻ in từ phải qua trái 
*/
void snake(){
    int n; cin >> n;
    long long a[500][500];
    for (int i=0; i< n; i++)
        for (int j=0; j< n; j++)
            cin >> a[i][j];    
    for (int i=0; i< n; i++){
        if(i%2==0){
            for (int j=0; j< n; j++)
                cout << a[i][j] << " ";
        }else{
            for (int j=n-1; j>=0; j--)
                cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

/**Ma trận xoắn ốc thuận 
10-20-30-40
          |  
50-60-70 80
 |     |  |
27 29-47 48
 |        |
32-33-39-50
*/
void xoanOc(){
    int n, m; cin >> n >> m;
    int a[500][500];
    for (int i=0; i< n; i++)
        for (int j=0; j< m; j++)
            cin >> a[i][j];    
    
    int h1=0, h2=n-1, c1=0, c2=m-1;
    while(h1<=h2 && c1<=c2){
        //xây dựng dòng trên cùng 
        for (int i = c1; i<=c2; i++)
            cout << a[h1][i] << " ";
        ++h1;
        //xây dựng cột bên phải 
        for (int i = h1; i<=h2; i++)
            cout << a[i][c2] << " ";
        --c2;
        if(h1 <= h2){
            //xây dựng dòng dưới cùng 
            for (int i = c2; i>=c1; i--)
                cout << a[h2][i] << " ";
            --h2;
        }
        if(c1 <= c2){
            //xây dựng cột bên trái 
            for (int i = h2; i>=h1; i--)
                cout << a[i][c1] << " ";
            ++c1;
        }

    }  
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    xoanOc();
    return 0;
}
