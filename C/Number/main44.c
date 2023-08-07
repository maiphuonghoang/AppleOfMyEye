//44.Lũy Thừa Nhị Phân | Thuật Toán Tính Lũy Thừa Trong O(LogN)
#include <stdio.h>
#include <math.h>
#define ll long long 
//O(n)
ll pow1(int a, int b){
    ll res = 1;
    for (int i = 1; i <= b; i++)
        res *= a;
    return res;
}
//O(logn)
// a^b = a^(b/2)*a^(b/2) nếu b chẵn 
// a^b =a^(b/2)*a^(b/2)*a nếu b lẻ 
// ll pow2(int a, int b){
//     ll res = 1;
//     while(b){
//         if(b%2==1)
//             res *= a;
//         a = a *a;
//         b /= 2;
//     }
//     return res;
// }
ll pow2(int a, int b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res *= a;
        b /= 2;
        a *= a;
    }
    return res;
}
ll pow3(int a, int b){
    if(b==0)
        return 1;
    ll x = pow3(a,b/2);
    if(b%2==1)
        return x*x*a;
    else return x*x;
}
int main(){
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%lld %lld %lld", pow1(a,b), pow2(a,b), pow3(a,b));
        printf("\n");
    }
}