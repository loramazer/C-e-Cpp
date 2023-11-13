//Laura Mazer Toporoski RA:23038323


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 11

int verificaCPF(int a[]) {
    int i, verif = 0, dig1, dig2, X = 0;
    for (i = 0; i < 9; i++) {
        verif = verif + (a[i] * (i + 1));
    }
    dig1 = verif % 11;
    if (dig1 == 10)
        dig1 = 0;
    for (i = 0; i < 10; i++) {
        verif = verif + (a[i] * i);
    }
    dig2 = verif % 11;
    if (dig2 == 10)
        dig2 = 0;
    if (a[9] == dig1 && a[10] == dig2)
        X = 1;
    return X;
}

int main() {
    int CPF[N], i;
    printf("Insira o cpf (apenas os numeros): ");
    for (i = 0; i < N; i++) {
        scanf("%1d", &CPF[i]);
    }

    if (verificaCPF(CPF) == 1) {
        printf("O CPF informado eh valido!!\n");
    } else {
        printf("O CPF informado eh invalido!!\n");
    }
    return 0;
}
