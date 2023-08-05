// #22 | 2[Bài Tập C (Hàm, Lý thuyết số )]. Số Thuận Nghịch | Số Đối Xứng
#include <stdio.h>
#include <math.h>
#include <string.h>

int reverse(long long n)
{
    long long rev = 0, m = n;
    while (n != 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return m == rev;
}
int thuannghich(char c[])
{
    int l = 0, r = strlen(c) - 1;
    while (l < r)
    {
        if (c[l] != c[r])
            return 0;
        l++;
        r--;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        if (reverse(n))
            printf("Yes");
        else
            printf("No");
    }
    while (1>0){
        //cach chuoi
        char c[100];
        scanf("%s", c);
        if (thuannghich(c))
            printf("Yes");
        else
            printf("No");
    }
}
