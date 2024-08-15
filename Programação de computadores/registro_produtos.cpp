#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

//registro produto
typedef struct {
	int cod;
	float qtde, valor, consumo[6];
	char desc[50];
}tproduto;

tproduto produto[N];

int entrada(tproduto produto[N], int ind) {
	int cod;
	system("cls");
	printf("Cod: ");
    scanf("%d", &cod);
   while (cod != 0 && ind < N) {
      produto[ind].cod=cod;
      printf("Descrição do produto: ");
      fflush(stdin);
      gets(produto[ind].desc);
      fflush(stdin);
      printf("Quantidade: ");
      scanf("%f", &produto[ind].qtde);     
      printf("Valor: ");
      scanf("%f", &produto[ind].valor);
	  ind++;
      printf("Cod: ");
      scanf("%d", &cod);
   }
   return ind; 
}


void mostra(tproduto produto[], int ind) {
   int i;
   printf("Cod       Descrição              Quantidade      Valor       Consumo ultimos 6 meses      \n");
   for(i=0; i<ind; i++)
     printf("%3d  %-30s   %5.2f   %5.2f   %5.2f\n", produto[i].cod,
                               produto[i].desc,
                               produto[i].qtde,
							   produto[i].valor,
							   produto[i].consumo[6]);     
   system("pause");  
}


void ordena(tproduto v[], int ind) {
    int i, j;
    tproduto aux; 
    for(i=0; i<ind-1; i++)
      for(j=i+1; j<ind; j++)
          if (strcmpi(v[i].desc, v[j].desc)>0) {
              aux=v[i];
              v[i]=v[j];
              v[j]=aux;
          }    
}

int main() {
   int ind=0, op; 
   do {
      printf("Menu\n");
      printf("1 - Cadastro de produtos\n");
      printf("2 - Lista casdastro de produtos\n");
      printf("3 - Ordena cadastro produtos por descrição\n");
      printf("4 - Encerra\n");
      printf("Informe sua escolha: ");
      scanf("%d", &op);
      switch (op) {
         case 1:  ind=entrada(produto, ind); break;   
         case 2:  mostra(produto, ind); break;
         case 3:  ordena(produto, ind); break;
         case 4:  break;
         default: printf("Escolha incorreta\n");
      }  
   } while (op!=4);    
   return 0;
} 
