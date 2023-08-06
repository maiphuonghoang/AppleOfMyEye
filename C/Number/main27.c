// 27. Số Hoàn Hảo
#include <stdio.h>
#include <math.h>

// 6 có ước 1 2 3 6 có tổng ước thực sự 1+2+3=6
// 28 có ước 1 2 4 7 14 28

int check(long long n)
{
    // n chắc chắn có ước là 1
    int sum = 1; // để bỏ trường hợp +n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i != n / i)
                sum += i + n / i;
            else
                sum += i;
        }
    }
    return sum == n;
}
// Nếu p là số nguyên tố, 2^p-1 là số nguyên tố
// thì tích 2^(p-1)*(2^p-1) là số hoàn hảo
// 6 thì p=2, 28 thì p=3

// Mảng chứa các số hoàn hảo trong [1; 10^18 (2^63)]
// duyệt p chạy từ 1 đến 32
int prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return n > 1;
}
int check2(long long n)
{
    for (int i = 1; i <= 32; i++)
    {
        if (prime(i))
        {
            int tmp = (int)pow(2, i) - 1;
            if (prime(tmp))
            {
                long long hoanhao = 1ll * tmp * (int)pow(2, i - 1);
                if (hoanhao == n)
                    return 1;
            }
        }
    }
    return 0;
}
// 130816
// 2096128
// các số hoàn hảo trong đoạn [1-10^18]
long long ans[10];
int num = 0;
void init()
{
    for (int i = 1; i <= 32; i++)
    {
        if (prime(i))
        {
            int tmp = (int)pow(2, i) - 1;
            if (prime(tmp))
                ans[num++] = 1ll * tmp * (int)pow(2, i - 1);
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        if (check(n))
            printf("Yes");
        else
            printf("No");
    }
    init();
    for (int i = 0; i < num; i++)
    {
        printf("%lld\n", ans[i]);
    }
}
