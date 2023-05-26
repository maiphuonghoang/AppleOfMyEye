#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//KIỂM TRA SỐ NGUYÊN TỐ VỚI NHỀU TEST CASE 
int prime[1000001];
// 0 < n < 10^6
void sieve(){
	for(int i = 0; i<=1000000; i++)
		prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i=2; i <= 1000; i++)
		if (prime[i])
			for(int j = i*i; j<=1000000; j+=i )
				prime[j] = 0;
}
int main(int argc, char *argv[]) {
	sieve();
	int t;
	printf("Nhap so luong input: ");
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		if(prime[n])
			printf("YES\n");
		else
			printf("NO\n");			
	}
}