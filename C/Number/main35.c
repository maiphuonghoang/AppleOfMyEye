// Số Armstrong
// Số A có n chữ số và thoả mãn tổng của lũy thừa bậc n 
//của từng số trong A bằng chính nó 
//371 = 3^3+7^3+1^3 
#include <stdio.h>
#include <math.h>
int count(int n){
    int count = 0;
    while (n)
    {
        count++;
        n /= 10;
    }
    return count;
    
}
int armstrong(int n){
    int sum = 0, tmp = n;
    int d = count(n);
    while(n){
        sum += (int)pow(n%10, d);
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
        if(armstrong(i)){
            printf("%d ", i);
            ok = 1;
        }
    }
    if(!ok) printf("-1");
}