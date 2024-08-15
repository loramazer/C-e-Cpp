#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fpi, *fpo;
   char c;
   char stri[50], stro[50];
   printf("Arquivo a ser copiado: ");
   scanf("%s", &stri);
   printf("Arquivo destino: ");
   scanf("%s", &stro);
   // abre arquivo a ser copiado
   fpi=fopen(stri, "rb");
   if (fpi==NULL) {
      printf("Erro ao tentar abrir arquivo de entrada\n");
      exit(-1);
   }

   // abre arquivo a ser criado
   fpo=fopen(stro, "wb");
   if (fpo==NULL) {
      printf("Erro ao tentar abrir arquivo destino\n");
      exit(-2);
   }

   // lê arquivo de entrada e grava o arquivo destino
   c=fgetc(fpi);
   while (!feof(fpi)) {
       fputc(c, fpo);
       c=fgetc(fpi);
   }

   // fecha os arquivos
   fclose(fpi);
   fclose(fpo);
   return 0;
}
