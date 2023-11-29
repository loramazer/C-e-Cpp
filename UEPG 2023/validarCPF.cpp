//Laura Mazer Toporoski RA:23038323


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 11

int verificaCPF(char a[]) {
    int i, verif = 0, dig1, dig2, X = 0;

    // Verifica se todos os dígitos são iguais
    int todosIguais = 1;
    for (i = 1; i < N; i++) {
        if (a[i] != a[i - 1]) {
            todosIguais = 0;
            break;
        }
    }

    if (todosIguais == 0) {
        for (i = 0; i < 9; i++) {
            verif = verif + (a[i] - '0') * (i + 1);
        }

        dig1 = verif % 11;
        if (dig1 == 10)
            dig1 = 0;

        verif = 0;

        for (i = 0; i < 10; i++) {
            verif = verif + (a[i] - '0') * i;
        }

        dig2 = verif % 11;
        if (dig2 == 10)
            dig2 = 0;

        if ((a[9] - '0') == dig1 && (a[10] - '0') == dig2) {
            X = 1;
        }
    }

    return X;
}

int main() {
    char CPF[N + 1]; // +1 para o caractere nulo '\0'
    
    printf("Insira o CPF (apenas os numeros): ");
    scanf("%11s", CPF); // Garantir que a leitura não ultrapasse o tamanho do array
    
    if (strlen(CPF) == 11) {
        CPF[N] = '\0'; // Adicionar explicitamente o caractere nulo ao final da string

        if (verificaCPF(CPF)) {
            printf("O CPF informado eh valido!!\n");
        } else {
            printf("O CPF informado eh invalido!!\n");
        }
    } else {
        printf("O CPF informado deve conter exatamente 11 digitos!!\n");
    }

    return 0;
}
