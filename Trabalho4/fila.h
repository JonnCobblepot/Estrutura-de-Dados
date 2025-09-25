//! ================================== CABEÇALHO DA FILA ==================================

//? Importações
#include <stdlib.h>  // malloc, free, exit
#include <stdio.h>   // printf, scanf
#include <stddef.h>  // size_t
#include <stdbool.h> // booleano


//? Estrutura que representa um Documento
typedef struct {
    char nome_arquivo[100]; // nome do arquivo a ser impresso
    int numero_paginas;     // número de páginas do documento
    char cor[10];           // cor (ex: "pb" ou "cor")
    char formato[10];       // formato do arquivo (ex: ".pdf", ".docx")
} Documento;


//? Nó da lista encadeada (cada elemento da fila)
typedef struct No {
    Documento doc;      // dados do documento
    struct No *prox;    // ponteiro para o próximo nó
} No;


//? Estrutura principal da Fila
typedef struct {
    No *inicio; // aponta para o primeiro nó da fila
    No *fim;    // aponta para o último nó da fila
} Fila;


//? Funções
void fila_create(Fila *F);                     // Create(F): inicializa a fila vazia
bool fila_is_empty(const Fila *F);             // Y=IsEmpty(F): se Y = True, a fila está vazia
float fila_enqueue(Fila *F, Documento D);      // Enqueue(F,D): insere documento D no fim da fila
float fila_dequeue(Fila *F, Documento *D);     // Dequeue(F,D): remove início da fila e retorna documento em D
void fila_list(const Fila *F, const char *pfx);// List(F): imprime todos os elementos da fila (sem remover)
void fila_free(Fila *F);                       // libera memória da fila (desaloca todos os nós)


//? Observações
//* - O TAD Fila foi implementado com lista encadeada (dinâmica).
//* - fila_enqueue: insere um novo nó no fim da fila (FIFO).
//* - fila_dequeue: remove o primeiro nó (caso exista).
//* - fila_list: percorre a fila sem modificar os elementos.
//* - fila_free: desaloca todos os nós ainda presentes na fila.
//* - const Fila *F: garante que a fila não será modificada (apenas leitura).

