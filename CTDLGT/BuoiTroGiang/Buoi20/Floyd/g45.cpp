#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Truy vấn đường đi (Floyd)
 * Tìm đường đi ngắn nhất giữa đỉnh X và đỉnh Y
5 6 
1 2 6 
1 3 7
2 4 8
3 4 9
3 5 1
4 5 2
3
1 5 
2 5 
4 3
=> 8 10 3
*/
int n, m;
int a[505][505];

void run(){
    cin >> n >> m;
    //Khởi tạo 
    f1(i, n)
        f1(j, n){
            if(i == j) a[i][j] = 0;//khoảng cách từ nó tới chính nó 
            else a[i][j] = 1e9;
        }
    // Nhập 
    f0(i, m){
        int x, y, z; cin >> x >> y >> z;
        a[x][y] = z;
        a[y][x] = z;
    }
    //Floyd 
    for (int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        cout << a[x][y] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}