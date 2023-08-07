// 38.Thừa Số Nguyên Tố Thứ K | Tần Suất Xuất Hiện Của Các Chữ Số
#include <stdio.h>
#include <math.h>
// Thừa Số Nguyên Tố Thứ K: Đưa ra số nguyên tố thứ k trong phân tích thừa số nguyên tố của số n
// n=28, k=3 có kết quả là (7) vì 28 = 2*2*7
// n=8, k=5 (-1)
// n=60, k=3 60=2*2*3*5 (3)
int solve(int n, int k)
{
    int count = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            while (n % i == 0)
            {
                n /= i;
                count++;
                if (count == k)
                    return i;
            }
    }
    if (n != 1)
        count++;
    if (count == k)
        return n;
    return -1;
}
// Liệt kê số lần xuất hiện của chữ số nguyên tố của 1 số theo thứ tự từ nhỏ đến lớn
// 722334123232277
// 2-6,3-4,7-3

void tanso(long long n)
{
    int c2=0, c3=0, c5=0, c7=0;
    while (n)
    {
        int r = n%10;
        if(r==2) c2++;
        else if(r==3) c3++;
        else if (r==5) c5++;
        else if (r==7) c7++;       
        n /= 10;
    }
    if(c2!=0) printf("2 %d\n", c2);
    if(c3!=0) printf("3 %d\n", c3);
    if(c5!=0) printf("5 %d\n", c5);
    if(c7!=0) printf("7 %d\n", c7);
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("\nThua so nguyen to thu k\n");
    printf("%d", solve(n, k));
    printf("\nTan so xuat hien\n");
    long long a;
    scanf("%lld", &a);
    tanso(a);
}