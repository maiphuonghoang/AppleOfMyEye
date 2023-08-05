// #23 [Bài Tập C (Hàm, Lý thuyết số )]. Số Chính Phương | Liệt Kê Số Chính Phương Trong Đoạn
#include <stdio.h>
#include <math.h>
#include <string.h>

int chinhPhuong(long long n)
{
    int can = sqrt(n) + 0.5;
    return 1ll * can * can == n;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        if (chinhPhuong(n))
            printf("Yes");
        else
            printf("No");
    }
    printf("\ntrong khoang");
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        for (int i = a; i <= b; i++)
            if (chinhPhuong(i))
                printf("%d ", i);
    printf("\n");

    // duyệt từ căn(a) đến căn(b) rồi bình phương lên ra các số chính phương trong khoảng
    int c1 = sqrt(a), c2=sqrt(b);
    if(c1*c1 != a)//xử lí cận dưới 
        c1++;
    for (int i = c1; i <= c2; i++)
            printf("%d ", i*i);
        printf("\n");
    printf ("so luong so chinh phuong trong doan la: %d",c2-c1+1);
    }

}
