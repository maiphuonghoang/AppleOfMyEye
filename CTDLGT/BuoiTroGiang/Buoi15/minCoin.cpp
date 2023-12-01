
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

/** Coin problem 
 * Đổi số tiền là S sao cho số tờ tiền cần dùng là ít nhất.
 * Được sử dụng 1 mệnh giá không giới hạn số lần 

K tính hoán vị trùng nhau / Tính hoán vị trùng nhau đều ok 
Được sử dụng a[i] nhiều lần 

3 10
4 5 8
=> 2
*/
/*
1 1 1000000000
1 2 1000000000
1 3 1000000000
1 4 1
1 5 1000000000
1 6 1000000000
1 7 1000000000
1 8 2
1 9 1000000000
1 10 1000000000
2 1 1000000000
2 2 1000000000
2 3 1000000000
2 4 1
2 5 1
2 6 1000000000
2 7 1000000000
2 8 2
2 9 2
2 10 2
3 1 1000000000
3 2 1000000000
3 3 1000000000
3 4 1
3 5 1
3 6 1000000000
3 7 1000000000
3 8 1
3 9 2
3 10 2
*/
int F[100001];
void run1(){
    int n, s; cin >> n >> s;
    int a[n+1];
    f1(i,n) cin >> a[i];
    for(int i=1; i<=s; i++){
        F[i] = 1e9;
    }
    F[0] = 0;
    // 3 2 5 
    //F[2][7] = {3 2 2} = 3
    //F[2][9] = 3 + 1 = 4
    //        = F[1][9] {3 3 3} = 3            
    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            if(j >= a[i])
                F[j] = min(F[j - a[i]] + 1, F[j]);
                        //có lấy nó         //k lấy nó thì vẫn giữ nguyên 
            //cout << i << " " << j << " " << F[j] << endl;
        }
    }
    if(F[s] == 1e9) cout << -1;
    else cout << F[s] << endl;
}
//----------------------------------------------------------------
void run(){
    int n, s; cin >> n >> s;
    int a[n+1];
    f1(i,n) cin >> a[i];
    for(int i=1; i<=s; i++){
        F[i] = 1e9;
    }
    F[0] = 0;
    for(int i=1; i<=s; i++){
        for(int j=1; j<=n; j++){
            if(i >= a[j])
                F[i] = min(F[i - a[j]] + 1, F[i]);
                        //có lấy nó         //k lấy nó thì vẫn giữ nguyên 
        }
    }
    if(F[s] == 1e9) cout << -1;
    else cout << F[s] << endl;
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