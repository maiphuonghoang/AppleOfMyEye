#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ƯỚC NGUYÊN TỐ NHỎ NHẤT CỦA 1 SỐ SỬ DỤNG SÀNG
/*
	Cho số tự nhiên N, in ra ước số nguyên tố nhỏ nhất của các số từ 1 đến N 
	Ước số nguyên tố nhỏ nhất của 1 là 1, của các số chẵn là 2,  của số nguyên tố là chính nó 
	Vd: 6 -> 1 2 3 2 5 2 
		10 -> 1 2 3 2 5 2 7 2 3 2 

*/
int findV1(int n){
	for (int i = 2; i<=sqrt(n); i++)
		if(n%i==0)
			return i;
	return n; //trường hợp n là số nguyên tố 
}
//	prime[i] = 0,1;
//	prime[i]: lưu ước số nguyên tố nhỏ nhất 
int prime[100001];
void seive(){
	//ban đầu coi ước nguyên tố nhỏ nhất của nó là chính nó 
	for (int i = 1; i< 100000; i++)
		prime[i] = i;
	for (int i = 2; i<sqrt(100000); i++)
		if(prime[i] == i)
			for (int j = i*i; j <= 100000; j+=i)
				if(prime[j] == j)
					prime[j] = i; //bội nhỏ nhất của j là i 
				
	/*
	Note i = 2 -> 4 6 8 10 12 gán 2 
		 i = 3 -> 9  12 15 -> 12 lại gán 3 thì sai 
		 thì thêm bước kiểm tra prime[j] đấy nhỏ hơn j hiện tại 
		 để đảm bảo trước đó chưa có ước nguyên tố nhỏ nhất nào gán cho j 
	*/
}
int main(int argc, char *argv[]) {
	seive();
	int t;
	scanf("%d", &t); 
	while(t--){
		int n;
		scanf("%d", &n);
		for (int i = 1; i<=n ;i++)
			printf("%d %d\n",findV1(i), prime[i]);
		
	}
	

}
