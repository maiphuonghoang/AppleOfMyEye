//45. Đếm Ước Của N Giai Thừa
//phân tích thừa số nguyên tố của n! (tìm bậc của mỗi số nguyên tố (<=n)))
//rồi áp dụng d(n)=(e1+1)(e2+1)...

#include <stdio.h>
#include <math.h>
#define ll long long 

//Tìm bậc của số nguyên tố p trong n!
int degree1(int n, int p){
    int ans = 0;
    //duyệt qua các bội của i;
    for (int i=p; i<=n; i+=p){
        int tmp = i;
        while (tmp%p==0)
        {
            ans++;
            tmp /= p;
        }
    }
    return ans;
} 
//Legendry
int degree2(int n, int p){
    int ans = 0;
    for (int i=p; i<=n; i*=p)
        ans += n/i;
    return ans;
}
int prime(int n){
    for (int i=2; i<= sqrt(n); i++){
        if(n%i==0) return 0;
    }
    return n>1;
}
//Tìm số ước qua bậc của số nguyên tố 
ll countDivisor(int n){
    ll res = 1;
    for (int i=1; i<=n; i++)
        if(prime(i))
            res *= degree2(n,i)+1;
    return res;
}
int main(){
        int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld", countDivisor(n));
        printf("\n");
    }
}