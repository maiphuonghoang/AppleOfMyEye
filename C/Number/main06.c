#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Liệt Kê N Số Nguyên Tố Ðầu Tiên
// Input: 5 	Output: 2 3 5 7 11
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