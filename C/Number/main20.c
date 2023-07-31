//#20[Bài Tập C (Hàm, Lý thuyết số )]. Số SMITH
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum(int n){
    int sum = 0;
    while (n % 10 != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int smith (int n){
    int sum1 = sum(n);
    int sum2 = 0; //tính tổng các chữ số của các thừa số nguyên tố của n 
    int tmp = n;//sau vòng for nếu biến tạm k thay đổi thì là số nguyên tố 
    for (int i=2; i<=sqrt(n); i++){
        while (n%i ==0){
            sum2 += sum(i);//tính tổng các chữ số của thừa số nguyên tố i 
            n /= i;
        }
    }
    if(tmp == n) return 0;
    if(n!= 1)
        sum2+= sum(n);
    return sum1 == sum2;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        printf(smith(n) ? "YES" : "NO");
    }
}