#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int cod;
	char nome[30];
	float nota;
} talu;

int grava_dados() {
	FILE *fp;
	int cg=0;
    talu ralu;
		
	fp=fopen("dados1.dad", "ab");
	if (fp==NULL) {
		printf("Erro na abertura do arquivo\n");
		return -1;
	}
	
	printf("Cod: ");
	scanf("%d", &ralu.cod);
	while (ralu.cod>0) {
        fflush(stdin);
		printf("Nome:");
		gets(ralu.nome);
        fflush(stdin);
		printf("Nota: ");
		scanf("%f", &ralu.nota);
        fwrite(&ralu, sizeof(ralu), 1, fp);
		cg++;
		printf("Cod: ");
		scanf("%d", &ralu.cod);
	} // while
	
	fclose(fp);
	return cg;
}

void mostra_dados() {
    FILE *fp;
    talu ralu;

	fp=fopen("dados1.dad", "rb");
	if (fp==NULL){
		printf("Erro na abertura do arquivo\n");
		exit(-1);
	}
	
    fread(&ralu, sizeof(ralu), 1, fp);
	while (!feof(fp)) {
		printf("Dados lidos: %d %s %.1f\n", ralu.cod, ralu.nome, ralu.nota);
        fread(&ralu, sizeof(ralu), 1, fp);
	}	

    fclose(fp);	
}

int main() {
	int r;
	
	r=grava_dados();
    if (r==-1) 
    	printf("Ocorreu erro na gravação dos dados\n");
	else {
	    printf("Lendo as %d entradas\n", r);
	    mostra_dados();
	}	
	return 0;
}
