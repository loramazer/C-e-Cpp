#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main () {
    int tentativas, numero_secreto, numero_grande, nivel, max_tentativas, ganhou=0;    /* Utilizando a função time para sempre obter uma seed diferente para a função rand*/

    srand(time(NULL));
    numero_grande = rand() ;
    numero_secreto = numero_grande % 100; /*resultado desta conta vai sempre dar um numero entre 0 e 99*/

printf("Escolha o nivel que quer jogar: \n");
printf("(1) Facil    (2)Medio    (3)Dificil\n");
scanf("%d", &nivel);
    switch (nivel){
        case 1: max_tentativas = 20; break;
        case 2: max_tentativas = 10; break;
        case 3: max_tentativas = 6; break;
        default: printf("Escolha incorreta!");
    }

    for (tentativas=0; tentativas<max_tentativas; tentativas ++) {
        int chute;
        printf ("------------------------------\n");
        printf("Tentativa %d\n", tentativas+1);
        printf ("Escreva um numero entre 0 e 99: \n");
        scanf ("%d", &chute);
            if (chute>0){
                if (chute == numero_secreto){
                    printf("Voce acertou em %d tentativas!\n", tentativas+1);
                    ganhou = 1;
                    break;
                }
                else if (chute < numero_secreto){
                    printf("Seu chute foi menor que o numero secreto!\n");
                }
                else {
                printf("Seu chute foi maior que o numero secreto!\n");
                }
            }
            else {
                printf("Voce digitou um numero invalido! O numero secreto eh positivo\n");
                tentativas--;   
            }
    }
    if (!ganhou){
        printf("Você perdeu! O número secreto era %d\n", numero_secreto);
    }
    return 0;



}