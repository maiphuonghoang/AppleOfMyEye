#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 
using namespace std;

/*
5 5
2 4 3 1 3
4 3 4 1 3 
2 3 2 3 3
3 1 4 1 4
2 1 4 3 2
=> 
1 : 1 2 2 
2 : 1 1 1 1 1
3 : 1 4 4
4 : 1 2 3
*/
//Try: loang từ ô hiện tại sang tất cả các ô xung quanh chung đỉnh với nó có gtri x 
int dem = 0;// số lượng ô chung miền 
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, a[100][100];

void input(){
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
}
void Try(int i, int j, int x){
    dem++;
    a[i][j] = 1000;//đánh dấu ô đã được xét 
    for (int k=0; k<8; k++){
        int i1 = i + dx[k], j1 = j + dy[k];
        if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1] == x){
            Try(i1, j1, x);
        }
    }
}
void run(){
    input();
    map<int, vector<int>> mp;//danh sách các vùng có số x
    // duyệt từng ô trên bảng số 
    for(int i=1; i<=n; i++)
        for (int j=1; j<=m; j++){
            if(a[i][j] != 1000){
                int tmp = a[i][j];//lưu lại ô 
                dem = 0; //reset sau mỗi lần try 
                Try(i, j, tmp);
                mp[tmp].push_back(dem);
            }
        }
    for (auto it : mp){
        sort(it.second.begin(), it.second.end());
        cout << it.first << " : ";
        for (int x : it.second)
            cout << x << " ";
        el;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}