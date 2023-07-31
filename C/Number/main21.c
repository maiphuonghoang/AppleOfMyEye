// #21[Bài Tập C (Hàm, Lý thuyết số )]. Tìm Ước Nguyên Tố Lớn Nhất Của 1 Số
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nt(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return n > 1;
}
int find1(int n)
{
    for (int i = n; i > 0; i--)
    {
        if (n % i == 0 && nt(i)) // độ phức tạp cao vì mỗi lần đều check nt
            return i;
    }
    return -1;
}
int find2(int n)
{
    // chỉ cần check ước nto, ước khác k cần check
    // thực chất là phân tích thừa số nto, lấy ước cuối cùng
    int res;
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            res = i;
            n /= i;
        }

    }
    if(n!=1) res = n;
    return res;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        printf("%d ", find1(n));
        printf("%d", find2(n));
    }
}