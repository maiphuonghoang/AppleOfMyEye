// 32. Số Thuận Nghịch Có Ít Nhất 3 Ước Nguyên Tố
#include <stdio.h>
#include <math.h>

int nguyento(int n)
{
    int count = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {   
        int ans = 0;
        while (n % i == 0)
        {
            ans++;
            n /= i;
        }
        if(ans != 0)
            count++;
    }
    if(n != 1)
        ++count;
    return count;
}
int thuannghich(int n){
    int sum = 0;
    int tmp = n;
    while (n!=0)    
    {
        sum = n%10 + sum* 10;
        n /= 10;
    }
    return sum == tmp;
    
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int ok = 0;
    for (int i=a; i<=b; i++){
        if(nguyento(i)>=3 && thuannghich(i)){
            printf("%d ", i);
            ok = 1;
        }
    }
    if(!ok) printf("-1");
}