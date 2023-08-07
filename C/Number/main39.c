// 39. Liệt kê Tần Suất Xuất Hiện Của Các Chữ Số Nguyên Tố trong 1 số
#include <stdio.h>
#include <math.h>
#include <string.h>
#define ll long long
ll reverse(ll n)
{
    ll r = 0;
    while (n)
    {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}
void tanso(long long n)
{
    int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    ll m = reverse(n);
    while (n)
    {
        int r = n % 10;
        if (r == 2)
            c2++;
        else if (r == 3)
            c3++;
        else if (r == 5)
            c5++;
        else if (r == 7)
            c7++;
        n /= 10;
    }
    while (m)
    {
        int r = m % 10;
        if (r == 2 && c2 != 0)
        {
            printf("2 %d\n", c2);
            c2 = 0;
        }
        if (r == 3 && c3 != 0)
        {
            printf("3 %d\n", c3);
            c3 = 0;
        }
        if (r == 5 && c5 != 0)
        {
            printf("5 %d\n", c5);
            c5 = 0;
        }
        if (r == 7 && c7 != 0)
        {
            printf("7 %d\n", c7);
            c7 = 0;
        }
        m /= 10;
    }
}
void solve(char c[])
{
    int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] == '2')
            c2++;
        else if (c[i] == '3')
            c3++;
        else if (c[i] == '5')
            c5++;
        else if (c[i] == '7')
            c7++;
    }
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] == '2' && c2 != 0)
        {
            printf("2 %d\n", c2);
            c2 = 0;
        }
        if (c[i] == '3' && c3 != 0)
        {
            printf("3 %d\n", c3);
            c3 = 0;
        }
        if (c[i] == '5' && c5 != 0)
        {
            printf("5 %d\n", c5);
            c5 = 0;
        }
        if (c[i] == '7' && c7 != 0)
        {
            printf("7 %d\n", c7);
            c7 = 0;
        }
    }
}
int main()
{
    printf("Tan so xuat hien\n");
    long long a;
    scanf("%lld", &a);
    tanso(a);
    printf("\ndung chuoi");
    char c[100];
    scanf("%s", &c);
    solve(c);
}