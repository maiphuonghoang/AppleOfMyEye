#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	NGUYÊN TỐ CÙNG NHAU 
	Một cặp số (i, j) được gọi là nguyên tố cùng nhau nếu i#j và 
	ước số chung lớn nhất của i và j là 1
	Hãy liệt kê các cặp số nguyên tố cùng nhau trong đoạn [a,b] theo thứ tự từ nhỏ đến lớn 
	5,8 	(5,6) (5,7) (5,8) (6,7) (7,8)
	
*/
int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main(int argc, char *argv[]) {
	printf("%d", gcd(4,24));
	printf("%d", gcd(24,4));
	printf("\nnhap a va b");
	int a, b;
	scanf("%d%d", &a, &b);
	printf("\nresult");
	for (int i=a; i<b; i++)
		for (int j= i + 1; j<=b; j++)
			if(gcd(a, b)==1)
				printf("(%d%d)\n", i,j);
}
