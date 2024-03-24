#include <bits/stdc++.h>
using namespace std;


// 1 + 2 + ... + n
int deQuy1(int n){
    if(n==1)
        return 1;
    return deQuy1(n-1) + n;
}
int deQuyLui1(int n, int x = 1){
    //lời gọi hàm nằm ở cuối cùng 
    if(n==1){
        return x;
    }
    return deQuyLui1(n-1, x + n);
}
int khuDeQuy1(int n){
    int tong = 0;
    for(int i=1;i<=n; i++){
        tong += i;
    }
    return tong;
}
//================================================================
// 1^2 + 2^2 + ... + n^2
int deQuy2(int n){
    if(n==1){
        return 1;
    }
    return deQuy2(n-1) + n*n;
}
int deQuyLui2(int n, int x = 1){
    if(n == 1){
        return x;
    }
    return deQuyLui2(n-1, x + n*n);
}
int khuDeQuy2(int n){
    int tong = 0;
    for(int i=1; i<=n; i++){
        tong += i*i;
    }
    return tong;
}
//================================================================
// 1 + 1/2 + 1/3 + ... + 1/n
float deQuy3(int n){
    if(n==1)
        return 1;
    return deQuy3(n-1) + 1.0*1/n;
}
float deQuyLui3(int n, float x = 1){
    if(n==1)
        return x;
    return deQuyLui3(n-1, x + 1.0*1/n);
}
float khuDeQuy3(int n){
    float tong = 0;
    for (int i=1; i<=n; i++){
        tong += 1.0*1/i;
    }
    return tong;
}
//================================================================
// 1/2 + 1/4 + ... + 1/2n
float deQuy4(int n){
    if(n==1)
        return 1.0/2;
    return deQuy4(n-1) + 1.0/(2*n);
}
float deQuyLui4(int n, float x = 1.0/2){
    if(n==1)
        return x;
    return deQuyLui4(n-1, x + 1.0/(2*n));
}
float khuDeQuy4(int n){
    float tong = 0;
    for (int i=1; i<=n; i++){
        tong += 1.0/(2*i);
    }
    return tong;
}
//================================================================
// 1 + 1 + 1 + ... +   1 
//     3   5         2n+1
float deQuy5(int n){
    if(n==0)
        return 1;
    return deQuy5(n-1) + 1.0/(2*n + 1);
}
float deQuyLui5(int n, float x = 1){
    if(n==0)
        return x;
    return deQuyLui5(n-1, x + 1.0/(2*n+1));
}
float khuDeQuy5(int n){
    float tong = 0;
    for (int i=0; i<=n; i++){
        tong += 1.0*1/(2*i + 1);
    }
    return tong;
}

//================================================================
//  1 +   1 +  ... +     1 
// 1*2   2*3          n(n+1)
float deQuy6(int n){
    if(n==1)
        return 1.0/2;
    return deQuy6(n-1) + 1.0/(n*(n+1));
}
float deQuyLui6(int n, float x = 1.0/2){
    if(n==1)
        return x;
    return deQuyLui6(n-1, x + 1.0/(n*(n+1)));
}
float khuDeQuy6(int n){
    float tong = 0;
    for (int i=1; i<=n; i++){
        tong += 1.0/(n*(n+1));
    }
    return tong;
}
//================================================================
/* tính x^n 
    với n>0 (vd là 3) thì x^3 = x*x*x
    với n<0 (vd là -3) thì x^-3 = 1/(x*x*x)
*/
float deQuy7(float x, int n){

    if(n==1){
        return x;
    }
    if(n == -1){
        return 1.0/x;
    }
    if(n<0){
        return deQuy7(x, n+1) * 1.0/x;
    }
    else if(n==0){
        return 1;
    }
    return deQuy7(x, n-1)*x;
}
float deQuyLui7(float x, int n, float y = 1){
    if(n==0){
        return y;
    }
    if(n<0){
        return deQuyLui7(x, n+1, y*1.0/x);
    }
    else if(n==0){
        return 1;
    }
    return deQuyLui7(x, n-1, y*x);
}
float khuDeQuy7(int x, int n){
    float tich = 1;
    bool check = false;
    if (n == 0)
        return tich;
    else if(n>0){
        check = true;
    }else{
        n *= -1;
    }
    for(int i=1; i<=n; i++){
        tich *= x;
    }
    if(check)
        return tich;
    return 1.0/tich;
}

int main() {
    cout << deQuy1(10) << deQuyLui1(10) << khuDeQuy1(10) << endl;
    cout << deQuy2(10) << deQuyLui2(10) << khuDeQuy2(10) << endl; 
    cout << deQuy3(10) << " " << deQuyLui3(10) << " " << khuDeQuy3(10) << endl; 
    cout << deQuy4(10) << " " << deQuyLui4(10) << " " << khuDeQuy4(10) << endl; 
    cout << deQuy5(10) << " " << deQuyLui5(10) << " " << khuDeQuy5(10) << endl; 
    cout << deQuy6(10) << " " << deQuyLui6(10) << " " << khuDeQuy6(10) << endl; 
    cout << deQuy7(2,-3) << " " << deQuyLui7(2,-3) << " " << khuDeQuy7(2,-3) << endl; 
    cout << deQuy7(2,0) << " " << deQuyLui7(2,0) << " " << khuDeQuy7(2,0) << endl; 
    return 0;
}