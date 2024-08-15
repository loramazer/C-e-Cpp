#include <stdio.h>

// Protótipo da função
int fat(int);

int main() {
	int Num;
	printf("Informa Num:");
	scanf("%d", &Num);
	printf("Fatoria de %d = %d\n", Num, fat(Num));
    return 0;	
}

int fat(int N) {
	if (N<0) return -1;
    if (N==0) return 1;
	else return N*fat(N-1);	
}


