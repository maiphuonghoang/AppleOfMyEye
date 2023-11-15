#include <bits/stdc++.h>
#define el cout << "\n";
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f2(j,m) for (int j = 1; j <= m; j++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/* Tìm số lượng ít nhất các số < n mà có tổng bình phương = n 
20 => 2
19 = 3^2 + 3^2 + 1^2 => 3

2 = 1^2 + 1
3 = 1^2 + 2
4 = 1^2 + 3
4 = 2^2 + 0
5 = 1^2 + 4
5 = 2^2 + 1
6 = 1^2 + 5
6 = 2^2 + 2
7 = 1^2 + 6
7 = 2^2 + 3
8 = 1^2 + 7
8 = 2^2 + 4
9 = 1^2 + 8
9 = 2^2 + 5
9 = 3^2 + 0
10 = 1^2 + 9
10 = 2^2 + 6
10 = 3^2 + 1
11 = 1^2 + 10
11 = 2^2 + 7
11 = 3^2 + 2
12 = 1^2 + 11
12 = 2^2 + 8
12 = 3^2 + 3
13 = 1^2 + 12
13 = 2^2 + 9
13 = 3^2 + 4
14 = 1^2 + 13
14 = 2^2 + 10
14 = 3^2 + 5
15 = 1^2 + 14
15 = 2^2 + 11
15 = 3^2 + 6
16 = 1^2 + 15
16 = 2^2 + 12
16 = 3^2 + 7
16 = 4^2 + 0
17 = 1^2 + 16
17 = 2^2 + 13
17 = 3^2 + 8
17 = 4^2 + 1
18 = 1^2 + 17
18 = 2^2 + 14
18 = 3^2 + 9
18 = 4^2 + 2
19 = 1^2 + 18
19 = 2^2 + 15
19 = 3^2 + 10
19 = 4^2 + 3
20 = 1^2 + 19
20 = 2^2 + 16
20 = 3^2 + 11
20 = 4^2 + 4
*/

void run(){
    int n; cin >> n;
    int F[n+1] = {0};
    F[1] = 1;
    for (int i=2; i<=n; i++){
        F[i] = i;//trong trường hợp tệ nhất là i số 1 cộng với nhau 
        for (int j=1; j<=sqrt(i); j++){
            F[i] = min(F[i], 1 + F[i-j*j]); 
            // hoặc 
            // F[i] = min(F[i], F[j*j] + F[i-j*j]); 
            cout << i << " = " << j << "^2 + " << i-j*j << endl;  
        }
    }
    cout << F[n] << endl;
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