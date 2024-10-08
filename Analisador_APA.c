#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 10000

int main() {
    int qtd_void = 0, qtd_int = 0, qtd_float = 0, qtd_double = 0, qtd_char = 0,
        qtd_if = 0, qtd_else = 0, qtd_case = 0, qtd_printf = 0, qtd_scanf = 0,
        qtd_funcao = 0, qtd_for = 0, qtd_while = 0, qtd_do = 0, soma = 0;
    int profundidade_for = 0, profundidade_while = 0, complexidade_melhor = 0, complexidade_pior = 0;
    int probabilidade = 0, paralelismo = 0, np_completude = 0, geometrico = 0, busca = 0, ordenacao = 0;
    clock_t t;
    char linha[1000];
    char n_arquivo[100];
    FILE *arq;

    
    printf("Digite o nome do arquivo a ser analisado: ");
    scanf("%s", n_arquivo);

    arq = fopen(n_arquivo, "r");
    if (arq == NULL) {
        printf("\nNao foi possivel abrir o arquivo %s\n", n_arquivo);
        exit(1);
    } else {
        t = clock();
        while (fgets(linha, 1000, arq) != NULL) {

            
            if (strstr(linha, "void") != NULL) {
                qtd_void++;
            } else if (strstr(linha, "int ") != NULL) {
                qtd_int++;
            } else if (strstr(linha, "float") != NULL) {
                qtd_float++;
            } else if (strstr(linha, "double") != NULL) {
                qtd_double++;
            } else if (strstr(linha, "char") != NULL) {
                qtd_char++;
            } else if (strstr(linha, "if") != NULL) {
                qtd_if++;
            } else if (strstr(linha, "else") != NULL) {
                qtd_else++;
            } else if (strstr(linha, "case") != NULL) {
                qtd_case++;
            } else if (strstr(linha, "printf") != NULL) {
                qtd_printf++;
            } else if (strstr(linha, "scanf") != NULL) {
                qtd_scanf++;
            } else if (strstr(linha, "return") != NULL) {
                qtd_funcao++;
            } else if (strstr(linha, "for") != NULL) {
                qtd_for++;
                profundidade_for++;
            } else if (strstr(linha, "while") != NULL) {
                qtd_while++;
                profundidade_while++;
            } else if (strstr(linha, "do") != NULL) {
                qtd_do++;
            }

         
            if (strstr(linha, "rand") != NULL || strstr(linha, "probability") != NULL) {
                probabilidade++;
            }
            if (strstr(linha, "parallel") != NULL || strstr(linha, "thread") != NULL) {
                paralelismo++;
            }
            if (strstr(linha, "np_complete") != NULL || strstr(linha, "complex") != NULL) {
                np_completude++;
            }
            if (strstr(linha, "geometry") != NULL || strstr(linha, "geometric") != NULL) {
                geometrico++;
            }
            if (strstr(linha, "search") != NULL || strstr(linha, "find") != NULL) {
                busca++;
            }
            if (strstr(linha, "sort") != NULL || strstr(linha, "ordenar") != NULL) {
                ordenacao++;
            }
        }
        t = clock() - t;
    }

    
    soma = qtd_void + qtd_int + qtd_float + qtd_double + qtd_char + qtd_if + qtd_else + qtd_case + qtd_printf + qtd_scanf + qtd_funcao + qtd_for + qtd_while + qtd_do;


    if (profundidade_for > 2 || profundidade_while > 2) {
        complexidade_pior = 4; 
    } else if (profundidade_for > 1 || profundidade_while > 1) {
        complexidade_pior = 3; 
    } else if (profundidade_for == 1 || profundidade_while == 1) {
        complexidade_pior = 2; 
    } else {
        complexidade_pior = 1; 
    }

    if (profundidade_for > 0 || profundidade_while > 0) {
        complexidade_melhor = 2; 
    } else {
        complexidade_melhor = 1; 
    }


    
    printf("\nQuantidade total de passos: %i\n", soma);
    printf("Tempo de execucao: %.1lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000)));

    
    printf("Analise de Complexidade Assintotica (Pior Caso): ");
    switch (complexidade_pior) {
        case 1:
            printf("O(1)\n");
            break;
        case 2:
            printf("O(n)\n");
            break;
        case 3:
            printf("O(n^2)\n");
            break;
        case 4:
            printf("O(n^3)\n");
            break;
        default:
            printf("Complexidade desconhecida\n");
    }

    printf("Analise de Complexidade Assintotica (Melhor Caso): ");
    switch (complexidade_melhor) {
        case 1:
            printf("O(1)\n");
            break;
        case 2:
            printf("O(n)\n");
            break;
        default:
            printf("Complexidade desconhecida\n");
    }

    
    printf("\nTipo de Algoritmo: ");
    if (paralelismo > 0) {
        printf("Paralelo\n");
    } else if (probabilidade > 0) {
        printf("Probabilístico\n");
    } else if (np_completude > 0) {
        printf("NP-Completo\n");
    } else if (geometrico > 0) {
        printf("Geométrico\n");
    } else if (busca > 0) {
        printf("Busca\n");
    } else if (ordenacao > 0) {
        printf("Ordenação\n");
    } else if (qtd_for > 0 || qtd_while > 0 || qtd_do > 0) {
        printf("Classificação Interna (baseado em laços)\n");
    } else {
        printf("Não identificado com precisão\n");
    }

    fclose(arq);
    return 0;
}



