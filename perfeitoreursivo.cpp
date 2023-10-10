//Função que verifica se o número inteiro é perfeito
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool perfeito (int Num) {
	int i, soma=0;
	for (i=1; i<Num; i++) {
		if (Num%i==0) 
			soma=soma+i;
	}
	if (soma==Num) {
		return true;
	}
	return false;
}
int main () {
	int N;
	printf ("Insira o numero inteiro que deseja verificar se pertence aos perfeitos: \n");
	scanf ("%d", &N);
	if (perfeito(N))
		printf("O numero eh perfeito");
	else printf ("O numero nao eh perfeito\n");
	return 0;
}