#include <bits/stdc++.h>
using namespace std;
/** Đặt n con hậu vào bàn cờ nxn
8
=> 92
*/
int n, X[100], cot[100], cheo1[100], cheo2[100], cnt = 0;
//X1 X2...Xn
//X1 = y : Con hậu hàng 1 đặt ở cột y 
void Try(int i){
    for(int j=1; j<=n; j++){
        //lựa chọn cột j để mình đặt con hậu ở hàng thứ i
        if(cot[j]==0 && cheo1[i-j+n]==0 && cheo2[i+j-1]==0){
            X[i] = j;
            cot[j] = cheo1[i-j+n] = cheo2[i+j-1] = 1;//đánh dấu đã đc dùng 
            if(i == n){
                for(int i=1; i<=n; i++)
                    cout << "Con hau hang " << i << " nam o cot " << X[i] << endl; 
                cout << endl;
                cnt++;
            }
            else{
                Try(i+1);
            }
            cot[j] = cheo1[i-j+n] = cheo2[i+j-1] = 0;
        }

    }
}
void run(){
    cin >> n;
    Try(1);
    cout << cnt << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}