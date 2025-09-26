#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

// ===============================
// TAD (Tipo Abstrato de Dados) - Música
// ===============================
typedef struct {
    char* nome;      // Nome da música (alocado dinamicamente)
    char* artista;   // Nome do artista (alocado dinamicamente)
    int duracao;     // Duração em segundos
} Musica;

// ===============================
// TAD - Nó da Lista Encadeada
// ===============================
typedef struct No {
    Musica musica;   // Dados da música armazenada no nó
    struct No* prox; // Ponteiro para o próximo nó da lista
} No;

// ===============================
// TAD - Lista Encadeada
// ===============================
typedef struct {
    No* inicio;      // Ponteiro para o primeiro nó da lista
    No* fim;         // Ponteiro para o último nó da lista
    size_t tamanho;  // Quantidade de elementos na lista
} Lista;

// ===============================
// DECLARAÇÕES DAS FUNÇÕES DA LISTA
// ===============================

// Cria uma lista vazia (alocação dinâmica)
Lista* lista_cria();

// Libera toda a memória alocada para a lista
void lista_finaliza(Lista** L);

// Insere uma nova música no final da lista
bool lista_insere_fim(Lista* L, const char* nome, const char* artista, int duracao);

// Remove a primeira ocorrência de uma música pelo nome
bool lista_remove_por_nome(Lista* L, const char* nome);

// Remove e retorna a música do início da lista (para tocar)
Musica* lista_remove_inicio(Lista* L);

// Verifica se a lista está vazia
bool lista_esta_vazia(const Lista* L);

// Retorna o número de elementos na lista
size_t lista_tamanho(const Lista* L);

// Imprime toda a lista no formato especificado
void lista_imprime(const Lista* L);

#endif
