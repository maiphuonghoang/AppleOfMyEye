#include <bits/stdc++.h>

using namespace std;
using ll = long long;
/** MẢNG CỘNG DỒN 1 CHIỀU 
 * 1. Cho mảng số nguyên a gồm n phần tử, có q truy vấn, mỗi truy vấn là 2 số L, R
 * Hãy tính tổng các số từ chỉ số L tới R của mảng 
 * Input 
11 3
6 5 9 7 7 6 7 7 5 9 7
1 9
1 10 
6 8 
 * Output 62 69 19
*/
void run1(){
    int n, q; cin >> n >> q;
    int a[n];
    for (int &x : a) cin >> x;
    while(q--){
        int l, r; cin >> l >> r;
        ll tong = 0;
        //O(N) 
        for (int i=l; i<=r; i++)
            tong+=a[i];
        cout << tong << endl;
    }

    ll pre[n];
    pre[0] = a[0];
    for (int i=1; i<n; i++)
        pre[i] = pre[i-1] + a[i];
    while (q--){
        int l, r; cin >> l >> r;
        //O(1)
        if(l == 0) cout << pre[r];
        else cout << pre[r] - pre[l-1] << endl;
    }
} 
//----------------------------------------------------------------
/* MẢNG CỘNG DỒN 2 CHIỀU 
8 8
1 1 0 0 0 1 1 1
1 0 0 0 1 1 1 1
0 1 1 1 0 0 1 0 
1 1 1 1 0 1 1 0 
1 1 1 1 1 0 1 1 
1 0 0 1 0 1 0 1 
0 0 0 0 1 0 1 0
1 1 0 0 0 1 0 1 
3
2 3 1 7 
2 2 2 7
1 2 1 8 
*/
int a[1005][1005];
void run2(){
    int n, m; cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
    int q; cin >> q ;
    while(q--){
        int x1,x2,y1,y2; 
        cin >> x1 >> x2 >> y1>>y2;
        int tong = 0;
        //O(N^2)
        for (int i = x1; i<=x2; i++)
            for (int j = y1; j<=y2; j++)
                tong += a[i][j];
        cout << tong<< endl; 
    }
}
int pre[1005][1005];
void run2U(){
    int n, m; cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];
    int q; cin >> q ;
    while(q--){
        int x1,x2,y1,y2; 
        cin >> x1 >> x2 >> y1>>y2;
        int res = pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
        cout << res << endl; 
    }
}

void test3(){
    int n; cin >> n ;
    int a[n];
    for (int &x : a) cin >> x;

    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
        for (int j = i+1; j < n; j++)
            a[j]--;
        
    } 
    cout << sum << endl;
}
//----------------------------------------------------------------
/* MẢNG HIỆU 
7 3
8 5 8 9 7 6 9 
0 5 0
0 5 0
1 5 1 
*/
void run3(){
    int n, q; cin >> n >> q;
    int a[n];
    for (int &x : a) cin >> x;

    int d[n+2];
    d[0] = a[0];
    for (int i=1; i < n; i++) 
        d[i] = a[i] - a[i-1];

    while (q--){
        int l, r, k;
        cin >> l >> r >> k;
        d[l] += k;
        d[r+1] -= k;
    }
    //Xây dựng mảng cộng dồn của mảng d => mảng a 
    ll f[n];
    f[0] = d[0];
    for(int i=1; i<n; i++)
        f[i] = f[i-1] + d[i];
    for (int i=0; i < n; i++) cout << f[i] << ' '; 

}
int main (){
    #ifndef ONLINE_JUDGE 
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run3();
    cout.flush();
    fclose(stdout);
   
}
