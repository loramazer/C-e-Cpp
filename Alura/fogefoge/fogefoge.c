#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"


struct MAPA m;

void liberamapa(){
    for (int i = 0; i < (m.linhas); i++){
        free((m.matriz)[i]);
    }
    
    free((m.matriz));
}

void alocamapa(){
     (m.matriz) = malloc(sizeof(char*) * (m.linhas));
    for (int i = 0; i < (m.linhas); i++){
        (m.matriz)[i] = malloc(sizeof(char)* (m.colunas) + 1);
    }
}

void lemapa(){
    FILE* f;
    f = fopen("D:\\Github\\C\\Alura\\fogefoge\\mapa.txt", "r");
    if (f==0) {
        printf("Erro na leitura do mapa\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(m.linhas), &(m.colunas));
    alocamapa();

    for (int i = 0; i < 5; i++){
        fscanf(f, "%s", (m.matriz)[i]);
    }
    fclose(f);
}

void imprimemapa() {
    for (int i = 0; i < 5; i++){
        printf("%s\n", (m.matriz)[i]);
    }
}

int acabou() {
    return 0;
}

void move(char direcao) {
    int x = 0; // Initialize x with 0 (top-left corner)
    int y = 0; // Initialize y with 0 (top-left corner)
    int x_at = 0;
    int y_at = 0;
    for (int i = 0; i < m.linhas; i++) {
        for (int j = 0; j < m.colunas; j++) {
            if (m.matriz[i][j] == '@') {
                x_at = i;
                y_at = j;
                x = x_at;
                y = y_at;
                break;
            }
        }
        if (x_at != 0)  // Break the loop if the '@' character is found
            break;
    }

    m.matriz[x_at][y_at] = '.';

    switch (direcao) {
    case 'a':
        y--;
        break;
    case 'w':
        x--;
        break;
    case 's':
        x++;
        break;
    case 'd':
        y++;
        break;
    }

    m.matriz[x][y] = '@';
}
int main (){



    lemapa();

    
    do {
        imprimemapa();

        char comando;
        printf("Digite a direcao que o personagem ira seguir:\n") ;
        scanf("%c", &comando);
        move(comando);

     } while(!acabou());

    liberamapa();
       
}