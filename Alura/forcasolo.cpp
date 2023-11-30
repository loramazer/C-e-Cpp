#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Tam 100

void escolha_palavra (char Palavra[Tam]) {
		printf ("Jogo da Forca!!\n");
		printf("Jogador 1, insira a palara:");
		gets(Palavra);
}

void chuta(int *tentativas, char Chute[Tam], char Letra) {
			printf("\n JOGO DA FORCA\n");
			printf("%s", Chute);
			printf("  Tentativas restantes: %d\n", 6-(*tentativas));
			printf("Digite uma letra: ");
			scanf("%c", &Letra);
}

void acertou (char Palavra[aux], char Letra, char Chute[aux], int *acertos){
	if (Palavra[aux]==Letra && Chute[aux]!=Letra){
		Chute[aux]=Letra;
		*acertos++;
		break;
	}
			}
}
int main() {
		char Palavra[Tam], Chute[Tam], Letra;
		int aux, acertou, tentativas=0, acertos=0, tamanho;
		
		//jogador 1 escolhe palavra
		escolha_palavra(Palavra);
		tamanho=strlen(Palavra);
		
		
		for(aux=0; aux<tamanho; aux++){
			Chute[aux]='_';
		}		
		Chute[aux]='\0';
		
		
		while (tentativas<6 && acertos<tamanho){
			//letra
			chuta(&tentativas, Chute, Letra);
			
			acertou=0;
			for (aux=0; aux<tamanho; aux++) {
				//verifica se acertou
				acertou (char Palavra[aux], char Letra, char Chute[aux], int *acertos)
				if(!acertou){
					printf("\nPalavra nao possui essa letra\n");
					tentativas++;
				}
			
		}
		if (acertos==tamanho)
			printf("Parabens!!!");
		else printf("Suas tentativas acabaram.");

		return 0;	
}