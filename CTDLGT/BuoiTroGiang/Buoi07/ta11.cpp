#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Sắp xếp các hàng của ma trận 
 * Cho ma trận vuông, sắp xếp các phần tử của từng hàng 
 * của ma trận theo thứ tự tăng dần 
3
2 7 6 
1 2 3 
9 8 1 
=>
2 6 7 
1 2 3
1 8 9
*/
void runHang(){
    int n; cin >> n;
    int a[n][n];
    for(int i=0; i<n; i++){
        //a[i] là 1 cái mảng 
        for(int &x : a[i])
            cin >> x;
    }
    for(int i=0; i<n; i++){
        sort(a[i], a[i] + n);
        for(int j=0; j<n; j++)
            cout << a[i][j] << " ";
        el;
    }
}
//----------------------------------------------------------------
/** Sắp xếp các cột của ma trận 
 * Cho ma trận vuông, sắp xếp các phần tử của từng cột 
 * của ma trận theo thứ tự tăng dần
nhap a[][]
chuyen vi a => aT[][]
sort tung hang cua aT[][]
in ra chuyen vi cua aT[][]
Mẹo:

3
1 2 3
5 5 2 
1 4 7  
=>
1 2 3 
1 4 2
5 5 7

Nhập và lưu 
1 5 1
2 5 4
3 2 7
*/
void runCot(){
    int n; cin >> n;
    int a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //nhập luôn vào a[j][i]
            cin >> a[j][i];
        }
    }
    for(int i=0; i<n; i++){
        sort(a[i], a[i] + n);
        for(int j=0; j<n; j++)
            cout << a[j][i] << " ";
        el;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    runCot();
    return 0;
}