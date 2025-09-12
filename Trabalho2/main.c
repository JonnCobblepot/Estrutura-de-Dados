//!=========================================== PROBLEMA ============================================
// 1° linha: coloque 5 números separados por espaço
// 2° linha: coloque 5 números separados por espaço
// Comandos:
// - 1: união dos conjuntos
// - 2: intersecção dos conjuntos
// - 3: subtração dos conjuntos
// - 4 x: verifica se x pertence ao conjunto
// - -1: encerra o programa

//!========================================== IMPORTAÇÕES ==========================================
#include <stdio.h>      // printf e scanf
#include "conjunto.h"   // inclui a definição dos conjuntos dentro do cabeçalho (.h) e eles correspondem com oq foi declarado em conjunto.c

// Ao incluir o conjunto.h sabe como é o Tipo Conjunto e as funções e operações entre conjuntos, que foram implementados no conjunto.c


//!============================================= MAIN ==============================================
int main() {
    Conjunto A, B, C;
    inicia_conjunto_vazio(&A);   // Inicia o conjunto A: A.tamanho = 0
    inicia_conjunto_vazio(&B);   // Inicia o conjunto B: B.tamanho = 0
                                 // Conjunto C é iniciado em conjunto.c, pois ele é o resultado das saídas

    //* No problema, a entrada tem duas linhas e tem 5 inteiros em cada
    // Lê os 5 inteiros da 1° linha (Conjunto A)
    for (int i = 0; i < 5; i++) {
        int x;
        if (scanf("%d", &x) != 1){
            return 0; 
        } 
        insere_elemento(&A, x); // Insere cada elemento no conjunto A
    }

    // Lê os 5 inteiros da 2° linha (Conjunto B)
    for (int i = 0; i < 5; i++) {
        int x;
        if (scanf("%d", &x) != 1) {
            return 0;
        }
        insere_elemento(&B, x); // Insere cada elemento no conjunto B
    }

    // Interrompendo o programa quando scanf = -1
    while (1) { // condição verdade pro loop
        int comando;
        if (scanf("%d", &comando) != 1) {
            break;
        }

        // se for -1 somente encerra
        if (comando == -1) {
            break;
        }

        switch (comando) {
            // união
            case 1: 
                C = uniao(A, B);
                imprime_elementos(C);
                break;
            // interseção
            case 2: 
                C = interseccao(A, B);
                imprime_elementos(C);
                break;
            // diferença A - B (elementos da 1° linha - os da 2° linha)
            case 3: 
                C = diferenca(A, B);
                imprime_elementos(C);
                break;
            // pertence, lê o comando 4 e depois separado por espaço o elemento que quer ver se pertence
            case 4: { 
                int x;
                if (scanf("%d", &x) != 1) return 0;
                if (pertence(A, x)) printf("Sim\n");
                else printf("Nao\n");
                break;
            }
            default:
                // comando não conhecido só ignora
                break;
        }
    }
    return 0;
}
