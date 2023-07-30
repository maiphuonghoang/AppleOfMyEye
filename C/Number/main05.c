#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//KIỂM TRA SỐ NGUYÊN TỐ CÓ TẤT CẢ CÁC CHỮ SỐ CŨNG LÀ SỐ NGUYÊN TỐ 
/* Đếm xem trong đoạn [a,b] có bao nhiêu số là số nguyên tố và 
 tất cả các chữ số của nó cũng là số nguyên tố 
	I						O
	2
	10 100					4
	1234 5678				26
*/
int isPrime(int n){
	for(int i = 2; i <= sqrt(n); i++)
		if(n%i==0)
			return 0;
	return n>1;
}
int digitPrime(int n){
	while (n){
		int r = n % 10;
		if(r!=2 && r!=3 && r!=5 && r!=7) 
		// !(n==2 || n==3 || n==5 || n==7)
			return 0;
		n /= 10;
	}
	return 1;	
}

int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int a, b;
		scanf("%d%d", &a, &b);
		int count = 0;
		for (int i = a; i<=b; i++)
			if(digitPrime(i) && isPrime(i))
				count++;
		printf("%d", count);
		
	}
}