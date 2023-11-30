#include <stdio.h>
#include <string.h>

void abertura() {
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}

void chuta(char chutes[], int* tentativas) {
	char chute;
	printf("Qual letra? ");
	scanf(" %c", &chute);

	chutes[*tentativas] = chute;
	(*tentativas)++;
}

int jachutou(char letra, char* chutes, int tentativas) {
	int achou = 0;
	for(int j = 0; j < tentativas; j++) {
		if(chutes[j] == letra) {
			achou = 1;
			break;
		}
	}

	return achou;
}

int enforcou() {
	
	int erros = 0;

	for (int i = 0; i< tentativas; i++){
		int existe = 0;

		for (int j = 0; j<strlen(palavrasecreta); j++){
			if (chutes[i]== palavrasecreta[j]){

				existe = 1;
				break;
			}
		}
		if (!existe) erros ++;
	}
	return erros >=5; 
}

void desenhaforca(char* palavrasecreta, char* chutes, int tentativas) {

	printf("Você já deu %d chutes\n", tentativas);

	for(int i = 0; i < strlen(palavrasecreta); i++) {

		if(jachutou(palavrasecreta[i], chutes, tentativas)) {
			printf("%c ", palavrasecreta[i]);
		} else {
			printf("_ ");
		}

	}
	printf("\n");

}

void escolhepalavra(char* palavrasecreta) {
	sprintf(palavrasecreta, "MELANCIA");
}

int main() {

	char palavrasecreta[20];
	

	int acertou = 0;

	char chutes[26];
	int tentativas = 0;

	abertura();
	escolhepalavra(palavrasecreta);

	do {

		desenhaforca(palavrasecreta, chutes, tentativas);
		chuta(chutes, &tentativas);

	} while (!acertou && !enforcou());

}