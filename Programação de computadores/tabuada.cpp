#include <stdlib.h>
#include <stdio.h>

//Escreva um algoritmo que recebe um valor e imprima a sua tabuada

void tabuada (int);

int main () {
	int valor;
	printf ("Insira o valor inteiro que deseja fazer a tabuada\n");
	scanf ("%d", &valor );
	tabuada (valor);
	return 0;
}

void tabuada (int valor) {
	int resultado, i;
	if (valor>0) 
		for (i=0; i<=10; i++) {
			resultado=valor*i;
			printf ("%d\n", resultado);
		}
	else printf("Apenas tabuada de valores inteiros positivos");
	
}