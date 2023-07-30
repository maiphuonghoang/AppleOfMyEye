//#18[Bài Tập C (Hàm, Lý thuyết số )]. Hướng Dẫn Đếm Số 0 Tận Cùng Của N Giai Thừa
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count1(int n, int p){
    int count = 0;
    for (int i=p; i<=n; i*=p){
        count += n/i;
    }
    return count;
}
int count2(int n){
    int count = 0;
    for (int i=5; i<=n; i+=5){
        int tmp = i;
        while (tmp % 5 == 0)
        {
            count++;
            tmp /= 5;
        }
        
    }
    return count;
}
int main(){
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
        int n, p = 5;
        scanf("%d",&n);
        //tìm số lần xuất hiện của 5 trong n giai thừa 
        printf("%d\n", count1(n,p));
        printf("%d\n", count2(n));
    }
    
}