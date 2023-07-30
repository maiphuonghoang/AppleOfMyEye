//#17[Bài Tập C (Hàm, Lý thuyết số )]. Bậc Của Số Nguyên Tố Trong N Giai Thừa | Công Thức Legendre
/*
TC 3
62  7   
76  2   
3   5
O: 9    73  0 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count1(int n, int p){
    int ans = 0;
    for (int i=p; i<=n; i+=p){
        int tmp = i;
        //tạo biến tmp để không làm thay đổi i trong vòng for 
        while (tmp % p == 0)
        {
            ans++;
            tmp /= p;
        }
        
    }
    return ans;
}
//Công Thức Legendre
//số lượng 3 trong 10! là chặn dưới (10/3) + chặn dưới (10/9)
int count2(int n, int p){
    int ans = 0;
    for (int i=p; i<=n; i*=p){
        ans += n/i;
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
        int n, p;
        scanf("%d%d",&n, &p);
        printf("%d\n", count1(n,p));
    }
    
}