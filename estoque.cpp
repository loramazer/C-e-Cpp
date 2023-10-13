// Registro para armazenar dados de produtos de um estoque (codigo, descriçaõ, quantidade,valor,data 
// de aquisição e consumo ultimos 6 meses

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct data {
	int dia, mes, ano;
};
struct prod {
	int codigo;
	char desc;
	float qtd, valor;
	struct data dtaq;
	float consumo[6];
};


