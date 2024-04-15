#define CIMA 'w'
#define BAIXO 's'
#define  ESQUERDA 'a'
#define DIREITA 'd'

int ehdirecao (char direcao);
int acabou();
void move(char direcao);
void fantasmas();
int praondefantasmavai (int xatual, int yatual, int* xdestino, 
 int*  ydestino);