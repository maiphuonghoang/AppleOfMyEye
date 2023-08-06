//34. Số Lộc Phát | Số Thuận Nghịch Lộc Phát
//Số Lộc Phát Là số chỉ có các chữ số 0,6,8
//Số Thuận Nghịch Lộc Phát: là số thuận nghịch, có chứa ít nahats 1 chữ số 6,
//tổng các chữ số có chữ số cuối cùng là 8
#include <stdio.h>
#include <math.h>
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
int chua6tong8(int n){
    int sum = 0;
    int check = 0;
    while (n)
    {
        if(n%10==6)
            check = 1;
        sum += n % 10;
        n /= 10;
    }
    return check && (sum % 10 == 8); 
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int ok = 0;
    for (int i=a; i<=b; i++){
        if(chua6tong8(i)&& thuannghich(i)){
            printf("%d ", i);
            ok = 1;
        }
    }
    if(!ok) printf("-1");
}