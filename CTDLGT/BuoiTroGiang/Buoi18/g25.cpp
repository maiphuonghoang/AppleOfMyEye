#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f2(j,m) for (int j = 1; j <= m; j++)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Bạn được đưa cho 1 bản đồ của 1 tòa nhà va nhiệm vụ của bạn là đếm số lượng 
 * phòng của tòa nhà đó. Kích thước của bản đồ là m x n hình vuông và mỗi hình vuông là 
 * sàn hoặc tường. Bạn có thể đi sang trái, phải, lên và xuống qua các ô sàn 
=> Đếm số thành phần liên thông 
6 6 
..###.
...#..
#..#..
.##.#.
######
.#.##.
*/
int n, m;
char a[1005][1005];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void loang(int i, int j){
    a[i][j] = '#';
    for (int k=0; k<4; k++){
        int i1 = i + dx[k], j1 = j+dy[k];
        if(i1>=1&&i1<=n&&j1>=1&&j1<=m&&a[i1][j1]=='.')
            loang(i1, j1);
    }
}

void run(){
    cin >> n >> m;
    f1(i, n)
        f1(j, m)
            cin >> a[i][j];
    int cnt = 0;
    f1(i,n)
        f1(j, m){
            if(a[i][j] == '.'){
                cnt++;
                loang(i, j);
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