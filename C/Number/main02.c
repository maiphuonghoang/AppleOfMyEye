#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
//SÀNG NGUYÊN TỐ TRÊN ĐOẠN [A-B]
int prime[1000001];//10^6+1
void sieve(){
	//coi tất cả các số từ 0 cho tới n là số nguyên tố 
	for (int i = 0; i <= 1000000; i++)
		prime[i] = 1;
	//loại 0 và 1;
	prime[0] = prime[1] = 0;
	
	//nếu i là số nguyên tố  
	for (int i = 2; i <= 1000; i++)
		if(prime[i])//lúc này số mang gtri 1 là snt 
			//duyệt tất cả các bội số của i và cho nó không là số nguyên tố 
			for(int j = i * i; j < 1000000; j += i)
				prime[j] = 0; //j ko còn là snt nữa 
		
}
int main(int argc, char *argv[]) {
	sieve();
	int l;
	scanf("%d", &l);
	int r;
	scanf("%d", &r);
	for (int i = l; i <= r; i++)
		if (prime[i])	
			printf("%d ", i);
}

