//! ================================ LISTA ENCADEADA DINÂMICA ================================

//? Importações
#include <stdio.h>   // printf, scanf
#include <stdlib.h>  // malloc, realloc, free, exit
#include <string.h>  // manipular strings
#include <time.h>    // para a ordem aleatória dos elementos
#include "lista.h"   //* cabeçalho


//? Cria um novo nó, alocando memória e inicializando os valores
static No* no_cria(const char* x) {           // static diz que só pode ser usado aqui nesse lista.c
    No* no = (No*) malloc(sizeof(No));
    if (no == NULL) return NULL;              // retorna NULL se não tiver memória
    // aloca memória para a cópia da string 
    no->info = (char*) malloc(strlen(x) + 1); // +1 para o caractere nulo, ou seja tá contando também
    if (no->info == NULL) {                  // se falhar, libera o nó que tinha alocado
        free(no);
        return NULL;
    }
    strcpy(no->info, x); // copia o conteúdo da string x para a nova memória
    no->prox = NULL;
    return no;
}

//? Criação da Lista vazia
Lista* lista_cria() {
    Lista* L = (Lista*) malloc(sizeof(Lista)); // aloca memória da lista (gerencia o início, fim e tamanho dela)
    if (L == NULL) return NULL;
    L->inicio = NULL;  // lista começa vazia, então ponteiros apontam para NULL
    L->fim = NULL;
    L->tamanho = 0;
    return L;
}

//? Encerra a Lista, liberando sua memória
void lista_finaliza(Lista** L_end) {  // argumento é um ponteiro para o ponteiro da lista (**) para anular o original depois de liberrar
    Lista* L = *L_end;                
    No* p = L->inicio;                // Ponteiro para percorrer a lista
    while (p != NULL) {               // itera na lista e libera os nós um de cada vez
        No* temp = p;
        p = p->prox;      // avança pro próximo antes de liberar o que se está
        free(temp->info); // libera primeiro a memória da string
        free(temp);       // em segundo libera a memória do nó
    }
    free(L);
    *L_end = NULL;
}

//? Insere no fim da Lista (como se fosse uma prioridade menor)
bool lista_insere_fim(Lista* L, const char* x) {
    if (L == NULL) return false;
    No* novo = no_cria(x);
    if (novo == NULL) return false;
    if (lista_esta_vazia(L)) {
        L->inicio = novo;
    } else { 
        L->fim->prox = novo;
    }
    L->fim = novo; // o novo nó agora é o fim da lista
    L->tamanho++;
    return true;
}

//? Insere no início da Lista 
bool lista_insere_inicio(Lista* L, const char* x) {
    if (L == NULL) return false;
    No* novo = no_cria(x);
    if (novo == NULL) return false;
    novo->prox = L->inicio;
    L->inicio = novo;
    if (L->fim == NULL) { // se a lista estava vazia, o novo nó é o fim
        L->fim = novo;
    }
    L->tamanho++;
    return true;
}

//? Remove elemento da Lista (a 1° ocorrência)
bool lista_remove(Lista* L, const char* x) {
    if (L == NULL || lista_esta_vazia(L)) return false;
    No* p = L->inicio;
    No* ant = NULL;
    while (p != NULL && strcmp(p->info, x) != 0) { // strcmp para comparar strings, conferindo com o que se quer remover
        ant = p;
        p = p->prox;
    }
    if (p == NULL) return false; // não encontrou o elemento que se queria remover
    if (ant == NULL) {
        L->inicio = p->prox; // o início da lista agora é o segundo elemento
    } else {
        ant->prox = p->prox; // o anterior pula o elemento atual e aponta para o próximo
    }
    if (L->fim == p) { // se o elemento removido era o último, o penultimo agora é o fim
        L->fim = ant;
    }
    free(p->info); // libera a memória da string e do nó para o elemento removido
    free(p);
    L->tamanho--;
    return true;
}

//? Busca elemento na Lista
bool lista_busca(const Lista* L, const char* x) {
    if (L == NULL) return false;
    No* p = L->inicio;
    while (p != NULL) {
        if (strcmp(p->info, x) == 0) { // strcmp para comparar strings
            return true;
        }
        p = p->prox;
    }
    return false;
}

//? Retorna o tamanho d Lista
size_t lista_tamanho(const Lista* L) {
    if (L == NULL) return 0;
    return L->tamanho;
}

//? Verifica se a Lista está vazia
bool lista_esta_vazia(const Lista* L) {
    if (L == NULL) return true;
    return L->tamanho == 0;
}

//! Imprime a lista (modificar para o print dos comandos das músicas com saída certinha e colocar na main)
void lista_imprime(const Lista* L) {
    if (L == NULL) { printf("Lista (NULA)\n"); return; }
    
    printf("Lista (tamanho %zu): ", L->tamanho);
    No* p = L->inicio;
    while (p != NULL) {
        printf("%s", p->info); // imprimir a string
        p = p->prox;
    }
}
