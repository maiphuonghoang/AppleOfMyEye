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

/** Floyd
*/
int n, m;
int a[1005][1005];
//a[i][j]: khoảng cách đường đi ngắn nhất từ i tới j 

void Floyd(){
    // duyệt đỉnh trung gian 
    for (int k=1; k<=n; k++)
        //xét tất cả cặp cạnh có đi qua đỉnh trung gian 
        for(int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}
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
        int x, y, z; cin >> x >> y >>z;
        a[x][y] = z;
        a[y][x] = z;
    }
    Floyd();
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