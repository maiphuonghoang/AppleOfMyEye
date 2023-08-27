#include <bits/stdc++.h>
using namespace std;

/**
6 5 2
1 7 5 2 8 7
2 6 5
1 5 1
1 6 1 
2 6 4 
2 5 4
2 5 
2 4 
=> 5 23 21 18 24 17 
//tăng phần tử từ chỉ số 2 đến chỉ số 6 lên 5 đơn vị 
*/
using ll = long long;
const int maxn = 1e5 + 5;
ll a[maxn], l[maxn], r[maxn], val[maxn];
ll diff[maxn], query[maxn];
int n, m, k;
void prefix(){
    //m: số lượng thao tác
    //k số truy vấn 
    cin >> n >> m >> k;
    //nhập mảng 
    for (int i = 1; i <= n; i++) 
        cin >> a[i];

    //nhập thao tác 
    for (int i = 1; i <= m; i++) 
        cin >> l[i] >> r[i] >> val[i];

    //nhập truy vấn, mảng hiệu (=> cộng dồn) đếm mỗi truy vấn thực hiện bn lần 
    for (int i = 1; i <= k; i++){
        int x, y; cin >> x >> y;
        diff[x] ++; diff[y + 1] --;
    }
    //tính mảng cộng dồn của diff
    for (int i = 1; i <= m; i++){
        diff[i] += diff[i - 1];
        //query lưu mảng hiệu của các thao tác 
        query[l[i]] += diff[i] * val[i];//thao tác được thực hiện diff[i] lần 
        query[r[i] + 1] -= diff[i] * val[i];
    }
    for (int i = 1; i <= n; i++){
        query[i] += query[i-1];
        cout << a[i] + query[i] << " ";
    }
    
}
int main (){
    #ifndef ONLINE_JUDGE 
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prefix();
    cout.flush();
    fclose(stdout);
}



