#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//SÀNG SỐ NGUYÊN TỐ TRÊN ĐOẠN
int max(int a, int b) {
	return a>b?a:b;
}
int main() {
	int l, r;
	scanf("%d%d", &l, &r);
	
	int prime[r-l+1];
	for(int i = 0; i<= r-l+1; i++ )
		prime[i] = 1;
		
	for (int i = 2; i <= sqrt(r); i++)
		if(prime[i])
			for (int j = max(i*i, (l+i-1)/i*i); j <= r; j+=i)
				prime[j - l] = 0;
				
	for (int i = max(l, 2); i<= r; i++)
		if(prime[i-l])
			printf("%d ", i);
}
//Format code: ctrl + shift + a 
//Debug: F5