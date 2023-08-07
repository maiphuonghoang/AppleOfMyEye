//36.Số nguyên tố có chữ số cuối cùng lớn nhất 
#include <stdio.h>
#include <math.h>
//x=n%10; trong quá trình tách có chữ số >x thì sai 
int prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return n > 1;
}
int check(int n){
    int x = n%10;
    while (n)
    {
        if(n%10 > x)
            return 0;
        n /= 10;
    }
    return 1;
    
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int ok = 0;
    for (int i=a; i<=b; i++){
        if(prime(i)&&check(i)){
            printf("%d ", i);
            ok = 1;
        }
    }
    if(!ok) printf("-1");
}