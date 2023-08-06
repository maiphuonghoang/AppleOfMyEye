//#30. Số Fibonacci | Kiểm Tra Số Fibonacci
//F(n) = F(n-1)+F(n-2)

#include <stdio.h>
#include <math.h>

void solve1(int n){
    printf("0 1 ");
    long long fn2=0, fn1=1;
    for (int i=3; i<=n; i++){
        long long fn = fn1 + fn2;
        printf ("%lld ", fn);
        fn2=fn1;
        fn1=fn;
    }
}
void solve2(int n){
    long long fibo[n];
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i=2; i<=n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    for (int i=0; i<n; i++){
        printf("%lld ", fibo[i]);
    }
}
// NOTE: n là số fibonaci thì 5n^2+4 và 5n^2-4 là số chính phương 
//kiểm tra 1 số có là số fibo không thì xem nó có trong mảng số fibo k 
void check(long long n){
    if(n==0||n==1)
        return 1;
    long long fn2=0, fn1=1;
    for (int i=3; i<=93; i++){
        long long fn = fn1 + fn2;
        if(fn==n)
            return 1;
        fn2=fn1;
        fn1=fn;
    }
    return 0;
}
int main()
{
    int t = 1;
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        solve1(n);
        solve2(n);
    }
}