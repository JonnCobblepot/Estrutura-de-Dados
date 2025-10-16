<<<<<<< HEAD
// //! ================================ LISTA ENCADEADA DINÂMICA ================================

// //? Importações
// #include <stdio.h>   // printf, scanf
// #include <stdlib.h>  // malloc, realloc, free, exit
// #include <string.h>  // manipular strings
// #include <time.h>    // para a ordem aleatória dos elementos
// #include "lista.h"   //* cabeçalho


// //? Cria um novo nó, alocando memória e inicializando os valores
// static No* no_cria(const char* x) {           // static diz que só pode ser usado aqui nesse lista.c
//     No* no = (No*) malloc(sizeof(No));
//     if (no == NULL) return NULL;              // retorna NULL se não tiver memória
//     // aloca memória para a cópia da string 
//     no->info = (char*) malloc(strlen(x) + 1); // +1 para o caractere nulo, ou seja tá contando também
//     if (no->info == NULL) {                  // se falhar, libera o nó que tinha alocado
//         free(no);
//         return NULL;
//     }
//     strcpy(no->info, x); // copia o conteúdo da string x para a nova memória
//     no->prox = NULL;
//     return no;
// }

// //? Criação da Lista vazia
// Lista* lista_cria() {
//     Lista* L = (Lista*) malloc(sizeof(Lista)); // aloca memória da lista (gerencia o início, fim e tamanho dela)
//     if (L == NULL) return NULL;
//     L->inicio = NULL;  // lista começa vazia, então ponteiros apontam para NULL
//     L->fim = NULL;
//     L->tamanho = 0;
//     return L;
// }

// //? Encerra a Lista, liberando sua memória
// void lista_finaliza(Lista** L_end) {  // argumento é um ponteiro para o ponteiro da lista (**) para anular o original depois de liberrar
//     Lista* L = *L_end;                
//     No* p = L->inicio;                // Ponteiro para percorrer a lista
//     while (p != NULL) {               // itera na lista e libera os nós um de cada vez
//         No* temp = p;
//         p = p->prox;      // avança pro próximo antes de liberar o que se está
//         free(temp->info); // libera primeiro a memória da string
//         free(temp);       // em segundo libera a memória do nó
//     }
//     free(L);
//     *L_end = NULL;
// }

// //? Insere no fim da Lista (como se fosse uma prioridade menor)
// bool lista_insere_fim(Lista* L, const char* x) {
//     if (L == NULL) return false;
//     No* novo = no_cria(x);
//     if (novo == NULL) return false;
//     if (lista_esta_vazia(L)) {
//         L->inicio = novo;
//     } else { 
//         L->fim->prox = novo;
//     }
//     L->fim = novo; // o novo nó agora é o fim da lista
//     L->tamanho++;
//     return true;
// }

// //? Insere no início da Lista 
// bool lista_insere_inicio(Lista* L, const char* x) {
//     if (L == NULL) return false;
//     No* novo = no_cria(x);
//     if (novo == NULL) return false;
//     novo->prox = L->inicio;
//     L->inicio = novo;
//     if (L->fim == NULL) { // se a lista estava vazia, o novo nó é o fim
//         L->fim = novo;
//     }
//     L->tamanho++;
//     return true;
// }

// //? Remove elemento da Lista (a 1° ocorrência)
// bool lista_remove(Lista* L, const char* x) {
//     if (L == NULL || lista_esta_vazia(L)) return false;
//     No* p = L->inicio;
//     No* ant = NULL;
//     while (p != NULL && strcmp(p->info, x) != 0) { // strcmp para comparar strings, conferindo com o que se quer remover
//         ant = p;
//         p = p->prox;
//     }
//     if (p == NULL) return false; // não encontrou o elemento que se queria remover
//     if (ant == NULL) {
//         L->inicio = p->prox; // o início da lista agora é o segundo elemento
//     } else {
//         ant->prox = p->prox; // o anterior pula o elemento atual e aponta para o próximo
//     }
//     if (L->fim == p) { // se o elemento removido era o último, o penultimo agora é o fim
//         L->fim = ant;
//     }
//     free(p->info); // libera a memória da string e do nó para o elemento removido
//     free(p);
//     L->tamanho--;
//     return true;
// }

