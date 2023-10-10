// Aloca matriz dinamicamente
#include <stdio.h>
#include <stdlib.h>

// aloca matriz dinamicamente (exemplo com float)
float **criamat(int N, int M) {
    float **v;
    int i;
    v=(float **) malloc(N*sizeof(float *));
    if (v==NULL) return NULL;
    for(i=0; i<N; i++) {
        v[i]=(float *) malloc(M*sizeof(float));
        if (v[i]==NULL) return NULL;
    }
    return v;    
}

void inicializa(float **v, int N, int M, float val) {
    int i, j;
    for(i=0;i<N;i++)
      for(j=0;j<M;j++) v[i][j]=val;
}

void mostra(float **v, int N, int M) {
    int i, j;
    for(i=0; i<N; i++) {
        for(j=0;j<M;j++) printf("%5.2f ", v[i][j]);
        printf("\n");
    }
}

void libera(float **mt, int N) {
    int i;
    if (mt==NULL) return;
    for(i=0; i<N; i++) if (mt[i]!=NULL) free(mt[i]);
    free(mt);
}

int main() {
    float **mat;
    int NL, NC;
    printf("Informe tamanho da matriz: ");
    scanf("%d %d", &NL, &NC);
    mat=criamat(NL, NC);
    if (mat==NULL) {
        printf("Erro ao alocar matriz\n");
        exit(-1);
    }
    inicializa(mat,NL, NC, 3.2);
    mostra(mat, NL, NC);
    libera(mat, NL);
    return 0;    
}