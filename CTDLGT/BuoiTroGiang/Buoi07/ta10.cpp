#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input0(a, n, m) for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j]
#define output0(a, n, m) for (int i = 0; i < n; i++){for (int j = 0; j < m; j++) cout << a[i][j]; el;} 
#define input1(a, n, m) for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j]
#define output1(a, n, m) for (int i = 1; i <= n; i++){for (int j = 1; j <= m; j++) cout << a[i][j]; el;} 
using ll = long long;
using namespace std;
int mod = 1e9+7;
/**
 * Đếm các phần tử là số nguyên tố trên đường chéo chính và phụ 
 * Mỗi số nguyên tố chỉ được đếm 1 lần => set 
3
1 2 3
4 5 6
7 8 9
=> 3
*/
int ngto(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return 0; 
    }
    return n>1;
}
void run(){
    int n; cin >> n;
    int a[n][n];
    input0(a, n, n);

    set<int> se;
    for(int i=0; i<n; i++)
        if(ngto(a[i][i]))
            se.insert(a[i][i]);
    for(int i=0; i<n; i++)
        if(ngto(a[i][n-1-i]))
            se.insert(a[i][n-1-i]);
            
    cout << se.size() << endl;
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