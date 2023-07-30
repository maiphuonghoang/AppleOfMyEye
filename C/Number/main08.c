#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// SỐ THUẦN NGUYÊN TỐ 
/* 
    Một số được coi là thuần nguyên tố nếu nó là số nguyên tố, tất cả các chữ số là nguyên tố 
    và tổng chữ số của nó cũng là một số nguyên tố  
*/


int prime[1000001];
void sieve() {
	for(int i = 0; i<=1000000; i++)
		prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i=2; i <= 1000; i++)
		if (prime[i])
			for(int j = i*i; j<=1000000; j+=i )
				prime[j] = 0;
}
int digitPrimeAndSumPrime(int n){
	int sum = 0;
	while(n){
		int r = n%10;
		if(r!=2&& r!=3 && r!=5 && r!=7)
			return 0;
		n/=10;
		sum += r;
	}
	return prime[sum];
	
}


int main(int argc, char *argv[]) {
	sieve();
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b;
		scanf("%d%d", &a, &b);
		int count = 0;
		for(int i=a; i<=b ;i++){
			if(digitPrimeAndSumPrime(i) && prime[i] )
				++count;
		}
		printf("count:%d\n", count);
	}



}