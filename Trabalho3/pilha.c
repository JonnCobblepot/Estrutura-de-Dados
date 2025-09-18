//! ======================================== PILHA ========================================

//? Importações
#include <stdio.h>   // malloc, realloc, free, exit
#include <stddef.h>  // size_t
#include <stdbool.h> // booleano
#include "pilha.h"   //* cabeçalho


//? Criação da Pilha
float pilha_create(Pilha *P, size_t total){
    (*P).itens = (elem*) malloc(total * sizeof(elem));
    if ((*P).itens == NULL) {
        return -1;      // falha ao alocar a memória
    }
    (*P).topo = 0;      // começa vazia
    (*P).total = total; // capacidade máxima da pilha
    return 0;           
}

//? Pilha está vazia?
// True se sim, False se não
bool pilha_is_empty(const Pilha *P) {
    return ((*P).topo == 0);
}

//? Pilha está cheia?
bool pilha_is_full(const Pilha *P) {
    return ((*P).topo >= (*P).total);
}

//?
float pilha_aumenta_memory(Pilha *P, size_t aumento) {
    if (aumento == 0) return -1;
    elem *tmp = (elem*) realloc((*P).itens, aumento * sizeof(elem));
    if (tmp == NULL) {
        return -1; // se não conseguir realocar, ficca como estava
    }
    (*P).itens = tmp;
    (*P).total = aumento;
    return 0;
}

//? Empilhar 
// (Pilha é L.I.F.O, coloca elementos no topo)
float pilha_empilha(Pilha *P, elem X){
    if (pilha_is_full(P)) {
        size_t nova = ((*P).total == 0) ? 1 : (*P).total * 2; /* dobra */
        if (pilha_aumenta_memory(P, nova) != 0) {
            return -1; /* erro: realloc falhou */
        }
    }
    (*P).itens[(*P).topo++] = X;
    
    return 0;
}


//? Desempilhar
float pilha_desempilha(Pilha *P, elem *X) {
    if (pilha_is_empty(P)) {
        return -1; // erro: pilha vazia
    }
    (*P).topo--;               // volta uma posição
    *X = (*P).itens[(*P).topo];  // devolve o valor do topo
    return 0; // sucesso
}

//? Libera a memória após encerrar o programa da pilha
void pilha_free_memory(Pilha *P) {
    if ((*P).itens != NULL) {
        free((*P).itens);
        (*P).itens = NULL;
    }
    (*P).topo = 0;
    (*P).total = 0;
}

//? Retorna o topo
float pilha_ver_topo(const Pilha *P, elem *X) {
    if (pilha_is_empty(P)) {
        return 0; // falhou
    }

    *X = (*P).itens[(*P).topo - 1];  // pega o último elemento
    return 1; // sucesso
}

//? Verifição se a pilha está vazia
void pilha_empty(Pilha *P) {
    P->topo = 0; 
}


//! Observações
//? pilha_create
//* - Para acessar campos normal da struct é struct.parâmetro (P.topo)
//* - Para acessar campos via ponteiro da struct é struct->parâmetro ((*P).topo ou P->topo)
//* - O vetor itens não tem tamanho fixo
//* - malloc pede ao s.o. para reserver um pedaço de memória (total * sizeof(elem)
//* - se der certo retorna o endereço da reserva, caso não retorna NULL
//* - sizeof retorna o tamanho em bytes, ex: sizeof(float) = 4
//* - malloc(100) reserva 100 bytes (daria 25 floats); malloc(100 * sizeof(float)) reserva 400 bytes = 100 floats