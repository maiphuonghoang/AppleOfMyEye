#include <stdio.h>
#include <stdlib.h>
/* //cách bình thường hay làm 
int nt (int n ){
	for (int i = 2; i < sqrt(n); i++)
		if (n % i == 0)
			return 0;
	return n > 1; //số dương khác 1 
}

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		if (nt(i))	
			printf("%d ", i);
}
*/
//Nếu bạn muốn sàng các số nguyên tố không vượt quá n.
//Phải tạo được 1 mảng có kích thước là n + 1 phần tử 
//vì chạy từ 0 tới n có n + 1 phần tử 

//SÀNG SỐ ERATOSTHENES 
//gán tất cả phần tử mảng 1
//loại bội cả những số nguyên tố - chuyển từ 1 -> 0
//phần nguyên tố là những cái 1 


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
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		if (prime[i])	
			printf("%d ", i);
}