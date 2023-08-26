#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
4
=>
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7
*/
void xoayOcTangDanThuan(){
    int n;
    scanf("%d", &n);
    int a[n][n], cnt = 1;
    int h1 = 0, h2 = n-1, c1 = 0, c2 = n-1;
    while(h1 <= h2 && c1 <= c2){
        //xây dựng dòng trên cùng 
        for (int i = c1; i <=c2; i++){
            a[h1][i] = cnt;
            cnt++;
        }
        h1++;
        //xây dựng cạnh bên phải 
        for (int i = h1; i <=h2; i++){
            a[i][c2] = cnt;
            cnt++;
        }        
        c2--;
        if(c1<=c2){
            //xây dựng dòng dưới cùng 
            for (int i = c2; i >= c1; i--){
                a[h2][i] = cnt;
                cnt++;
            } 
            h2--;
        }
        if(h1 <=h2){
            //xây dựng cột bên trái 
            for (int i = h2; i >= h1; i--){
                a[i][c1] = cnt;
                cnt++;
            }    
            c1++;         
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
//----------------------------------------------------------------
/**
3
=>
9 8 7
2 1 6
3 4 5
*/
void xoayOcTangDanNguoc(){
    int n;
    scanf("%d", &n);
    int a[n][n], cnt = n*n;
    int h1 = 0, h2 = n-1, c1 = 0, c2 = n-1;
    while(h1 <= h2 && c1 <= c2){
        //xây dựng dòng trên cùng 
        for (int i = c1; i <=c2; i++){
            a[h1][i] = cnt;
            cnt--;
        }
        h1++;
        //xây dựng cạnh bên phải 
        for (int i = h1; i <=h2; i++){
            a[i][c2] = cnt;
            cnt--;
        }        
        c2--;
        if(c1<=c2){
            //xây dựng dòng dưới cùng 
            for (int i = c2; i >= c1; i--){
                a[h2][i] = cnt;
                cnt--;
            } 
            h2--;
        }
        if(h1 <=h2){
            //xây dựng cột bên trái 
            for (int i = h2; i >= h1; i--){
                a[i][c1] = cnt;
                cnt--;
            }    
            c1++;         
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
//----------------------------------------------------------------
/** (n k vượt quá 10)
4
=>
2 3 5 7
37 41 43 11
31 53 47 13
29 23 19 17
*/
int nt(int n){
    for (int i = 2; i <= sqrt(n); i++)
        if(n%i == 0) return 0;
    return n > 1;
}
int p[100];
void initPrime (){
    int i = 0, cnt = 0;
    while (cnt < 100) {
        if(nt(i)){
            p[cnt] = i;
            cnt++;
        } 
        i++;
    }
}
void xoayOcNguyenTo(){
    initPrime();
    // for (int i = 0; i < 100; i++)
    //     printf("%d ", p[i]);

    int n;
    scanf("%d", &n);
    int a[n][n], cnt = 0;
    int h1 = 0, h2 = n-1, c1 = 0, c2 = n-1;
    while(h1 <= h2 && c1 <= c2){
        //xây dựng dòng trên cùng 
        for (int i = c1; i <=c2; i++){
            a[h1][i] = p[cnt];
            cnt++;
        }
        h1++;
        //xây dựng cạnh bên phải 
        for (int i = h1; i <=h2; i++){
            a[i][c2] = p[cnt];
            cnt++;
        }        
        c2--;
        if(c1<=c2){
            //xây dựng dòng dưới cùng 
            for (int i = c2; i >= c1; i--){
                a[h2][i] = p[cnt];
                cnt++;
            } 
            h2--;
        }
        if(h1 <=h2){
            //xây dựng cột bên trái 
            for (int i = h2; i >= h1; i--){
                a[i][c1] = p[cnt];
                cnt++;
            }    
            c1++;         
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
//----------------------------------------------------------------
long long fibo[100];
void initFibo(){
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= 90; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
}
void xoayOcFibonacci(){
    initFibo();
    int n;
    scanf("%d", &n);
    long long a[n][n], cnt = 0;
    int h1 = 0, h2 = n-1, c1 = 0, c2 = n-1;
    while(h1 <= h2 && c1 <= c2){
        //xây dựng dòng trên cùng 
        for (int i = c1; i <=c2; i++){
            a[h1][i] = fibo[cnt];
            cnt++;
        }
        h1++;
        //xây dựng cạnh bên phải 
        for (int i = h1; i <=h2; i++){
            a[i][c2] = fibo[cnt];
            cnt++;
        }        
        c2--;
        if(c1<=c2){
            //xây dựng dòng dưới cùng 
            for (int i = c2; i >= c1; i--){
                a[h2][i] = fibo[cnt];
                cnt++;
            } 
            h2--;
        }
        if(h1 <=h2){
            //xây dựng cột bên trái 
            for (int i = h2; i >= h1; i--){
                a[i][c1] = fibo[cnt];
                cnt++;
            }    
            c1++;         
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%lld ", a[i][j]);
        printf("\n");
    }
}
int main(int argc, char *argv[]) {
	xoayOcFibonacci();
}