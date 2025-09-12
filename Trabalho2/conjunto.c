//!========================================== IMPORTAÇÕES ==========================================
#include <stdio.h>      // printf e scanf
#include "conjunto.h"   // inclui a definição dos conjuntos dentro do cabeçalho (.h) e eles correspondem com oq foi declarado aqui


//!============================== INICIALIZAÇÃO, INSERÇÃO E IMPRESSÃO ==============================

//? Inicia com um conjunto vazio
void inicia_conjunto_vazio(Conjunto *c) {
    
    // o elemento "tamanho" vindo do struct é 0 (nenhum elemento)
    (*c).tamanho = 0;   // ou c->tamanho = 0;  // *c = 0; estaria atribuindo 0 para a struct inteira
}


//? Insere elemento no conjunto (não pode duplicar - ter dois do mesmo elemento)
void insere_elemento(Conjunto *c, int valor) {

    //? O elemento já existe?
    // itera por todos os elementos para ver se o valor dado já existe
    for (int i = 0; i < (*c).tamanho; i++) {
        // verifica se o elemento já existe, se existir
        if ((*c).elementos[i] == valor) { 
            return; // já está no conjunto, retorna nada
        }
    }

    //? O elemento cabe no conjunto?
    // condição se exceder o tamanho máximo do conjunto
    if ((*c).tamanho >= MAX) {
        printf("O tamanho do conjunto excedeu o limite");
        return;
    }

    //? Inserindo o elemento no conjunto
    (*c).elementos[(*c).tamanho] = valor;
    (*c).tamanho++; // incrementa o tamanho e adiciona no final //! PILHA
}


//? Imprime os elementos do conjunto separados por espaço e pula linha
void imprime_elementos(Conjunto c) {

    // Percorre iterando sobre os elementos
    for (int i = 0; i < c.tamanho; i++) {

        printf("%d", c.elementos[i]); // Imprime cada elemento
        if (i < c.tamanho - 1) {
            printf(" ");              // Imprime o espaço (até o penúltimo elemento)
        }
    }
    printf("\n"); // pula a linha após imprimir todo o conjunto
}


//!=================================== OPERAÇÕES ENTRE CONJUNTOS ===================================

//? A U B
// - Copia os elementos de A para C; depois insere elementos de B que não está no C (isso preserva a ordem dos elementos)
Conjunto uniao(Conjunto A, Conjunto B) {
    
    // Iniciando o conjunto vazio C
    Conjunto C;
    inicia_conjunto_vazio(&C);

    // Copiando os elementos de A para C
    for (int i = 0; i < A.tamanho; i++) {
        insere_elemento(&C, A.elementos[i]);
    }

    // Adiciona os elementos de B que não estão em C ("cópia de A"), e evita duplicatas 
    for (int i = 0; i < B.tamanho; i++) {
        insere_elemento(&C, B.elementos[i]);
    }

    return C;
}


//? A [intersecção] B
// - retorna elementos em comum
Conjunto interseccao(Conjunto A, Conjunto B) {

    // Inicia o novo conjunto C
    Conjunto C;
    inicia_conjunto_vazio(&C);

    // Para cada elemento de A vê se existe em B, se sim, insere em C
    for (int i = 0; i < A.tamanho; i++) {
        for (int j = 0; j < B.tamanho; j++) {
            if (A.elementos[i] == B.elementos[j]) {
                insere_elemento(&C, A.elementos[i]);
                break; // não precisa continuar verificando B para esse elemento
            }
        }
    }
    return C;
}


//? A - B
// - retorna elementos de A que não estão em B (tira os elementos de B que estão em A e retorna A)
Conjunto diferenca(Conjunto A, Conjunto B) {
    
    // Inicia o conjunto C
    Conjunto C;
    inicia_conjunto_vazio(&C);


    for (int i = 0; i < A.tamanho; i++) {            // itera em cada elemento de A
        int encontrado = 0;                          // assume inicialmente que NÃO está em B
        for (int j = 0; j < B.tamanho; j++) {       
            if (A.elementos[i] == B.elementos[j]) {
                encontrado = 1;                      // achamos em B
                break;                               // podemos parar de procurar
            }
        }
        if (!encontrado) {  
            insere_elemento(&C, A.elementos[i]);    // se não achou em B, então insere
        }
    }
    return C;
}


//? x E A
// - verifica se um elemento dado pertence ao conjunto A (retorna 1 se sim, e 0 se não)
int pertence(Conjunto A, int x) {
    for (int i = 0; i < A.tamanho; i++) {
        if (A.elementos[i] == x) return 1;
    }
    return 0;
}
