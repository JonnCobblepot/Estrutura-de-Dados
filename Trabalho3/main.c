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
#include <stdio.h>   // malloc, free, exit
#include <stdlib.h>  // printf, scanf
#include <stddef.h>  // size_t
#include <stdbool.h> // booleano
#include "pilha.h"   // cabeçalho