#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Registro data
typedef struct {
   int dia,mes,ano;         
} tdata;

// Registro contatos
typedef struct {
   char nome[50];
   char fone[20];
   tdata dtnasc;    
//  char sit; 
} tcontato;

// Leitura dos contatos
tcontato *leitura(const char filename[], int *qc) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Arquivo não encontrado. Criando um novo arquivo...\n");
        *qc = 0;

        // Tentativa de criar um novo arquivo se ele não existir
        FILE *newFile = fopen(filename, "wb");
        if (newFile == NULL) {
            printf("Não foi possível criar um novo arquivo.\n");
            return NULL;
        }
        fclose(newFile);

        // Agora tentamos abrir o arquivo novamente
        fp = fopen(filename, "rb");
        if (fp == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return NULL;
        }
    }

    fseek(fp, 0, SEEK_END);
    long tb = ftell(fp);
    *qc = tb / sizeof(tcontato);
    fseek(fp, 0, SEEK_SET);

    tcontato *v = (tcontato *)malloc((*qc + 1000) * sizeof(tcontato));
    if (v == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(v, sizeof(tcontato), *qc, fp);
    fclose(fp);
    return v;
}


// Função para incluir contatos
int incluir(tcontato *v, int *qc) {
    char nome[50];
    int i = *qc;

    printf("Nome: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove a quebra de linha lida pelo fgets

    while (strcmpi(nome, "fim") != 0 && i < *qc + 1000) {
        strcpy(v[i].nome, nome);

        printf("Fone: ");
        fgets(v[i].fone, sizeof(v[i].fone), stdin);
        v[i].fone[strcspn(v[i].fone, "\n")] = '\0'; // Remove a quebra de linha

        printf("Data Nascimento (DD/MM/AAAA): ");
        scanf("%d/%d/%d", &v[i].dtnasc.dia, &v[i].dtnasc.mes, &v[i].dtnasc.ano);

        getchar(); // Limpar o buffer do \n deixado pelo scanf

        i++;

        printf("Nome: ");
        fflush(stdin);
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0'; // Remove a quebra de linha
    }
    *qc = i;
    return 0;
}

void trocacontato (tcontato *menor, tcontato *maior) {
  tcontato temp= *menor;
  *menor = *maior;
  *maior = temp;
}

// Função para ordenar os contatos
int ordena(tcontato *v, int qc) {
    int i, j;
    for (i = 0; i < qc - 1; i++) {
        for (j = 0; j < qc - 1 - i; j++) {
            if (strcmpi(v[j].nome, v[j + 1].nome) > 0) {
                trocacontato(&v[j], &v[j + 1]);
            }
        }
    }
    return 0;
}

// Função para salvar contatos
int salvar(const char filename[], tcontato *v, int *qc) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) return -1;

    ordena(v, *qc);

    fwrite(v, sizeof(tcontato), *qc, fp);
    fclose(fp);
    return 0;
}

// Lista a agenda.
void listar(tcontato *v, int *qc){
    int i;
    for(i=0; i<*qc; i++) 
      printf("%-30s  %-20s  %d/%d/%d\n", v[i].nome, v[i].fone, 
      v[i].dtnasc.dia,
      v[i].dtnasc.mes,
      v[i].dtnasc.ano);

    system("pause");
}


int excluir(tcontato *v, int *qc) {
    char nomeExcluir[50];
    int i, encontrado = 0;

    printf("Digite o nome do contato que deseja excluir: ");
    fflush(stdin);
    fgets(nomeExcluir, sizeof(nomeExcluir), stdin);
    nomeExcluir[strcspn(nomeExcluir, "\n")] = '\0'; // Remove a quebra de linha

    for (i = 0; i < *qc; i++) {
        if (strcmpi(v[i].nome, nomeExcluir) == 0) {
            encontrado = 1;
            // Sobrescrever o contato encontrado com o último contato na lista e diminuir o contador de contatos (*qc)
            v[i] = v[*qc - 1];
            (*qc)--;
            printf("Contato '%s' excluído com sucesso!\n", nomeExcluir);
            break;
        }
    }

    if (!encontrado) {
        printf("Contato '%s' não encontrado na agenda.\n", nomeExcluir);
    }

    return 0;
}



// Função principal
int main() {
    int qc, op;
    tcontato *agenda;
    agenda = leitura("C:\\Agenda.dad", &qc);

    if (agenda == NULL) {
        printf("Erro ao abrir a agenda.\n");
        return -1;
    }

    do {
        system("cls");
        printf("Menu\n");
        printf("1- Inserir novo contato.\n");
        printf("2- Listar todos os contatos.\n");
        printf("3- Excluir um contato.\n");
        printf("4- Salvar alterações na agenda.\n");
        printf("5- Sair da Agenda.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                incluir(agenda, &qc);
                break;
            case 2:
                listar(agenda, &qc);
                break;
            case 3:
                excluir(agenda, &qc);
                break;
            case 4:
                salvar("D:\\", agenda, &qc);
                break;
            case 5:
                break;
            default:
                printf("Escolha incorreta.\n");
        }
    } while (op != 5);

    free(agenda); // Liberar a memória alocada
    return 0;
}
