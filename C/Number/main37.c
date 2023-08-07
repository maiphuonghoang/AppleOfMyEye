// 37.  Phi Hàm Euler | Kiểm Tra 2 Số Nguyên Tố Cùng Nhau
// 2 số nguyên tố cùng nhau có ước chung lớn nhất là 1

#include <stdio.h>
#include <math.h>
/*
13 5
5 3
3 2
2 1
1 0
1

16 24
24 8
8 16
16 8
8 8
8 0
8

*/

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// Phi Hàm Euler: Đếm số lượng các số nguyên tố cùng nhau với n không vượt quá n
// n=8 => 1 3 5 7
long long count1(long long n)
{
    long long res = 0;
    for (int i = 0; i <= n; i++)
    {
        if (gcd(i, n) == 1)
            res++;
    }
    return res;
}
// Công thức Phi hàm Euler
//  n(1-1/p) trong đó p|n (p là phân tích thừa số nguyên tố n chia hết)
//  60 = 2^2*3*5 => E{60} = 60*(1-1/2)*(1-1/3)*(1-1/5)=16
#define ll long long
ll phi(ll n)
{
    ll res = n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {

            while (n % i == 0)
            {
                n /= i;
            }
            //res = res * (1 - 1/i);
            res = res - res/i;
        }
    }
    if(n!=1){
        res = res - res/n;
    }
    return res;
}

int main()
{
    long long a, b;
    scanf("%lld%lld", &a, &b);
    if (gcd(a, b) == 1)
        printf("Yes");
    else
        printf("No");
    printf("\n so luong nguyen to cung nhau (CACH THONG THUONG) cua: ");
    long long n;
    scanf("%lld", &n);
    printf("%lld", count1(n));
    printf("\n so luong nguyen to cung nhau (CACH THONG THUONG) cua: %lld =", n);
    printf("%lld", phi(n));
}
