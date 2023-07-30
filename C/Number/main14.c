// 14[Bài Tập C (Hàm, Lý thuyết số )]. Phân Tích Thừa Số Nguyên Tố
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void pt(int n) // 84 = 2 2 3 7
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            printf("%d ", i);
            n /= i;
        }
    }
    if (n != 1)
        printf("%d ", n);
}
void pt2(int n) // 84 = 2 3 7
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            printf("%d ", i); // chỉ in 1 lần ở bên ngoài
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n != 1)
        printf("%d ", n);
}
void pt3(int n) // 84 = 2(2) 3(1) 7(1)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                n /= i;
                count++;
            }
            printf("%d(%d) ", i, count);
        }
    }
    if (n != 1)
        printf("%d(1) ", n);
}
void pt4(int n) // 84 = 2x2x3x7
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {

            while (n % i == 0)
            {
                printf("%d", i);
                n /= i;
                if (n != 1)
                    printf("x");
            }
        }
    }
    if (n != 1)
        printf("%d", n);
}

void pt5(int n) // 84 = 2^2*3^1*7^1
{
    printf("%d = ", n);
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n /= i;                
            }
            printf("%d^%d", i, count);
            if (n != 1)
                    printf("*");
        }
    }
    if (n != 1)
        printf("%d", n);
}
int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    // pt(n);
    // pt2(n);
    pt5(n);
    return 0;
}
