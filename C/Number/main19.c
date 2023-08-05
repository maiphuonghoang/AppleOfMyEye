// #19[Bài Tập C (Hàm, Lý thuyết số )]. Số Sphenic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sphenic(int n)
{
    int res = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        if (count >= 2)
            return 0;
        if (count == 1)
            res++;
    }
    if (n != 1)
        res++;
    return res == 3;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        printf(sphenic(n) ? "YES" : "NO");
    }
}