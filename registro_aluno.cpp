#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

// registro aluno via criação de tipo
typedef struct {
   int cod;
   char nome[50];
   float nota;        
} taluno;

// vetor representando uma tabela de alunos, ou vetor de registros
taluno cadalu[N];

// função para preenchimento da tabela alunos
int entrada(taluno cadalu[], int ind) {
   int cod; 
   system("cls");
   printf("Cod: ");
   scanf("%d", &cod);
   while (cod != 0 && ind < N) {
      cadalu[ind].cod=cod;
      printf("Nome do Aluno: ");
      fflush(stdin);
      gets(cadalu[ind].nome);
      fflush(stdin);
      printf("Nota: ");
      scanf("%f", &cadalu[ind].nota);     
      ind++;
      printf("Cod: ");
      scanf("%d", &cod);
   }
   return ind;         
}

// Mostra os alunos constantes na tabela
void mostra(taluno cadalu[], int ind) {
   int i;
   system("cls");
   printf("Cod       Nome                Nota \n");
   for(i=0; i<ind; i++)
     printf("%3d  %-30s   %5.2f\n", cadalu[i].cod,
                               cadalu[i].nome,
                               cadalu[i].nota);     
   system("pause");  
}

// Ordena a tabela por nome de aluno
void ordena(taluno v[], int ind) {
    int i, j;
    taluno aux; 
    for(i=0; i<ind-1; i++)
      for(j=i+1; j<ind; j++)
          if (strcmpi(v[i].nome, v[j].nome)>0) {
              aux=v[i];
              v[i]=v[j];
              v[j]=aux;
          }     
     
}

// Menu de opções
int main() {
   int ind=0, op; 
   do {
      system("cls");
      printf("Menu\n");
      printf("1 - Cadastro de alunos\n");
      printf("2 - Lista casdastro de alunos\n");
      printf("3 - Ordena cadastro alunos por nome\n");
      printf("4 - Encerra\n");
      printf("Informe sua escolha: ");
      scanf("%d", &op);
      switch (op) {
         case 1:  ind=entrada(cadalu, ind); break;   
         case 2:  mostra(cadalu, ind); break;
         case 3:  ordena(cadalu, ind); break;
         case 4:  break;
         default: printf("Escolha incorreta\n");
      }  
   } while (op!=4);    
   return 0;
}



