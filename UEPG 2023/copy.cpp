#include <stdio.h>
#include <stdlib.h>

// Explicação: o que acontece de acordo com a linha de comando
// C:> copy arqa arqb <enter>
// argc = 3
// argv = [copy, arqa, arqb]

int main(int argc, char *argv[]) {
   FILE *fpi, *fpo;
   char c;
   
   if (argc != 3) {
   	  printf("Erro na passagem de argumentos \n");
   	  exit(-1);
   }
   
   // abre arquivo a ser copiado
   fpi=fopen(argv[1], "rb");
   if (fpi==NULL) {
      printf("Erro ao tentar abrir arquivo de entrada\n");
      exit(-1);
   }

   // abre arquivo a ser criado
   fpo=fopen(argv[2], "wb");
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
