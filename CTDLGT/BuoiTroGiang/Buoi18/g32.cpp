#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Tìm các khu vực của các thành phần bị ngắt kết nối 
 * Đếm số lượng đỉnh trong thành phần liên thông 
10 10
###.#.#..#
.######...
###..##.#.
.##...###.
##....#..#
.#..###...
..####.##.
...##.....
..#...####
.#..##.##.
=> 1 1 8 1 11 1 17 9 1 1 
*/
int n, m;
char a[1005][1005];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push({i, j});
    a[i][j] = '#';
    int cnt = 0;
    while(!q.empty()){
        auto it = q.front(); q.pop();
        int i = it.first, j = it.second;
        cnt++;
        for (int k = 0; k < 4; k++){
            int i1 = i + dx[k], j1 = j + dy[k];
            if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]=='.'){
                q.push({i1, j1});
                a[i1][j1] = '#';
            }
        }
    }
    return cnt;
}
void run(){
    cin >> n >> m;
    f1(i, n) 
        f1(j, m) 
            cin >> a[i][j];
    f1(i, n) 
        f1(j, m)
            if(a[i][j] == '.')
                cout << bfs(i, j) << " ";     
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