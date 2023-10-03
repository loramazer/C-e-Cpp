#include <stdio.h>

int fibo(int);

int main() {
  int termo;
  printf("Informe termo: ");
  scanf("%d", &termo);
  printf("O termo %d de Fibonacci eh %d\n", termo, fibo(termo));
  return 0;
}

int fibo(int N){
	if (N==1 || N==2) return 1;
	return fibo(N-1) + fibo(N-2);
}
