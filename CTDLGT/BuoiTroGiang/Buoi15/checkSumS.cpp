#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input(a) f0(i,n) cin >> a[i]
#define output(a) f0(i,n) cout << a[i] << " "
using ll = long long;
using namespace std;

/** Dãy con tổng S
 * Có thể tạo ra 1 tập con các ptu trong mảng có tổng bằng S k
8 92
69 16 82 170 31 24 45 112   
=> 1
*/
bool F[201][1001];
//F[i][j]: duyệt qua i phần tử có tạo ra tổng j không
void run(){
    int n, s; cin >> n >> s;
    int a[n+1];
    f1(i, n) cin >> a[i];
    /*
    a[1] = 2
    F[1][2] = true
    Do F[0][0] = true || F[0][2]
    a[4] = 5;
    F[4][5] = true
    F[4][5] = F[3][0] = true|| F[3][5]
    */
    for(int i=0; i<=n; i++){
        F[i][0] = true;
    }
    //Cách 1
    // i = 2, s = 9
    //F[2][9] = F[1][7] || F[1][9]
    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            if(j >= a[i]){
                F[i][j] = F[i-1][j-a[i]] || F[i-1][j];
            }
            else    
                F[i][j] = F[i-1][j];
        }
    }
    cout << F[n][s] << endl;
}
//----------------------------------------------------------------
int f[100001];
void run2(){
    int n, s; cin >> n >> s;
    int a[n+1];
    f1(i, n) cin >> a[i];
    f[0] = 1;
    //Cách 2: tài thời điểm tính F[2][9] mới chỉ có F[1][7] chứ chưa có F[2][7]
    //F[9] = F[7] || F[9]
    //i = 2, j = 9
    //i = 2, j = 8
    //i = 2, j = 7
    for(int i=1; i<=n; i++){
        for(int j=s; j>=1; j--)
            f[j] = f[j-a[i]] || f[j];
    }
    cout << f[s] << endl;
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