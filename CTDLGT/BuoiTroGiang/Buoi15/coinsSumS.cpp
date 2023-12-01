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

/** Coin
 * Tính số cách không xét đến thứ tự để tạo ra số tiền x
 * bằng cách sử dụng số tiền có sẵn. 
 * Được quyền sử dụng 1 đồng tiền nhiều lần 
 * {2, 3, 5} s = 9
 * (2 2 5) (3 3 3) (2 2 2 3)
3 9
2 3 5
=> 3
3 2
2 3 5
=> 1
*/
int F[101][1000001];
int mod = 1e9+7;

void run(){
    int n, s; cin >> n >> s;
    int a[n+1];
    f1(i,n) cin >> a[i];
    for(int i=0; i<=n; i++){
        F[i][0] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            if(j >= a[i])
                F[i][j] = F[i][j-a[i]] + F[i-1][j]; //check thì thay + thành ||
                        //có chứa nó     k chứa nó
            else
                F[i][j] = F[i-1][j];
            F[i][j] %= mod;
        }
    }
    cout << F[n][s] << endl;
}
//----------------------------------------------------------------
//trong bài được sử dụng 1 tờ tiền nhiều lần thì bỏ vị trí đi cũng được 
int T[100001];
void run2(){
    int n, s; cin >> n >> s;
    int a[n+1];
    f1(i,n) cin >> a[i];
    T[0] = 1;
    //Cách 2: k quan tâm đứng trước
    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            if(j >= a[i])
                T[j] = T[j-a[i]] + T[j];
            T[j] %= mod;
        }
    }
    cout << T[s] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    // run();
    run2();
    return 0;
}