
#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/**
 * Cho mê cung A nxn. 1 con chuột xuất phát từ ô (s, t) và di chuyển tới ô (u, v)
 * Xác định số bước đi tối thiểu để con chuột có thể di chuyển từ ô (s, t) tới (u, v)
 * hoặc xác định rằng k thể tìm được đường tới ô (u, v)
 * Con chuột chỉ có thể di chuyển từ ô hiện tại sang các ô chung đỉnh 
 * Số bước đến đỉnh i = số bước đến bố i + 1
10 
9 6 9 3
1 1 0 1 1 1 1 0 0 1
0 0 1 0 0 1 0 1 0 1
1 1 1 1 0 0 0 1 1 0 
1 0 0 0 1 0 0 0 1 1 
1 0 1 0 0 1 0 1 1 0 
0 0 1 1 0 1 0 0 0 0 
1 1 0 1 0 1 1 0 0 0 
0 0 0 1 1 0 1 1 0 1 
1 0 1 0 0 1 0 0 1 1 
0 1 1 1 1 0 1 0 1 1 
=> 3
*/

int n, m, s1, s2, t1, t2;
int a[1005][1005];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*
Đường đi quân mã 
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
*/ 

int bfs(){
    queue<pair<pair<int,int>, int>> q;
    q.push({{s1, s2}, 0});
    a[s1][s2] = 0;
    while(!q.empty()){
        auto it = q.front(); q.pop();
        int i = it.first.first;
        int j = it.first.second;
        int d = it.second;
        // Đến điểm cần đến rồi
        if(i==t1 && j==t2)
            return d;

        for (int k = 0; k < 8; k++){
            int i1 = i + dx[k], j1 = j + dy[k];
            if(i1>=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1]){
                q.push({{i1, j1}, d+1});
                a[i1][j1] = 0;
            }
        }
    }
    return -1;//k đi đến 
}
void run(){
    cin >> n >> s1 >> s2 >> t1 >> t2;
    f1(i, n) f1(j, n) cin >> a[i][j];
    cout << bfs();
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