//! ======================================== PILHA ========================================

//? Importações
#include <stdio.h>   // malloc, realloc, free, exit
#include <stdlib.h>  // printf, scanf
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
    (*P).total = total; // capacidade máxima
    return 0;           // tudo certo
}


//! Observações
//? pilha_create
//* - Para acessar campos normal da struct é struct.parâmetro (P.topo)
//* - Para acessar campos via ponteiro da struct é struct->parâmetro ((*P).topo ou P->topo)
//* - O vetor itens não tem tamanho fixo
//* - malloc pede ao s.o. para reserver um pedaço de memória (total * sizeof(elem)
//* - se der certo retorna o endereço da reserva, caso não retorna NULL