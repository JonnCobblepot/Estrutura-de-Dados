#include <stdlib.h>  // malloc, realloc, free
#include <stdio.h>   // printf, scanf
#include <stddef.h>  // size_t
#include <stdbool.h> // booleano

typedef float elem; // tipo dos elementos da pilha

// Caracterização da Pilha
typedef struct Pilha {
    elem *itens;   // vetor dinâmico (usa malloc, realloc)
    size_t topo;   // posição do topo (n° de elementos atuais)
    size_t total;  // tamanho total da pilha
} Pilha;

int pilha_create(Pilha *P, size_t total);    // Create(P): cria pilha P vazia
int pilha_empilha(Pilha *P, elem X);         // Push(P,X): empilha o valor da variável X na pilha P
int pilha_desempilha(Pilha *P, elem *X);     // Pop(P,X): desempilha P e retorna X (valor do topo desempilhado)
int pilha_ver_topo(const Pilha *P, elem *X); // X=top(P): vê quem está no topo
bool pilha_is_empty(const Pilha *P);         // Y=IsEmpty(P): se Y = True, a pilha está vazia
void pilha_empty(Pilha *P);                  // Empty(P): esvazia uma pilha
void pilha_free_memory(Pilha *p);            // libera a memória