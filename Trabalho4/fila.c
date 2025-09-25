//! ======================================== FILA ========================================

//? Importações
#include "fila.h"    //* cabeçalho

//? Criação da fila (inicializa vazia)
void fila_create(Fila *F) {
    F->inicio = NULL;
    F->fim = NULL;
}

//? Fila está vazia?
bool fila_is_empty(const Fila *F) {
    return (F->inicio == NULL);
}

//? Enfileirar (adiciona no fim da fila)
float fila_enqueue(Fila *F, Documento D) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        return -1; // falha na alocação
    }

    novo->doc = D;
    novo->prox = NULL;

    if (fila_is_empty(F)) {
        F->inicio = novo;
    } else {
        F->fim->prox = novo;
    }
    F->fim = novo;

    return 0; // sucesso
}

//? Desenfileirar (remove do início)
float fila_dequeue(Fila *F, Documento *D) {
    if (fila_is_empty(F)) {
        return -1; // erro: fila vazia
    }

    No *temp = F->inicio;
    *D = temp->doc;          // copia o documento removido
    F->inicio = temp->prox;  // avança para o próximo

    if (F->inicio == NULL) { // se esvaziou
        F->fim = NULL;
    }

    free(temp);
    return 0; // sucesso
}

//? Listar os documentos da fila (sem remover)
void fila_list(const Fila *F, const char *prefixo) {
    printf("%s[", prefixo);
    No *atual = F->inicio;

    while (atual != NULL) {
        Documento d = atual->doc;
        printf("%s (%d paginas, %s, %s)",
               d.nome_arquivo, d.numero_paginas, d.cor, d.formato);
        if (atual->prox != NULL) printf(", ");
        atual = atual->prox;
    }
    printf("]\n");
}

//? Libera memória de toda a fila
void fila_free(Fila *F) {
    Documento d;
    while (!fila_is_empty(F)) {
        fila_dequeue(F, &d);
    }
}

