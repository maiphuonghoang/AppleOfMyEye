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

/** Dãy số Bitonic
 * 1 dãy số được gọi là Bitonic nếu nó được chia thành 2, 
 * dãy đầu tăng dần và dãy tiếp theo giảm dần. Tìm tổng lớn nhất
 * dãy con Bitonic của dãy số.
 * A[] = {1,15,51,45,33,100,12,18,9}
 * 194 (1 15 51 100 18 9)
   ^ \
  /   \
 /     \
/      V
        giảm từ trái qua phải 
   ^ ^
  /   \
 /     \
/       \
        tăng từ phải qua trái 
Dãy con tăng dài nhất từ tría qua phải và từ phải qua trái 

8
7 8 8 19 3 6 2 15
=> 49
5
1 2 3 4 5
*/

void run(){
    int n; cin >> n;
    int a[n+1], F[n+1], G[n+1];//với mỗi đỉnh 
    f1(i,n) cin >> a[i];
    //dãy con tăng từ trái qua phải
    for(int i=1; i<=n; i++){
        F[i] = a[i];
        for(int j=1; j<=i; j++){
            if(a[j] < a[i])
                F[i] = max(F[i], F[j] + a[i]);
        }
    }
    //dãy con tăng từ phải qua trái 
    for(int i=n; i>=1; i--){
        G[i] = a[i];
        for(int j=n; j>i; j--){
            if(a[j] < a[i])
                G[i] = max(G[i], G[j] + a[i]);
        }
    }
    int res = 0;
    for(int i=1; i<=n; i++){
        res = max(res, F[i] + G[i] - a[i]);
    }
    cout << res << endl;
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