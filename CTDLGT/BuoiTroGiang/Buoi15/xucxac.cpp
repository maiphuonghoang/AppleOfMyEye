
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

/** Cho ngẫu nhiên số n. Hỏi rằng nếu được tung 1 con xúc xắc k giới hạn số lần 
 * và lấy tổng số chấm trên mặt xúc xắc cộng lại với nhau, hỏi có bn cách tung 
 * để tổng số chấm trong mọi lần tung xúc xắc bằng n
 * <=> Cầu thang, mỗi bước được bước 1...6 bước 
Có hoán vị, a[i] trùng nhau 
7
=> 63
*/
int mod = 1e9+7;
void run(){
    int n; cin >> n;
    int F[n+1] = {0};
    F[0] = 1;
    //sum ở bên ngoài ptu trong trường hợp được xét hoán vị nhiều lần 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=6; j++){
            if(i >= j)
                F[i] += F[i-j];
            F[i] %= mod;
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