// //? Busca elemento na Lista
// bool lista_busca(const Lista* L, const char* x) {
//     if (L == NULL) return false;
//     No* p = L->inicio;
//     while (p != NULL) {
//         if (strcmp(p->info, x) == 0) { // strcmp para comparar strings
//             return true;
//         }
//         p = p->prox;
//     }
//     return false;
// }

// //? Retorna o tamanho d Lista
// size_t lista_tamanho(const Lista* L) {
//     if (L == NULL) return 0;
//     return L->tamanho;
// }

// //? Verifica se a Lista está vazia
// bool lista_esta_vazia(const Lista* L) {
//     if (L == NULL) return true;
//     return L->tamanho == 0;
// }

// //! Imprime a lista (modificar para o print dos comandos das músicas com saída certinha e colocar na main)
// void lista_imprime(const Lista* L) {
//     if (L == NULL) { printf("Lista (NULA)\n"); return; }
    
//     printf("Lista (tamanho %zu): ", L->tamanho);
//     No* p = L->inicio;
//     while (p != NULL) {
//         printf("%s", p->info); // imprimir a string
//         p = p->prox;
//     }
// }

=======
>>>>>>> ee9b6a27fa388904da9bd4b0e0c9ba99dd2001d2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// ===============================
// FUNÇÃO INTERNA (static) - Cria um novo nó
// ===============================
static No* no_cria(const char* nome, const char* artista, int duracao) {
    // Aloca memória para o nó
    No* no = (No*)malloc(sizeof(No));
    if (no == NULL) return NULL; // Verifica se a alocação foi bem-sucedida

    // Aloca memória para o nome da música (+1 para o caractere nulo '\0')
    no->musica.nome = (char*)malloc(strlen(nome) + 1);
    // Aloca memória para o nome do artista
    no->musica.artista = (char*)malloc(strlen(artista) + 1);
    
    // Verifica se as alocações das strings foram bem-sucedidas
    if (no->musica.nome == NULL || no->musica.artista == NULL) {
        // Se falhou, libera a memória já alocada
        free(no->musica.nome);
        free(no->musica.artista);
        free(no);
        return NULL;
    }

    // Copia as strings para a memória alocada
    strcpy(no->musica.nome, nome);
    strcpy(no->musica.artista, artista);
    no->musica.duracao = duracao; // Armazena a duração
    no->prox = NULL; // Inicializa o ponteiro para próximo como NULL
    return no;
}

// ===============================
// FUNÇÃO PÚBLICA - Cria lista vazia
// ===============================
Lista* lista_cria() {
    // Aloca memória para a estrutura da lista
    Lista* L = (Lista*)malloc(sizeof(Lista));
    if (L == NULL) return NULL; // Verifica alocação
    
    // Inicializa os campos da lista
    L->inicio = NULL;  // Lista vazia: início aponta para NULL
    L->fim = NULL;     // Lista vazia: fim aponta para NULL
    L->tamanho = 0;    // Lista vazia: tamanho zero
    return L;
}

// ===============================
// FUNÇÃO PÚBLICA - Libera toda a memória da lista
// ===============================
void lista_finaliza(Lista** L_end) {
    // Verifica se o ponteiro para a lista é válido
    if (L_end == NULL || *L_end == NULL) return;
    
    Lista* L = *L_end;
    No* p = L->inicio; // Ponteiro para percorrer a lista
    
    // Percorre todos os nós liberando a memória
    while (p != NULL) {
        No* temp = p;   // Guarda referência ao nó atual
        p = p->prox;    // Avança para o próximo nó
        
        // Libera a memória das strings primeiro
        free(temp->musica.nome);
        free(temp->musica.artista);
        // Libera a memória do nó
        free(temp);
    }
    
    // Libera a memória da estrutura da lista
    free(L);
    *L_end = NULL; // Anula o ponteiro original para evitar uso acidental
}

