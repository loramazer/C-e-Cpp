#include <stdlib.h>
#include <stdio.h>
int fatorial (int);
int fibonacci (int);
float maiorvalor(float [], int);
float somavet(float [], int);

int main (){
	int n, i, N=5;
	float V;
	printf ("Insira um numero inteiro: \n");
	scanf("%d", &n);
	printf ("o fatorial deste numero: %d\n", fatorial(n));
	printf ("o enesimo numero da sequencia fibonacci: %d\n", fibonacci(n));
	printf ("o maior valor deste vetor: %f\n", maiorvalor(V, 5));
	printf ("a soma dos numeros deste vetor: %f\n", somavet(V, 5));
	return 0;
}

int fatorial (int n) {
	if (n==0)
		return 1;
	else 
		return (n*fatorial(n-1));
}

int fibonacci (int n) {
	if (n==1 || n==2)
		return 1;
	else return (fibonacci(n-1)+fibonacci(n-2));
}
float maiorvalor (float V[], int N) {
	float aux;
	if(N==1)
		return V[0];
	aux=maiorvalor(V, N-1);
	if (aux>V[N-1])
		return aux;
	else return (V[N-1]);
}
float somavet (float V[], int tamanho) {
	//criterio de parada 
	if (tamanho==0) return 0;
	//caso recursivo soma o elemento atual com a soma dos restantes
	return V[tamanho-1]+somavet(V, tamanho-1);
}

