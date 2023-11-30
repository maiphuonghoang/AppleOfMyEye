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

/** Taxi
 * Có n nhóm học sinh, mỗi nhóm có từ 1 đến 4 người. Các nhóm đi 
 * bằng taxi, mỗi xe chở được tối đa 4 người.
 * Tìm số lượng taxi tối thiểu để có thể chở hết n nhóm họ sinh này,
 * biết rằng những học sinh ở cùng 1 nhóm sẽ đi cùng 1 taxi 
6
2 1 3 1 2 2 
=> 3
2 3 
=> 2
*/
/*
taxi = 4
taxi = 3 1 
taxi = 2 2
taxi = 2 1 1 
taxi = 3
taxi = 1 1 1 1 
*/
void run(){
    int n; cin >> n;
    int d[5] = {0};
    int a[n]; 
    //đếm xem bn nhóm có n người 
    f0(i,n){
        cin >> a[i];
        d[a[i]]++;
    }
    int res = 0;
    res += d[4];

    int res31 = min(d[3], d[1]);
    d[1] -= res31;
    d[3] -= res31;
    res += res31;

    int res22 = d[2]/2;
    d[2] = d[2] % 2;
    res += res22;

    if(d[2]){
        res++;
        d[1] -= min(d[1], 2); // 1(2) 3(1)
    } 

    res += d[3];

    int res1111 = d[1]/4;
    if(d[1]%4!=0) res1111++;
    res += res1111;

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