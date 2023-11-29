//Laura Mazer Toporoski RA:23038323


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//protótipo de funções
	float Euclidiana (float a[], float b[], int n);
	float Manhatan(float a[], float b[], int n);


int main (){
	int i, N;
	printf("Insira o tamanho dos vetores: \n");
	scanf("%d", &N);
	float VET1[N], VET2[N];
	printf("Insira os valores do vetor 1:\n");
	for(i=0; i<N; i++){
		scanf("%f", &VET1[i]);
	}
	printf("Insira os valores do vetor 2:\n");
	for(i=0; i<N; i++){
		scanf("%f", &VET2[i]);
	}
	printf("A distancia Euclidiana destes dois vetores:%f\n", Euclidiana(VET1,VET2, N));
	printf ("A distancia Manhatan destes dois vetores:%f\n", Manhatan(VET1, VET2, N));
	return 0;
}

//Distancia Euclidiana
float Euclidiana (float a[],float b[], int n){
	int i;
	float distancia=0;
	for (i=0; i<n; i++) {
		distancia= distancia + pow((a[i]-b[i]),2);
	}
	distancia=sqrt(distancia);
	return distancia;
}

//Distancia de Manhatan
float Manhatan (float a[], float b[], int n) {
	int i;
	float soma=0;
	for (i=0; i<n; i++) {
		soma = soma + abs(a[i]-b[i]);
	}
	return soma;
}