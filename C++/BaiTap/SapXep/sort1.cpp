#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define nhap_mang for(int &x : a) cin >> x
#define xuat_mang for(int x : a) cout << x << " "
using ll = long long;
using namespace std;

/** Thuật toán đổi chỗ trực tiếp O(n^2)
4
5 7 3 2 
=>
Buoc 1: 2 7 5 3 
Buoc 2: 2 3 7 5
Buoc 3: 2 3 5 7

i j
5 7 3 2
3 7 5 2
  i j
2 7 5 3
2 5 7 3 
    i j
2 3 7 5
2 3 5 7
*/
void run1(){
    int n; cin >> n;
    int a[n];
    nhap_mang;
    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i+1; j <n; j++){
            if(a[i] > a[j])
                swap(a[i], a[j]);          
        }
        cout << "Buoc " << i + 1 << ": "; 
        xuat_mang; el;
    }
}
//----------------------------------------------------------------
/** Thuật toán sắp xếp chọn O(n^2)
4
5 7 3 2
=> 
Buoc 1: 2 7 3 5 
Buoc 2: 2 3 7 5
Buoc 3: 2 3 5 7

2 5 7 3 min=2
2 | 7 3 5
2   3 7 5 min = 3
2 3 | 5 7 min = 5
*/
void run2(){
    int n; cin >> n;
    int a[n];
    nhap_mang;
    for(int i = 0; i < n - 1; i++){
        int min_pos = i;
        for(int j = i+1; j <n; j++){
            if(a[j] < a[min_pos])
                min_pos = j;    
        }
        swap(a[i], a[min_pos]);
        cout << "Buoc " << i + 1 << ": "; 
        xuat_mang; el;
    }
}
//----------------------------------------------------------------
/** Thuật toán sắp xếp chèn O(n^2)
4
5 7 3 2
=> 
Buoc 0: 5 
Buoc 1: 5 7
Buoc 2: 3 5 7
Buoc 3: 2 3 5 7

5 | 7 3 2
5 7 | 3 2
3 5 7 | 2
2 3 5 7 |
*/
void run3(){
    int n; cin >> n;
    int a[n];
    nhap_mang;
    for(int i = 0; i < n; i++){
        int x = a[i], pos = i-1;
        while(pos >= 0 && a[pos] > x){
            a[pos+1] = a[pos];
            --pos;
        }
        a[pos+1] = x;
        cout << "Buoc " << i << ": "; 
        for(int j=0; j<=i; j++)
            cout << a[j] << " ";
        el;
    }
}
//----------------------------------------------------------------
/** Thuật toán sắp xếp nổi bọt O(n^2)
4
5 3 2 7
=> 
Buoc 1: 3 2 5 7 
Buoc 2: 2 3 5 7
*/
void run4(){
    int n; cin >> n;
    int a[n];
    nhap_mang;
    for(int i = 0; i < n - 1; i++){
        bool ok = false;
        for(int j = 0; j <n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);   
                ok = true;
            }
        }
        if(ok){
            cout << "Buoc " << i + 1 << ": "; 
            xuat_mang; el;
        }else break;   
    }
}
//----------------------------------------------------------------
/**Tìm kiếm nhị phân 
5 3
1 2 3 4 5
1
=> YES 
*/
bool binarySearch(int a[], int n, int x){
    int l = 0, r = n-1;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m] == x) return true;
        else if(a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}
void run5(){
    int n, x; cin >> n >> x;
    int a[n];
    nhap_mang;
    binarySearch(a, n, x) ? yes : no;
}
//----------------------------------------------------------------
/** Vị trí đầu tiên, cuối cùng 
 * Cho mảng số nguyên đã được sắp xếp tăng dần và số nguyên x. 
 * Tìm vị trí xuất hiện đầu tiên của x trong mảng 
2
5 3
1 2 3 3 3
5 4
1 1 2 5 6 
=> 3 5
   -1 -1 

*/
int dautien(int a[], int n, int x){
    int res = -1, l = 0, r = n - 1;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m] == x) {
            res = m + 1;
            r = m - 1;//****
        }
        else if(a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return res;
}
int cuoicung(int a[], int n, int x){
    int res = -1, l = 0, r = n - 1;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m] == x) {
            res = m + 1;
            l = m + 1;//*****
        }
        else if(a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return res;    
}
void run6(){
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        int a[n];
        nhap_mang;
        cout << dautien(a, n, x) << " ";
        cout << cuoicung(a, n, x) << " ";
        el;
    }
}
//----------------------------------------------------------------
void run(){
    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}