//! ================================== CABEÇALHO DA PILHA ==================================

//? Importações
#include <stdlib.h>  // malloc, realloc, free, exit
#include <stdio.h>   // printf, scanf
#include <stddef.h>  // size_t
#include <stdbool.h> // booleano


//? Caracterização da Pilha
typedef float elem; // tipo dos elementos da pilha
typedef struct Pilha {
    elem *itens;   // vetor dinâmico (usa malloc, realloc)
    size_t topo;   // posição do topo (n° de elementos atuais)
    size_t total;  // tamanho total da pilha
} Pilha;


//? Funções
float pilha_create(Pilha *P, size_t total);    // Create(P): cria pilha P vazia
float pilha_empilha(Pilha *P, elem X);         // Push(P,X): empilha o valor da variável X na pilha P
float pilha_desempilha(Pilha *P, elem *X);     // Pop(P,X): desempilha P e retorna X (valor do topo desempilhado)
float pilha_ver_topo(const Pilha *P, elem *X); // X=top(P): vê quem está no topo
bool pilha_is_empty(const Pilha *P);           // Y=IsEmpty(P): se Y = True, a pilha está vazia
void pilha_empty(Pilha *P);                    // Empty(P): esvazia uma pilha
void pilha_free_memory(Pilha *p);              // libera a memória


//? Observações
//* - * significa ponteiro
//* - Pilha *P: ponteiro pois vai modificar a estrutura passada (alocar memória, inicializar elementos)
//* - size_t total: valor simples, passado por valor (não será mudado)
//* - elem X: por valor, ex: empilhar o n° 77, não precisa modificá-lo
//* - elem *X: ponteiro, ex: desempilhar o topo, precisamos devolver esse valor, retorno a nós
//* - const Pilha *P: ponteiro constante, pois só haverá leitura dos dados, não irá alterar
//* Se quer só usar o valor na pilha, não coloca o *
//* Se quer devolver, ler, acessar ou alterar, coloca o *
//* Se quer modificar, ler ou devolver uma struct, passa o ponteiro para a struct