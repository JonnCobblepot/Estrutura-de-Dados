#ifndef CONTATO_H
#define CONTATO_H

/* -------------------------------------------------------------------------
 * TAD: Contato
 * 
 * Responsável por representar um contato de agenda, contendo nome, telefone
 * e e-mail. As operações definidas aqui são de criação, liberação, impressão
 * e comparação. O usuário não acessa diretamente os campos da estrutura.
 * ------------------------------------------------------------------------- */

#define TAM_NOME 100
#define TAM_FONE 25
#define TAM_EMAIL 100

/* Tipo opaco: estrutura definida apenas em contato.c */
typedef struct contato Contato;

/* Cria e inicializa um novo contato, copiando nome, telefone e e-mail.
 * Retorna ponteiro para o contato ou NULL em caso de erro. */
Contato* contato_cria(const char* nome, const char* telefone, const char* email);

/* Libera a memória associada a um contato. */
void contato_libera(Contato* c);

/* Retorna o nome do contato (apenas leitura). */
const char* contato_get_nome(const Contato* c);

/* Imprime o contato no formato [Nome, telefone, email]. */
void contato_imprime(const Contato* c);

/* Compara dois contatos alfabeticamente pelo nome.
 * Retorna valor <0, 0 ou >0 (como strcmp). */
int contato_compara_nome(const Contato* a, const Contato* b);

#endif

