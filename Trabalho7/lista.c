#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/* Estrutura de nó da lista encadeada.
 * Cada nó armazena um contato e o ponteiro para o próximo nó. */
typedef struct no {
    Contato* dado;
    struct no* prox;
} No;

/* Estrutura principal da lista.
 * Mantém ponteiro para o início e o número de elementos. */
struct lista {
    No* inicio;
    int tamanho;
};

/* -------------------------------------------------------------------------
 * Criação e Liberação
 * ------------------------------------------------------------------------- */

/* Cria lista vazia. */
Lista* lista_cria(void) {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    if (!l) return NULL;
    l->inicio = NULL;
    l->tamanho = 0;
    return l;
}

/* Libera todos os nós e contatos da lista. */
void lista_libera(Lista* l) {
    if (!l) return;
    No* p = l->inicio;
    while (p) {
        No* nxt = p->prox;
        contato_libera(p->dado);
        free(p);
        p = nxt;
    }
    free(l);
}

/* -------------------------------------------------------------------------
 * Inserção Ordenada
 * ------------------------------------------------------------------------- */

int lista_inserir(Lista* l, const char* nome, const char* telefone, const char* email) {
    if (!l || !nome) return -1;

    /* Cria o contato e o nó */
    Contato* c = contato_cria(nome, telefone, email);
    if (!c) return -1;

    No* novo = (No*) malloc(sizeof(No));
    if (!novo) { contato_libera(c); return -1; }

    novo->dado = c;
    novo->prox = NULL;

    /* Caso lista vazia */
    if (l->inicio == NULL) {
        l->inicio = novo;
        l->tamanho++;
        return 0;
    }

    /* Busca posição de inserção */
    No* prev = NULL;
    No* cur = l->inicio;
    while (cur) {
        int cmp = strcmp(contato_get_nome(cur->dado), nome);
        if (cmp == 0) {
            /* Nome duplicado — não insere */
            contato_libera(c);
            free(novo);
            return 1;
        } else if (cmp > 0) {
            /* Inserir antes do atual */
            break;
        }
        prev = cur;
        cur = cur->prox;
    }

    /* Inserção no início */
    if (prev == NULL) {
        novo->prox = l->inicio;
        l->inicio = novo;
    } else {
        /* Inserção no meio ou fim */
        prev->prox = novo;
        novo->prox = cur;
    }

    l->tamanho++;
    return 0;
}

/* -------------------------------------------------------------------------
 * Remoção e Busca
 * ------------------------------------------------------------------------- */

/* Remove o contato pelo nome (se existir). */
int lista_remover(Lista* l, const char* nome) {
    if (!l || !nome) return 0;

    No* prev = NULL;
    No* cur = l->inicio;

    while (cur) {
        if (strcmp(contato_get_nome(cur->dado), nome) == 0) {
            /* Remove o nó atual */
            if (prev == NULL)
                l->inicio = cur->prox;
            else
                prev->prox = cur->prox;

            contato_libera(cur->dado);
            free(cur);
            l->tamanho--;
            return 1;
        }
        prev = cur;
        cur = cur->prox;
    }

    return 0;  /* não encontrado */
}

/* Busca contato pelo nome. */
Contato* lista_buscar(const Lista* l, const char* nome) {
    if (!l || !nome) return NULL;
    No* cur = l->inicio;
    while (cur) {
        int cmp = strcmp(contato_get_nome(cur->dado), nome);
        if (cmp == 0) return cur->dado;
        if (cmp > 0) return NULL; /* lista ordenada => já passou */
        cur = cur->prox;
    }
    return NULL;
}

/* -------------------------------------------------------------------------
 * Impressão
 * ------------------------------------------------------------------------- */

/* Imprime todos os contatos em ordem. */
void lista_listar(const Lista* l) {
    if (!l) return;
    if (l->inicio == NULL) {
        printf("A agenda de contatos esta vazia.\n");
        return;
    }

    printf("Contatos:\n");
    No* cur = l->inicio;
    while (cur) {
        printf("- ");
        contato_imprime(cur->dado);
        printf("\n");
        cur = cur->prox;
    }
}

