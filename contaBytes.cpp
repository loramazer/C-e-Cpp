#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fpi;
   char c;
   char stri[100];
   int cont;
   
   printf("Arquivo a ser lido: ");
   scanf("%s", &stri);
 
   // abre arquivo a ser lido
   fpi=fopen(stri, "rb");
   if (fpi==NULL) {
      printf("Erro ao tentar abrir arquivo de entrada\n");
      exit(-1);
   }

   // lê arquivo e conta bytes
   c=fgetc(fpi);
   cont=0;
   while (!feof(fpi)) {
       cont++;
       c=fgetc(fpi);
   }

   // fecha o arquivo
   fclose(fpi);
   
   printf("Total de bytes lidos = %d\n", cont); 
   return 0;
}
