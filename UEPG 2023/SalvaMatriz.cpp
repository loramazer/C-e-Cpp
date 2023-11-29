#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Cria uma matriz alocada dinamicamente
int **CriaMatriz(int N, int M) {
	int **mat, i;
	
	mat=(int **) malloc(N*sizeof(int *));
	if (mat==NULL) {
		printf("Erro ao alocar memória\n");
		return NULL;
	} 
	for(i=0; i<N; i++) {
		mat[i]=(int *) malloc(M*sizeof(int));
		if (mat[i]==NULL) {
			printf("Erro ao alocar memória\n");
			return NULL;
		}
	}
	return mat;	
}

// Mostra a matriz
void mostra(int **X, int N, int M){
	int i, j;
	printf("\nMatriz \n");
	for(i=0; i<N; i++){
		for(j=0; j<M; j++) printf("%3d ", X[i][j]);
		printf("\n");
	}
}

// Inicializa a matriz com valores entre 0 e 99 aleatoriamente
void inicializa(int **X, int N, int M){
	int i, j;
	srand(time(NULL));
	for(i=0; i<N; i++)
	  for(j=0; j<M; j++) X[i][j]=rand() % 100;
}

// Salva a matriz (toda de uma vez) ou (linha a linha)
int salva(int **X, int N, int M){ 
	FILE *fp;
	int i;
	fp=fopen("matriz.dad", "wb");
	if (fp==NULL) return -1;

//  Exemplo salvando a matriz toda de uma vez
//	fwrite(X, N*M*sizeof(int), 1, fp);
    
// Exemplo salvando linha a linha
    for (i=0; i<N; i++) 
        fwrite(X[i], M*sizeof(int), 1, fp);

    fclose(fp);
    return 0;
}

// Carrega a matriz (toda de uma vez) ou (linha a linha)
int **carrega(int N, int M){
	FILE *fp;
	int **X, i;
	X=CriaMatriz(N, M);
	if (X==NULL) return NULL;
	fp=fopen("matriz.dad", "rb");
	if (fp==NULL) return NULL;

// Exemplo lendo a matriz toda de uma vez
//	fread(X, N*M*sizeof(int), 1, fp);

// Exemplo lendo linha a linha
    for (i=0; i<N; i++) 
        fread(X[i], M*sizeof(int), 1, fp);

	fclose(fp);
	return X;
}


// Função principal que utiliza as funções acima
int main() {
	int **A, QL, QC, ret;
	printf( "Informe tamanho matriz NxM: ");
	scanf("%dx%d", &QL, &QC);
	A=CriaMatriz(QL, QC);
    if (A==NULL) {
    	printf("Erro memória \n");
    	return -1;
	}
	inicializa(A, QL, QC);
	mostra(A,QL, QC);
	ret = salva(A, QL, QC);
	if (ret == -1) {
		printf(" Erro ao salvar a matriz\n");
		return -2;
	}
	A = carrega(QL, QC);
	if (A==NULL) {
		printf("Erro ao carregar a matriz\n");
		return -3;
	}
	printf("\n\nDados lidos do arquivo\n");
	mostra(A, QL, QC);
	return 0;
}



 
