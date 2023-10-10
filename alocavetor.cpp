#include <stdio.h>
#include <stdlib.h>

// Função para alocar um vetor de float
float * criavet(int N) {
    float *v;
    v=(float *) malloc(N*sizeof(float));
    return v;
}

void inicia(float *v, int N, float val) {
    int i;
    for (i=0; i<N; i++) v[i]=val;
}

void mostra(float *v, int N) {
    int i;
    printf("Elementos do vetor:\n");
    for (i=0; i<N; i++) printf("%.2f ", v[i]);
}

void libera(float *v) {
    if (v!=NULL) free(v);
}

int main()
{
    float *vet;
    int Tam;
    printf("Informe tamanho vetor: ");
    scanf("%d", &Tam);
    vet=criavet(Tam);
    if (vet==NULL) {
        printf("Erro ao alocar vetor\n");
        exit(-1);
    }    
    inicia(vet, Tam, 10);
    mostra(vet, Tam);
    libera(vet);
    return 0;
}