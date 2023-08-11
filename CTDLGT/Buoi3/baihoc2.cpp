#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
//----------------------------------------------------------------
/**
3 3 1
3 5
1 4
2 4
3 5
=> 2 
3 3 2
3 5
1 4
2 4
3 5
1 3
=> 2 1
*/
int a[200005];
int f[200005];
void PhaTraSua(){
    //n: số lượng thao tác thêm đường
    //k: lượng đường tối thiểu 1 cốc trà sữa đạt chuẩn
    //q: số truy vấn kết quả 
    int n, k, q; cin >> n >> k >> q;
    for (int i = 1; i <= n; i++){
        int l,r; cin >> l >> r;
        a[l] += 1;
        a[r+1] -= 1;
    }
    for (int i = 1; i <= 200000; i++)
        a[i] += a[i-1];
    int dem = 0;

    //f[i]: số cốc trà sữa từ thứ 1 tới i 
    for (int i = 1; i <= 200000; i++){
        if(a[i] >= k) dem++;
        f[i] = dem;
    }
    while(q--){
        int l, r; cin >> l >> r;
        cout << f[r] - f[l-1] << endl;
    }
}


int main (){
    #ifndef ONLINE_JUDGE 
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    PhaTraSua();
    cout.flush();
    fclose(stdout);
}
