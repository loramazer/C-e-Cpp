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

// Carrega contatos do disco e acrescenta 1000 entradas vazias na agenda.
tcontato * leitura(const char filename[], int *qc) {
    FILE *fp;
    tcontato *v;
    int i;
    long tb; //total de bytes
    fp=fopen(filename, "rb");
    if (fp==NULL) { *qc=0; tb=0;}
    else {
        fseek(fp, 0, SEEK_END);
        tb=ftell(fp);  
        *qc=tb/sizeof(tcontato); 
        fseek(fp, 0, SEEK_SET);
    }
    tb=tb+ 1000*sizeof(tcontato);  // adicionando 1000 espa�os no vetor 
    v=(tcontato *) malloc(tb);
    
    for(i=0; i<*qc; i++) {
        fread(&v[i], sizeof(tcontato), 1, fp);         
    }
    
    if (fp) fclose(fp);
    return v;
}

// Permite incluir contatos. Encerra com "fim".
int incluir(tcontato *v, int *qc) {
    char nome[50];
    int i;
    printf("Nome: ");
    fflush(stdin);
    gets(nome);
    i=*qc;
    while (strcmpi(nome, "fim") !=0 && i<*qc+1000) {
        strcpy(v[i].nome, nome);
        printf("Fone: "); gets(v[i].fone); 
        fflush(stdin); 
        printf("Data Nascimento: ");
        scanf("%d/%d/%d", &v[i].dtnasc.dia,&v[i].dtnasc.mes, &v[i].dtnasc.ano); 
        i++;
        fflush(stdin);
        printf("Nome: "); gets(nome);   
    }
    *qc=i;
    return 0;
}

void trocacontato (tcontato *menor, tcontato *maior) {
  tcontato temp= *menor;
  *menor = *maior;
  *maior = temp;
}

int ordena (tcontato *v, int qc) {
  int i, j;
  tcontato temp;
  for (i=0; i<qc-1; i++){
    for (j=0; j<qc-1-i; j++){
      if ((strcmpi(v[j].nome, v[j + 1].nome))>0){
        trocacontato(&v[j], &v[j+1]);
    }
  }
  }

}

// Salva a agenda em disco. Somente entradas preenchidas.
int salvar(const char filename[], tcontato *v, int *qc) {
   FILE *fp;
   int i;
   ordena(&v, qc);
   fp=fopen(filename, "wb");
   if (fp==NULL) return -1;
   
   for(i=0; i<*qc; i++) 
     fwrite(&v[i], sizeof(tcontato), 1, fp);
    
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

int excluir(tcontato *v, int *qc){

}

// Fun��o principal.
int main() {
  int qc, op; //qntd de contatos
  tcontato *agenda;  
  agenda = leitura("C:\\Agenda.dad", &qc); 
  do {
    system ("cls");
    printf ("Menu\n");
    printf ("1- Inserir novos contatos.\n");
    printf ("2- Listar todos os contatos.\n");
    printf ("3 - Excluir um contato\n");
    printf ("4 - Salvar alterações na sua agenda\n");
    printf ("5 - Sair da Agenda\n");
    printf ("Escolha uma opcao:\n");
    scanf ("%d", &op);
    switch (op) {
      case 1: incluir(agenda, &qc); break;
      case 2: listar (agenda, &qc); break;
      case 3: excluir(agenda, &qc); break;
      case 4: salvar("C:\\Agenda.dad", agenda, &qc); break;
      case 5: break;
      default: printf ("Escolha incorreta\n");
  }
}
while (op != 4);
return 0;
}
