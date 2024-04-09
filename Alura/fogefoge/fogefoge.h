void liberamapa();
void lemapa();
void alocamapa();
int acabou();
void move(char direcao);
void imprimemapa();

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};