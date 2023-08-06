//33. Số Strong
//Số có tổng giai thừa các chữ số bangef chính nó 
//2 có tổng giai thừa 2! = 2
//145 có tổng giai thừa 1+ 4! + 5!= 1+24+120 = 145 
#include <stdio.h>
#include <math.h>
int giaiThua(int n){
    int res = 1;
    for (int i=1; i<=n; i++)
        res*=i;
    return res;
}
int strong(int n){
    int sum = 0, tmp = n;
    while (n){
        sum += giaiThua(n%10);
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
        if(strong(i)){
            printf("%d ", i);
            ok = 1;
        }
    }
    if(!ok) printf("-1");
}