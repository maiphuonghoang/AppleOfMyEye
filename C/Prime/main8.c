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
int main(int argc, char *argv[]) {
	sieve();
	int n;
	scanf("%d", &n);
	int i=0, count = 0;
	while (count < n) {
		if(prime[i]) {
			printf("%d ", i);
			count++;
		}
		i++;
	}



}