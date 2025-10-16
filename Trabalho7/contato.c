#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"

/* Estrutura concreta do TAD Contato.
 * Os campos são privados e não devem ser acessados fora deste arquivo. */
struct contato {
    char nome[TAM_NOME];
    char telefone[TAM_FONE];
    char email[TAM_EMAIL];
};

/* -------------------------------------------------------------------------
 * Implementações das funções do TAD Contato
 * ------------------------------------------------------------------------- */

Contato* contato_cria(const char* nome, const char* telefone, const char* email) {
    if (!nome || !telefone || !email) return NULL;

    /* Aloca memória dinamicamente */
    Contato* c = (Contato*) malloc(sizeof(Contato));
    if (!c) return NULL;

    /* Copia strings para os campos internos */
    strncpy(c->nome, nome, TAM_NOME - 1);   c->nome[TAM_NOME - 1] = '\0';
    strncpy(c->telefone, telefone, TAM_FONE - 1); c->telefone[TAM_FONE - 1] = '\0';
    strncpy(c->email, email, TAM_EMAIL - 1); c->email[TAM_EMAIL - 1] = '\0';

    return c;
}

void contato_libera(Contato* c) {
    free(c);
}

const char* contato_get_nome(const Contato* c) {
    return c ? c->nome : NULL;
}

void contato_imprime(const Contato* c) {
    if (!c) return;
    printf("[%s, %s, %s]", c->nome, c->telefone, c->email);
}

int contato_compara_nome(const Contato* a, const Contato* b) {
    if (!a || !b) return 0;
    return strcmp(a->nome, b->nome);
}

