#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	SỐ CÓ 3 ƯỚC SỐ | SỐ T-PRIME 
		- Số chính phương (số lượng ước là số lẻ)
		- n = p^e1 * p^e2 * p^e3
		thì số ước của n là d(n) = (e1+1)(e2+1)...(en+1)
		Vd: 60 = 2^2.3.5 => d(60)=3.2.2=12 ước 
		
		d(n) = 3 = 2 + 1 => n = p^2 
		=> Số có 3 ước số là bình phương của 1 số nguyên tố 
		
	Cho số tự nhiên N, liệt kê tất cả các số có đúng 3 ước số
	VD: n = 100, ta có các số 4,9,25,49
	
*/
//n<10^6 thì sàng đến 10^3
int prime[1001];
void seive(){
	for(int i = 0; i<=1000; i++)
		prime[i] = 1;
	prime[0] = prime [1] = 0;
	for (int i = 2; i<=sqrt(1000) ; i++)
		if (prime[i])
			for (int j = i*i; j <1000; j+=i)
				prime[j] = 0;
}
int main(int argc, char *argv[]) {
	seive();
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		for (int i = 1; i<=sqrt(n); i++)
			if(prime[i])
				printf("%d ", i*i);
				
		printf("\n");
	}
	printf("Dem trong doan left right");
	while (t--){
		long long l, r;
		scanf("%lld%lld", &l, &r);
		int count = 0;
		int a = sqrt(l);
		if(1ll*a*a!=l)
			++a;
		//for (int i = sqrt(l); i<=sqrt(r); i++)
		for (int i = a; i<=sqrt(r); i++)
			if(prime[i])
				++count;
		printf("%d", count);
	}
	//chú ý trường hợp 5-10 làm tròn xuống căn bậc 2 của 5 vô tình là số nguyên tố 
	
}
