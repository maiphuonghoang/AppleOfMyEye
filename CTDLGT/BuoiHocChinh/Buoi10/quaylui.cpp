#include <bits/stdc++.h>
using namespace std;
/**
 * Liệt kê dãy con có tổng = k 
 * In các số theo chiều tăng dần 
3 
5 50
5 10 15 20 25
8 53
15 22 14 26 32 9 16 8
6 55
5 10 5 15 20 25
=>
5 10 15 20 
5 20 25
10 15 25

9 14 22 8
14 15 16 8
15 16 22

5 5 10 15 20
5 5 20 25
5 10 15 25
5 10 15 25
10 20 25
*/
int n, k, X[100], a[100], sum;
void TryDayConSumK(int i, int pos){
    for (int j = pos; j <= n; j++){//k duyệt trùng 
        X[i] = a[j];
        sum += a[j];
        if(sum == k){
            for (int l = 1; l <= i; l++)
                cout << X[l] << " ";
            cout << endl;
        }
        else{
            TryDayConSumK(i+1, j+1);
            cout << "Try("<< i <<"," << j+1 <<")"<<endl;
        }
        sum -= a[j];
    }
}
void runDayConSumK(){
    int t; cin >> t;
    while(t--){
        sum = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];

        sort(a+1, a+n);//in theo thứ tự từ điển 
        TryDayConSumK(1,1);
        cout << endl;
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    runDayConSumK();
    return 0;
}