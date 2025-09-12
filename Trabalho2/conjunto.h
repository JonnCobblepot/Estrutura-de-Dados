//!============================== HEADER GUARD ==============================
// Evita que esse arquivo seja definido ou compilado mais de uma vez, caso chamado em mais de um arquivo
// O nome é dado para que o compilador entenda que o conteúdo desse arquivo é chamado CONJUNTO_H
// Quando tiver uma chamada, ele sabe que já compilou, então pula ele
#ifndef CONJUNTO_H
#define CONJUNTO_H

// Tamanho máximo do array (conjunto)
#define MAX 10


//!============================ STRUCT CONJUNTO =============================
typedef struct {         // usa "Conjunto" como tipo direto
    int elementos[MAX];  // array que vai guardar os valores inteiros do conjunto
    int tamanho;         // quantos elementos tem no array //! PILHA insere por último (LiFo Last in, First out)
} Conjunto;


//!======================= PROTÓTIPOS DAS FUNÇÕES TAD ========================
// - Assinatura das funções, compilador vê que elas existem

//? Inicialização, Inserção e Impressão
void inicia_conjunto_vazio(Conjunto *c);        // inicia um conjunto
void insere_elemento(Conjunto *c, int valor);   // insere no conjunto sem duplicar
void imprime_elementos(Conjunto c);             // imprime elementos separados por espaço e depois pula linha

//? Operações entre Conjuntos
Conjunto uniao(Conjunto A, Conjunto B);         // retorna A ∪ B
Conjunto interseccao(Conjunto A, Conjunto B);   // retorna A [intercção] B
Conjunto diferenca(Conjunto A, Conjunto B);     // retorna A - B
int pertence(Conjunto A, int x);                // retorna 1 se x E A, e 0 se não

#endif
