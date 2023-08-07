//41. Ước Chung Lớn Nhất | Bội Chung Nhỏ Nhất 
#include <stdio.h>
#include <math.h>
#define ll long long 

//gcd(a,b)=gcd(b,a-b) kết thúc khi a=b
ll gcd1(ll a, ll b){
    if(a==0||b==0) return a+b;
    while (a!=b){
        if(a>b)
            a = a-b;
        else
            b = b-a; 
    }
    return a;
}
//gcd(a,b)=gcd(b,a%b) kết thúc khi b=0
ll gcd2(ll a, ll b){
    while (b!=0){
        ll tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
ll gcd3(ll a, ll b){
    if(b==0)
        return a;
    return gcd3(b,a%b);
}
ll lcm(ll a, ll b){
    return a*b/gcd3(a,b);
}
int main(){
    ll a, b;
    scanf("%lld%lld",&a, &b);
    printf("%lld %lld %lld %lld", gcd1(a,b),gcd2(a,b), gcd3(a,b), lcm(a,b));
}