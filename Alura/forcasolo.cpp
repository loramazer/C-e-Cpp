#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Tam 100

int main() {
		char Palavra[Tam], Chute[Tam], Letra;
		int aux, acertou, tentativas=0, acertos=0, tamanho;
		
		//jogador 1 escolhe palavra
		printf ("Jogo da Forca!!\n");
		printf("Jogador 1, insira a palara:");
		gets(Palavra);
		tamanho=strlen(Palavra);
		
		
		for(aux=0; aux<tamanho; aux++){
			Chute[aux]='_';
		}		
		Chute[aux]='\0';
		
		
		while (tentativas<6 && acertos<tamanho){
			//letra
			printf("\n JOGO DA FORCA\n");
			printf("%s", Chute);
			printf("  Tentativas restantes: %d\n", 6-tentativas);
			printf("Digite uma letra: ");
			scanf("%c", &Letra);
			
			acertou=0;
			for (aux=0; aux<tamanho; aux++) {
				//verifica se acertou
				if (Palavra[aux]==Letra && Chute[aux]!=Letra){
					Chute[aux]=Letra;
					acertos++;
					acertou=1;
				}
			}
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