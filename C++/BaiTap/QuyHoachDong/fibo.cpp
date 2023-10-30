#include <bits/stdc++.h>
using namespace std;
int fiboV1(int n){
    cout << n << " ";
    if(n <= 1) return 1;
    return fiboV1(n-1) + fiboV1(n-2);
}
int f[100];
void fiboV2(int n){
    f[0] = f[1] = 1;
    for (int i = 2; i <= 92; i++)
        f[i] = f[i-1] + f[i-2];       
}
//Đệ quy có nhớ 
int F[100];
int fiboV3(int n){
    cout << n << " ";
    if(n <= 1) return 1;
    if(F[n] != -1) return F[n]; //đã được tính 
    F[n] = fiboV3(n-1) + fiboV3(n-2);
    return F[n];
}
void initfiboV3(){
    // gán tất cả = -1 
    //memset < for < fill 
    //C1:
    memset(F, -1, sizeof F);

    //C2
    for (int i = 2; i <= 92; i++)
        F[i] = -1;
    
    //C3
      
}
//----------------------------------------------------------------

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    fiboV1(10);
    cout << endl;
    initfiboV3();
    cout << fiboV3(10);
    return 0;
}