#include <stdio.h>
#include <stdlib.h>

// exemplo registro contendo uma matriz (tabuleiro) e dados adicionais
typedef struct {
	int N, M;   // dimensões
	int mat[3][4];  // matriz
	int score;      // score atual
} treg;


int main() {
	FILE *fp;
	char nome[30];
	int i, j;
	
	// declarando o registro
	treg tab, tab_loaded;
	
	// inicializando o registro
	tab.N=3;
	tab.M=4;
	for(i=0; i<tab.N; i++)
	   for(j=0; j<tab.M; j++)
			tab.mat[i][j]=1;
	tab.score=5;
	
	// salvar o registro tab
	printf("Informe nome para salvar o arquivo: ");
	scanf("%s", &nome);
	fp=fopen(nome, "wb");
	if (fp==NULL) {
		printf("Erro ao criar arquivo\n");
		exit(-1);
	}
    fwrite(&tab, sizeof(tab), 1, fp);
	fclose(fp);
		
	// carregar o registro salvo no artigo 
	printf("Informe o nome do artigo a ser carregado: ");
	scanf("%s", &nome);
	fp=fopen(nome, "rb");
	if (fp==NULL) {
		printf("Erro ao abrir arquivo\n");
		exit(-1);
	}
	fread(&tab_loaded, sizeof(tab_loaded), 1, fp);
	fclose (fp);
	
	// Mostrando dados carregados
	printf("N: %d\n", tab_loaded.N);
	printf("M: %d\n", tab_loaded.M);
	printf("Score: %d\n", tab_loaded.score);
	for(i=0; i<tab_loaded.N; i++) {
		for(j=0; j<tab_loaded.M; j++) printf("%d ", tab_loaded.mat[i][j]);
		printf("\n");
    }
    
    return 0;
}
