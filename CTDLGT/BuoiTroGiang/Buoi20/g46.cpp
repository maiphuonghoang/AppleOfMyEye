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

/** Tìm 1 đường đi từ ô (1,1) tới ô (n,m) sao cho chi phí nhỏ nhất.
 * Tại mỗi ô, được phép đi sang trái, sang phải, lên trên, xuống dưới 
6 7
0 3 6 0 5 9 1 
6 5 4 4 0 7 6
4 0 2 1 5 6 1 
2 7 7 3 3 1 6 
4 4 9 6 9 7 2 
3 6 4 4 1 9 2
=> 28
*/
#define pip pair<int, pair<int, int>>
int n, m, a[505][505], d[505][505];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void Dijkstra(){
    f1(i, n)
        f1(j, m)
            d[i][j] = 1e9;
    d[1][1] = a[1][1];
    priority_queue<pip, vector<pip>, greater<pip>> q;
    q.push({0, {1, 1}});
    while(!q.empty()){
        auto it = q.top(); q.pop();
        int i = it.second.first, j = it.second.second; 
        int len = it.first;
        if(len > d[i][j]) continue;//phiên bản k tốt 
        for(int k = 0; k<4; k++){
            int i1 = i + dx[k], j1 = j + dy[k];{}
            if(d[i1][j1] > d[i][j] + a[i1][j1]){
                d[i1][j1] = d[i][j] + a[i1][j1];
                q.push({d[i1][j1], {i1, j1}});
            }
        }
    }
    cout << d[n][m];
}
void run(){
    cin >> n >> m;
    f1(i, n)
        f1(j, m)
            cin >> a[i][j];                  
    Dijkstra();  
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