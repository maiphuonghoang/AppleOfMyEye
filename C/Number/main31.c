// Số Nguyên Tố Có Tổng Các Chữ Số Là Số Fibonacci

#include <stdio.h>
#include <math.h>

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
// NOTE: n là số fibonaci thì 5n^2+4 và 5n^2-4 là số chính phương
// kiểm tra 1 số có là số fibo không thì xem nó có trong mảng số fibo k
int check(long long n)
{
    if (n == 0 || n == 1)
        return 1;
    long long fn2 = 0, fn1 = 1;
    for (int i = 3; i <= 93; i++)
    {
        long long fn = fn1 + fn2;
        if (fn == n)
            return 1;
        fn2 = fn1;
        fn1 = fn;
    }
    return 0;
}
int sum(int n)
{
    int ans = 0;
    while (n != 0)
    {
        ans += n % 10;
        n /= 10;
    }
    return check(ans);
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int ok = 0;//check xem có tồn tại số đẹp nằm trong khaongr từ a=>b k 
    for (int i=a; i<=b; i++){
        if(sum(i)&&prime(i)){
            printf("%d ", i);
            ok = 1;
        }
    }
    if(!ok) printf("-1");
}