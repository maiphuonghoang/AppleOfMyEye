#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// CẶP SỐ NGUYÊN TỐ CÓ TỔNG BẰNG N 
/* 	Liệt kê 2 số nguyên tố có tổng bằng 4 <= N <= 10000, N chẵn 
		I			O
		T:2
		4			2 2
		6			3 3
*/
int prime[10001];
void sieve() {
	for(int i = 0; i<=10000; i++)
		prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i=2; i <= 100; i++)
		if (prime[i])
			for(int j = i*i; j<=10000; j+=i )
				prime[j] = 0;
}
void main() {
	int t;
	scanf("%d", &t);
	sieve();
	while(t--){
		int n;
	scanf("%d", &n);
		for (int i =2; i<= n/2; i++)
		if(prime[i]&&prime[n-i])
			printf("%d %d ", i, n-i);
	}
}

