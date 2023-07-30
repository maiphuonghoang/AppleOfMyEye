// 15[Bài Tập C (Hàm, Lý thuyết số )]. Phân Tích Thừa Số Nguyên Tố Kết Hợp Sàng Số Nguyên Tố
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime[100001];
void seive()
{
    for (int i = 1; i <= 100000; i++)
        prime[i] = i;
    for (int i = 2; i < sqrt(100000); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 100000; j += i)
                if (prime[j] == j)
                    prime[j] = i;
            // ước nguyên tố nhỏ nhất của 1 số
        }
    }
}
void pt1(int n)
{
    while (n != 1)
    {
        printf("%d ", prime[n]);
        n /= prime[n];
    }
    printf("\n");
}
void pt2(int n)
{
    while (n != 1)
    {
        int count = 0;
        int tmp = prime[n];
        while (n % tmp == 0)
        {
            count++;
            n /= tmp;
        }
        printf("%d(%d) ", tmp, count);
    }
    printf("\n");
}
void pt3(int n)
{
    int soluong = 0;
    while (n != 1)
    {
        int count = 0;
        int tmp = prime[n];
        while (n % tmp == 0)
        {
            count++;
            n /= tmp;
        }
        soluong++;
        printf("%d(%d) ", tmp, count);
    }
    printf("so luong so nguyen to: %d\n", soluong);
}
int main()
{
    seive();
    int t;
    scanf("%d", &t);
    for (int i = 0; i <= t; i++)
    {
        int n;
        scanf("%d", &n);
        printf("#TC%d: ", i);
        // pt2(n);
        pt3(n);
    }
}