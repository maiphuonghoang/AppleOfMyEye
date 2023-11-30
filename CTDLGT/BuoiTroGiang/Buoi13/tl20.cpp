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

/** Cặp số
 * Gọi 1 cặp số (x,y) là tương tự nhau nếu chúng có cùng tính chất chẵn lẻ 
 * hoặc có abs(x-y) = 1 (1 chẵn 1 lẻ). Kiểm tra có thể chia n phần tử của mảng a thành 
 * các cặp sao cho mỗi cặp đều tương tự nhau 
 * 1=<N<=100
6 
78 17 17 42 11 43
=> YES
8
78 17 17 40 11 43 1 4
=> NO
*/

void run(){
    int n; cin >> n;
    vector<int> chan, le;
    for(int i=0; i<n;i++){
        int x; cin >> x;
        if(x%2==0) chan.push_back(x);
        else le.push_back(x);
    }
    if(chan.size() % 2 == 0) yes;
    else{
        // tìm 1 số trong chan, 1 số trong le tm abs(a-b) = 1
        for(int x : chan)
            for(int y : le)
                if(abs(x-y) == 1){
                    cout << x << " " << y << endl;
        cout << "chay else";
                    yes;
                    return;
                }    
        no;      
    }
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