#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input2(a, n, m) for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j]
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Count Island 1
 * Đếm số lượng miền số 1 trong ma trận
4 7 
0 1 1 0 1 1 0
1 1 1 1 1 1 1
1 0 0 0 0 1 1 
1 1 0 1 0 0 0 
=> 2
*/
int n, m, a[505][505];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void loang(int i, int j){
    a[i][j] = 0;
    for(int k=0; k<4; k++){
        int i1 = i+dx[k];
        int j1 = j+dy[k];
        if(i1>=1&&i1<=n&&j1>=1&&j1<=m&&a[i1][j1])
            loang(i1, j1);
    }
}
void run(){
    cin >> n >> m;
    input2(a, n, m);
    int cnt = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] == 1){
                cnt++;
                loang(i, j);
            }
        }
    }
    cout << cnt;
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