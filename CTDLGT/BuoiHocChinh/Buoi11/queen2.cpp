#include <bits/stdc++.h>
using namespace std;
/** Đặt n con hậu vào bàn cờ nxn sao cho k có quân hậu nào là ăn nhau
 * và số điểm đặt được là lớn nhất
8
12 29 80 91 56 46 97 13
54 88 27 84 85 9 32 77
48 80 88 74 30 77 38 98 
6 82 20 95 7 86 12 43
100 82 15 7 95 9 5 84
51 40 65 98 86 38 30 63
96 78 98 76 33 11 2 58 
33 51 35 68 62 87 67 39 
=> 653
*/
int n, X[100], a[100][100], cot[100], cheo1[100], cheo2[100], res = INT_MIN;
//X1 X2...Xn
//X1 = y : Con hậu hàng 1 đặt ở cột y 

void Try1(int i){
    for(int j=1; j<=n; j++){
        //lựa chọn cột j để mình đặt con hậu ở hàng thứ i
        if(cot[j]==0 && cheo1[i-j+n]==0 && cheo2[i+j-1]==0){
            X[i] = j;
            cot[j] = cheo1[i-j+n] = cheo2[i+j-1] = 1;//đánh dấu đã đc dùng 
            if(i == n){
                int tong = 0;
                for(int hang=1; hang<=n; hang++){
                    tong += a[hang][X[hang]];
                }
                res = max(res, tong);
            }
            else{
                Try1(i+1);
            }
            cot[j] = cheo1[i-j+n] = cheo2[i+j-1] = 0;
        }
    }
}

void Try(int i, int sum){
    for(int j=1; j<=n; j++){
        //lựa chọn cột j để mình đặt con hậu ở hàng thứ i
        if(cot[j]==0 && cheo1[i-j+n]==0 && cheo2[i+j-1]==0){
            X[i] = j;
            cot[j] = cheo1[i-j+n] = cheo2[i+j-1] = 1;//đánh dấu đã đc dùng 
            if(i == n){
                res = max(res, sum + a[i][j]);
            }
            else{
                Try(i+1, sum + a[i][j]);
            }
            cot[j] = cheo1[i-j+n] = cheo2[i+j-1] = 0;
        }

    }
}

void run(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cin >> a[i][j];
    }
    // Try(1, 0);
    Try1(1);
    cout << res << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}