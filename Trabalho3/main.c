//! ======================================== ENUNCIADO ========================================
//! Calculadora Polonesa Reversa (RPN)
//? - Lê sequencia de comandos (um por linha)
//? - Os comandos podem ser float ou operadores matemáticos
//? - Após cada comando, imprime o resultado do topo da pilha
//? - Execução só para após comando "off" imprimindo a pilha
//! Lista de Funções
//?   Objetivo     Comando                            Descrição
//*   empilhar        X     lê float e empilha(sem saída)
//*     soma          +     desempilha 2, soma, empilha o resultado e o imprime
//*   subtração       -     desempilha 2 (B, depois A), faz A-B, empilha o resultado e o imprime
//* multiplicação     *     desempilha 2, multiplica, empilha o resultado e o imprime
//*    divisão        /     desempilha 2 (B, depois A), faz A/B, empilha o resultado e o imprime
//*   potência        ^     desempilha 2 (B, depois A), faz A^B, empilha o resultado e o imprime
//*   encerrar       off    imprime toda a pilha (do topo para a basa) e encerra o programa
//! Organização
//? - Código em C e usando um TAD para Pilha
//? - main.c ; pilha.c ; pilha.h ; Makefile


//! ================================ Programa ao Cliente - TAD ================================
#include <stdio.h>   // malloc, realloc, free, exit
#include <stdlib.h>  // printf, scanf
#include <stddef.h>  // size_t
#include <stdbool.h> // booleano
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "pilha.h"   // cabeçalho

int tamanho_inicial_pilha = 16; // entretanto se passar já é feita a lógica para aumentar a memória automático
int tamanho_buffer = 100;       // o buffer armazena os caracteres do input para verificar se é um comando e o que fazer

int main() {
    Pilha pilha;
    char buffer[tamanho_buffer]; // tudo o que é input é string, então ele vai comparar strings

    //? Criando a Pilha 
    pilha_create(&pilha, tamanho_inicial_pilha);
    
    //? Loop principal para ler comandos
    while (1) {
        
        fgets(buffer, tamanho_buffer, stdin); // lê cada linha passada
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove quebra de linha \n do buffer para comparar

        //? Comando "off" = saída
        if (strcmp(buffer, "off") == 0) {
            break; // Sai do loop
        }
        
        //? Comandos das operações
        else if (strcmp(buffer, "+") == 0) {
            if (pilha.topo < 2) {
                continue;
            } else {
                elem a, b;
                pilha_desempilha(&pilha, &b);
                pilha_desempilha(&pilha, &a);
                elem resultado = a + b;
                pilha_empilha(&pilha, resultado);
                printf("%.2f\n", resultado);
            }
        } 
        else if (strcmp(buffer, "-") == 0) {
            if (pilha.topo < 2) {
                continue;
            } else {
                elem a, b;
                pilha_desempilha(&pilha, &b);
                pilha_desempilha(&pilha, &a);
                elem resultado = a - b;
                pilha_empilha(&pilha, resultado);
                printf("%.2f\n", resultado);
            }
        }
        else if (strcmp(buffer, "*") == 0) {
            if (pilha.topo < 2) {
                continue;
            } else {
                elem a, b;
                pilha_desempilha(&pilha, &b);
                pilha_desempilha(&pilha, &a);
                elem resultado = a * b;
                pilha_empilha(&pilha, resultado);
                printf("%.2f\n", resultado);
            }
        }
        else if (strcmp(buffer, "/") == 0) {
            if (pilha.topo < 2) {
                continue;
            } else {
                elem a, b;
                pilha_desempilha(&pilha, &b);
                pilha_desempilha(&pilha, &a);
                if (b == 0) { // condição de erro, simplesmente não faz a operação por dividir por zero
                    pilha_empilha(&pilha, a);
                    pilha_empilha(&pilha, b);
                } else {
                    elem resultado = a / b;
                    pilha_empilha(&pilha, resultado);
                    printf("%.2f\n", resultado);
                }
            }
        }
        else if (strcmp(buffer, "^") == 0) {
            if (pilha.topo < 2) {
                continue;
            } else {
                elem a, b;
                pilha_desempilha(&pilha, &b);
                pilha_desempilha(&pilha, &a);
                elem resultado = pow(a, b);
                pilha_empilha(&pilha, resultado);
                printf("%.2f\n", resultado);
            }
        }
        
        //? Empilhando o número
        else {
            elem numero = atof(buffer);
            pilha_empilha(&pilha, numero);
        }
    }

    //? Imprime a pilha no final do topo para a base
    printf("Pilha:");
    elem valor;

    //? Desempilha para imprimir
    while (!pilha_is_empty(&pilha)) {
        pilha_desempilha(&pilha, &valor);
        printf(" %.2f", valor);
    }
    printf("\n");

    //? Libera a memória alocada para a pilha
    pilha_free_memory(&pilha);

    return 0; // Sucesso
}
