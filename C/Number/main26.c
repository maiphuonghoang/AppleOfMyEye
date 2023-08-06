//26. Kiểm Tra Số Có Số Lượng Ước Là Số Lẻ
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool check(long long n){
    int count = 0;
    for (int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            if(i!=n/i)
                count += 2;
            else    
                ++count;
        }
    }
    return count%2==1;
}
//số chính phương có số lượng ước là số lẻ 
int chinhphuong(long long n){
    int can = sqrt(n);
    if(1ll*can*can == n)
        return 1;
    return 0;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        if(check(n))
            printf("Yes");
        else printf("No");
    }
}