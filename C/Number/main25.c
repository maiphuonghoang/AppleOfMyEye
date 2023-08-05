// #25 [Bài Tập C (Hàm, Lý thuyết số )]. Tính Tổng Ước Của Số Nguyên | Đếm Ước Của Số Nguyên
#include <stdio.h>
#include <math.h>
int count(int n)
{
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++)
        if (n % i == 0)
            count += 2;
    int c = sqrt(n);
    if (c * c == n)
        count--;
    return count;
}
int count2(int n)
{
    // n = p^e1* p^2* p^e3
    // so uoc = (e1+1)(e2+1)(e3+1)
    int res = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        res *= (count + 1);
    }
    if (n != 1)
        res *= 2;
    return res;
}
int sumDivisor(int n)
{
    int sum = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i != n / i)
            {
                sum += i + n / i;
            }
            else
                sum += i;
        }
    }
    return sum;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("so luong1: %d", count(n));
        printf("so luong2: %d", count2(n));
        printf("sum = %d",sumDivisor(n));
        printf("\n");
    }
}