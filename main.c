#include <stdio.h>
#include <stdlib.h>

void calculo() {
    int primeiro_valor = 0;
    int segundo_valor = 0;
    char conta = '\0';

    printf("Digite o primeiro valor (ou a conta completa ex: 10 + 5):\n> ");

    if (scanf("%i", &primeiro_valor) != 1) {
        return;
    }

    int proximo = getchar();

    // Se apertou Enter, vai para o modo passo a passo
    if (proximo == '\n') {
        printf("Selecione o tipo de conta (+, -, *, /): ");
        scanf(" %c", &conta);

        char proximo_segundo = getchar();

        if (proximo_segundo == '\n') {
            printf("Selecione o segundo valor: ");
            scanf("%i", &segundo_valor);
        } else {
            if (proximo_segundo == ' ') {
                scanf("%i", &segundo_valor);
            } else {
                ungetc(proximo_segundo, stdin);
                scanf("%i", &segundo_valor);
            }
        }
    }
    else {
        // Modo na mesma linha (ex: "10 + 5")
        if (proximo == ' ') {
            scanf(" %c", &conta);
        } else {
            conta = proximo;
        }
        scanf("%i", &segundo_valor);
    }

    // Processamento do resultado
    if (conta == '/') {
        if (segundo_valor == 0) {
            printf("\nErro: Divisao por zero!\n");
        } else {
            printf("\nO resultado vale %i\n", primeiro_valor / segundo_valor);
        }
    }
    else if (conta == '*') {
        printf("\nO resultado vale %i\n", primeiro_valor * segundo_valor);
    }
    else if (conta == '-') {
        printf("\nO resultado vale %i\n", primeiro_valor - segundo_valor);
    }
    else if (conta == '+') {
        printf("\nO resultado vale %i\n", primeiro_valor + segundo_valor);
    }
    else {
        printf("\nOperacao invalida!\n");
    }
}

int main() {
    char continuidade = 's';

    while (continuidade == 's' || continuidade == 'S') {
        calculo();

        printf("\nDeseja continuar calculando? S/N: ");
        scanf(" %c", &continuidade);
    }

    printf("\nPrograma encerrado.\n");
    return 0;
}
