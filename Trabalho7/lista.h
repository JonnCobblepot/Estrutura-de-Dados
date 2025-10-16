#ifndef LISTA_H
#define LISTA_H

#include "contato.h"

/* -------------------------------------------------------------------------
 * TAD: Lista Ordenada de Contatos
 * 
 * Este TAD armazena contatos de forma ordenada alfabeticamente pelo nome.
 * A estrutura é implementada como lista encadeada simples, com alocação
 * dinâmica. O usuário só interage com as funções públicas.
 * ------------------------------------------------------------------------- */

typedef struct lista Lista;

/* Cria e inicializa uma nova lista vazia. Retorna ponteiro ou NULL em erro. */
Lista* lista_cria(void);

/* Libera todos os nós e contatos armazenados, além da própria lista. */
void lista_libera(Lista* l);

/* Insere um novo contato na lista em ordem alfabética.
 * Se o nome já existir, não insere e retorna 1.
 * Retorna 0 em sucesso ou -1 em erro de alocação. */
int lista_inserir(Lista* l, const char* nome, const char* telefone, const char* email);

/* Remove o contato com o nome informado.
 * Retorna 1 se removido, 0 se não encontrado. */
int lista_remover(Lista* l, const char* nome);

/* Busca um contato pelo nome e retorna ponteiro (não deve ser liberado). */
Contato* lista_buscar(const Lista* l, const char* nome);

/* Imprime todos os contatos em ordem.
 * Se vazia, imprime "Agenda vazia." */
void lista_listar(const Lista* l);

#endif

