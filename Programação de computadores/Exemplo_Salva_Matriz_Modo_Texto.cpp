#include <stdio.h>
#include <stdlib.h>

// Registro com um ponteiro para matriz bem como suas dimensões
typedef struct {
	int **mat;
	int N, M;
} treg;

// Declaração de 2 registros do tipo treg
treg r, s;

// Alocação da matriz
int **criamat(int N, int M) {
	int **x, i, j;
	x=(int **)malloc(N*sizeof(int*));
    if (x==NULL) return NULL; 
	for (i=0; i<M; i++) {
       x[i]= (int *) malloc(M*sizeof(int));
       if (x[i]==NULL) return NULL;
    }
	
	// inicializa a matriz com o valor de i
	for(i=0; i<N; i++)
	   for(j=0; j<M; j++) x[i][j]=i;
	  
    return x;
}

// Mostra uma matriz
void mostra(int **x, int N, int M) {
	int i, j;
	for (i=0; i<N; i++) {
		for (j=0; j<M; j++) printf("%d ", x[i][j]);
		printf("\n");
	}

}

// Salvando dados do registro (inclusive a matriz) em arquivo texto
void salva (char filename[]) {
    int i, j;
	FILE *fp;
	fp=fopen(filename, "w");
	if (fp==NULL) {
		printf("Erro ao abrir arquivo \n");
		exit(-1);
	}
    fprintf(fp,"%d,%d\n", r.N, r.M);
    for(i=0; i<r.N; i++) {
       for(j=0; j<r.M; j++) fprintf(fp, "%d ", r.mat[i][j]);	
       fprintf(fp, "\n");     	
	}
    fclose(fp);	
}

// Carregando a matriz do arquivo
void carrega(char filename[]) {
    int i, j;
	FILE *fp;
	fp=fopen(filename, "r");
	if (fp==NULL) {
		printf("Erro ao abrir arquivo \n");
		exit(-1);
	}
    fscanf(fp,"%d,%d\n", &s.N, &s.M);
 	s.mat = criamat(s.N, s.M);
    for(i=0; i<s.N; i++) {
       for(j=0; j<s.M; j++) fscanf(fp, "%d ", &s.mat[i][j]);	
       fscanf(fp, "\n");     	
	}
    fclose(fp);	
}

// Função main
int main() {
	char name[100];
	printf("Informe nome arquivo: ");
	scanf("%s", &name);
	
	// Dimensões da matriz (3x4)
	r.N=3;
	r.M=4;
	// aloca a matriz
	r.mat = criamat(r.N, r.M);
    printf("Mostrando a matriz criada\n");
	mostra(r.mat, r.N, r.M);
	// salva matriz no disco
    salva(name);
    // carrega matriz do disco
    carrega(name);
    printf("Mostrando a matriz carregada do arquivo\n");
	mostra(s.mat, s.N, s.M);
	return 0;
}

