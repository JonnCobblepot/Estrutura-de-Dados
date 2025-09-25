//! ======================================== ENUNCIADO ========================================
//! Fila de Impressão (ICMC)
//? - Lê sequência de comandos (um por linha)
//? - Os comandos podem ser: add, print, list, off
//? - O programa continua até receber o comando "off"
//? - Após cada comando, mostra o resultado pedido
//! Lista de Funções
//?   Objetivo         Comando                         Descrição
//*   adicionar        add <nome> <pag> <cor> <form>   insere documento no final da fila
//*   imprimir         print                           remove início e mostra documento
//*   listar           list                            lista documentos sem removê-los
//*   encerrar         off                             imprime fila final e encerra
//! Organização
//? - Código em C e usando um TAD para Fila
//? - main.c ; fila.c ; fila.h ; Makefile


//! ================================ Programa ao Cliente - TAD ================================
#include <stdio.h>   // scanf, printf
#include <string.h>  // strcmp
#include "fila.h"    //* cabeçalho da fila

int main() {
    Fila fila;
    fila_create(&fila); //? Cria fila inicialmente vazia

    char comando[20];
    while (1) {
        if (scanf("%s", comando) == EOF) break;

        //! Comandos
        //? Adicionar documento na fila
        if (strcmp(comando, "add") == 0) {
            Documento d;
            scanf("%s %d %s %s", d.nome_arquivo,
                                 &d.numero_paginas,
                                 d.cor,
                                 d.formato);
            fila_enqueue(&fila, d);
        }

        //? Imprimir próximo documento
        else if (strcmp(comando, "print") == 0) {
            Documento d;
            if (fila_dequeue(&fila, &d) == 0) {
                printf("Imprimindo: %s (%d paginas, %s, %s)\n",
                       d.nome_arquivo, d.numero_paginas, d.cor, d.formato);
            } else {
                printf("Fila de impressao vazia.\n");
            }
        }

        //? Listar documentos pendentes
        else if (strcmp(comando, "list") == 0) {
            fila_list(&fila, "Fila: ");
        }

        //? Encerrar programa
        else if (strcmp(comando, "off") == 0) {
            fila_list(&fila, "Fila final: ");
            fila_free(&fila);
            break;
        }
    }

    return 0; // sucesso
}

