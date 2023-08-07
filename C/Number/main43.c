// 42. Phi Hàm Euler Sử Dụng Sàng Số Nguyên Tố Biến Đổi
#include <stdio.h>
#include <math.h>

int p[1000001];
void seive(){
    for (int i=1; i<1000001; i++)
        p[i]=i;
    for (int i=2; i<=1000000; i++)
        if(p[i]==i){
            p[i] = i-1;//số lượng nguyên tố cùng nhau của số nguyên tố 
            for (int j=2*i; j<=1000000; j+=i)//gặp bội của i thì nhân thêm 
                p[j] -= p[j]/i;
        }

}
int main(){
    seive();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i=1; i<=n; i++)
            printf("%d ", p[i]);
        printf("\n");
    }
    

}