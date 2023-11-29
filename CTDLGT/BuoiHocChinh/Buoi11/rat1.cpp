#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
using ll = long long;
using namespace std;

/** Con chuột di chuyển từ ô (1,1) tới ô (n,n)
 * Chỉ được di chuyển xuống dưới hoặc sang phải và 
 * ô đó có giá trị là 1.
 * Liệt kê các cách đi theo thứ tự từ điển 
Chuột chỉ đi sang phải và xuống dưới nên k quay lại được như bài rat2
4
1 1 0 1
1 1 1 1
1 0 1 1
1 1 1 1 
=>
DDDRRR
DRRDDR
DRRDRD
DRRRDD
RDRDDR
RDRDRD
RDRRDD
*/
int a[100][100], n, check = 0;
string s;

void input(){
    cin >> n;
    f1(i,n) 
        f1(j,n) cin >> a[i][j];
}
//Thử đi vào ô (i,j)
void Try1(int i, int j){
    if(i == n && j == n){
        check = 1;
        cout << s << endl;
    }
    //thử đi sang phải hoặc xuống dưới
    //chọn down đi trước
    if(i+1<=n && a[i+1][j])//nằm trong mảng và có đường đi
    {
        a[i+1][j] = 0;
        s += "D";
        Try1(i+1, j);
        //Thử xong rồi thì backtrack 
        a[i+1][j] = 1;
        s.pop_back();

    }
    if(j+1<=n && a[i][j+1])
    {
        a[i][j+1] = 0;
        s += "R";
        Try1(i, j+1);
        a[i][j+1] = 1;
        s.pop_back();
    }
    
}
void run1(){
    input();
    Try1(1, 1);
    if(check == 0) cout << -1;
}
//----------------------------------------------------------------
int dx[2] = {0,1};
int dy[2] = {1,0};
string path = "RD";
vector<string> v;
void Try2(int i, int j){
    if(i == n && j == n){
        check = 1;
        v.push_back(s);
    }
    for(int k=0; k<2; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1>=1 && i1 <=n && j1>=1 && j1<=n && a[i1][j1]){
            a[i1][j1] = 0;
            s += path[k];
            Try2(i1,j1);
            //backtrack
            a[i1][j1] = 1;
            s.pop_back();
        }
    }
}
void run2(){
    input();
    Try2(1, 1);
    sort(v.begin(),v.end());
    for(string x : v)
        cout << x << endl;
    if(check == 0) cout << -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run2();
    return 0;
}