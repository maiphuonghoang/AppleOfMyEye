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

/** Tìm đường 
 * Di chuyển từ s đến t sao cho số lần đổi hướng k quá 2 lần.
 * Có thể di chuyển từ 1 ô sang 4 ô chung cạnh với ô hiện tại và k có vật cản 
9 6
**.*..
.**..T
.*..*.
.....*
...***
...*S.
*.....
****..
.....*
*/
int n, m, s1, s2, t1, t2;
char a[505][505];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int ok = 0;

void ql(int i, int j, int k_prev, int cnt){
    if(cnt > 3) return;
    if(i == t1 && j == t2){
        ok = 1;
        return;
    } 
    if(ok) return;  
    a[i][j] = '*';
    for(int k=0; k<4; k++){
        int i1 = i + dx[k], j1 = j + dy[k];
        if(i1>=1&&i1<=n&&j1>=1&&j1<=m&&a[i1][j1]!='*')
            if(k_prev == k)
                ql(i1, j1, k, cnt);
            else ql(i1, j1, k, cnt+1);
    }
    a[i][j] = '.';// mở khóa để có thể duyệt lại 
}

void run(){
    cin >> n >> m;
    f1(i, n)
        f1(j, m){
            cin >> a[i][j];
            if(a[i][j] == 'S'){
                s1 = i;
                s2 = j;
            }
            if(a[i][j] == 'T'){
                t1 = i;
                t2 = j;
            }
        }
    ql(s1, s2, -1, 0);
    ok? yes: no;
    
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