// ===============================
// FUNÇÃO PÚBLICA - Insere no final da lista
// ===============================
bool lista_insere_fim(Lista* L, const char* nome, const char* artista, int duracao) {
    if (L == NULL) return false; // Verifica se a lista existe
    
    // Cria um novo nó com os dados da música
    No* novo = no_cria(nome, artista, duracao);
    if (novo == NULL) return false; // Verifica se a criação foi bem-sucedida
    
    // Se a lista está vazia, o novo nó será o primeiro e último
    if (lista_esta_vazia(L)) {
        L->inicio = novo;
    } else {
        // Se não está vazia, o último nó atual aponta para o novo nó
        L->fim->prox = novo;
    }
    
    L->fim = novo; // Atualiza o ponteiro para o final da lista
    L->tamanho++;  // Incrementa o contador de elementos
    return true;
}

// ===============================
// FUNÇÃO PÚBLICA - Remove música por nome
// ===============================
bool lista_remove_por_nome(Lista* L, const char* nome) {
    // Verifica se a lista existe ou está vazia
    if (L == NULL || lista_esta_vazia(L)) return false;
    
    No* p = L->inicio; // Ponteiro para percorrer a lista
    No* ant = NULL;     // Ponteiro para o nó anterior
    
    // Percorre a lista procurando a música pelo nome
    while (p != NULL && strcmp(p->musica.nome, nome) != 0) {
        ant = p;       // Guarda o nó anterior
        p = p->prox;   // Avança para o próximo
    }
    
    if (p == NULL) return false; // Música não encontrada
    
    // Reorganiza os ponteiros para remover o nó
    if (ant == NULL) {
        // Remove do início: o segundo nó passa a ser o primeiro
        L->inicio = p->prox;
    } else {
        // Remove do meio/fim: o nó anterior pula o nó removido
        ant->prox = p->prox;
    }
    
    // Se o nó removido era o último, atualiza o ponteiro do fim
    if (L->fim == p) {
        L->fim = ant;
    }
    
    // Libera a memória do nó removido
    free(p->musica.nome);
    free(p->musica.artista);
    free(p);
    L->tamanho--; // Decrementa o contador de elementos
    return true;
}

// ===============================
// FUNÇÃO PÚBLICA - Remove do início (para tocar música)
// ===============================
Musica* lista_remove_inicio(Lista* L) {
    // Verifica se a lista existe ou está vazia
    if (L == NULL || lista_esta_vazia(L)) return NULL;
    
    No* removido = L->inicio; // Guarda referência ao nó que será removido
    L->inicio = removido->prox; // O segundo nó passa a ser o primeiro
    
    // Se a lista tinha apenas um elemento, atualiza o ponteiro do fim
    if (L->fim == removido) {
        L->fim = NULL;
    }
    L->tamanho--; // Decrementa o contador

    // Cria uma cópia da música para retornar (evita perder dados ao liberar o nó)
    Musica* m = (Musica*)malloc(sizeof(Musica));
    m->nome = strdup(removido->musica.nome);     // Duplica a string do nome
    m->artista = strdup(removido->musica.artista); // Duplica a string do artista
    m->duracao = removido->musica.duracao;       // Copia a duração

    // Libera o nó removido (mas não as strings originais - agora temos cópias)
    free(removido->musica.nome);
    free(removido->musica.artista);
    free(removido);
    
    return m; // Retorna a música removida
}

// ===============================
// FUNÇÃO PÚBLICA - Verifica se lista está vazia
// ===============================
bool lista_esta_vazia(const Lista* L) {
    return L == NULL || L->tamanho == 0;
}

// ===============================
// FUNÇÃO PÚBLICA - Retorna tamanho da lista
// ===============================
size_t lista_tamanho(const Lista* L) {
    return L == NULL ? 0 : L->tamanho;
}

// ===============================
// FUNÇÃO PÚBLICA - Imprime a lista no formato especificado
// ===============================
void lista_imprime(const Lista* L) {
    // Verifica se a lista está vazia
    if (lista_esta_vazia(L)) {
        printf("Playlist: []\n");
        return;
    }
    
    printf("Playlist: ");
    No* p = L->inicio; // Ponteiro para percorrer a lista
    
    // Percorre todos os nós imprimindo cada música
    while (p != NULL) {
        // Formato: [nome, artista, duraçãos]
        printf("[%s, %s, %ds]", p->musica.nome, p->musica.artista, p->musica.duracao);
        
        // Se não é o último, imprime a seta " -> "
        if (p->prox != NULL) printf(" -> ");
        p = p->prox; // Avança para o próximo nó
    }
    printf("\n"); // Nova linha no final
}
