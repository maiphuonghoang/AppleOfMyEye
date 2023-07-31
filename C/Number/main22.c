// #22 [Bài Tập C (Hàm, Lý thuyết số )]. Tìm Số Chia Hết Cho 1 Số Và Chia Hết Cho Bình Phương Của Nó

// B1. Một số được coi là số đẹp khi nó đồng thời vừa chia hết cho 1 số nguyên tố
//  và chia hết cho bình phương của số nguyên tố đó

// In ra các số đẹp trong đoạn từ a tới b

// 28 = 2.2.7 => ước nguyên tố có bậc là 2
// Xác định trong phân tích thừa số nguyên tố của n có thừa số nào có số mũ >=2
#include <stdio.h>
#include <math.h>

int sodep(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        if (count >= 2)
            return 1;
    }
    return 0;
}
// B2. Một số được coi là số đẹp khi nó đồng thời vừa chia hết cho các ước số nguyên tố
//  và bắt buộc chia hết cho bình phương của số nguyên tố đó
// Xác định trong phân tích thừa số nguyên tố của n có thừa số nào có số mũ =1
int sodep2(int n)
{
    int ok = 0;//check dieu kien can 
    for (int i = 2; i <= sqrt(n); i++)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        if (count == 1)
            return 0;
        if(count >= 2)
            ok = 1;
    }
    if(n != 1)
        return 0;
    return ok; 
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++)
        if (sodep(i))
            printf("%d ", i);
    for (int i = a; i <= b; i++)
        if (sodep2(i))
            printf("%d ", i);
}