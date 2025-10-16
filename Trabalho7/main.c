#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

/* -------------------------------------------------------------------------
 * Função principal (usuário do TAD)
 * 
 * - Lê comandos do usuário até receber "sair".
 * - Usa apenas as funções definidas nos TADs (não acessa structs diretamente).
 * ------------------------------------------------------------------------- */

int main(void) {
    Lista* agenda = lista_cria();
    if (!agenda) {
        fprintf(stderr, "Erro ao criar agenda.\n");
        return 1;
    }

    char comando[32];

    /* Loop principal de leitura de comandos */
    while (scanf("%31s", comando) == 1) {
        if (strcmp(comando, "inserir") == 0) {
            char nome[110], telefone[60], email[120];
            if (scanf("%109s %59s %119s", nome, telefone, email) != 3) break;

            int r = lista_inserir(agenda, nome, telefone, email);
            if (r == 1)
                printf("Contato %s ja existe.\n", nome);
            else if (r == -1)
                fprintf(stderr, "Erro de alocacao ao inserir.\n");
            /* Em sucesso (r==0), nada é impresso */

        } else if (strcmp(comando, "remover") == 0) {
            char nome[110];
            if (scanf("%109s", nome) != 1) break;

            int r = lista_remover(agenda, nome);
            if (r)
                printf("Contato %s removido.\n", nome);
            else
                printf("Contato %s nao encontrado.\n", nome);

        } else if (strcmp(comando, "buscar") == 0) {
            char nome[110];
            if (scanf("%109s", nome) != 1) break;

            Contato* c = lista_buscar(agenda, nome);
            if (c) {
                printf("Contato Encontrado: ");
                contato_imprime(c);
                printf("\n");
            } else {
                printf("Contato %s nao encontrado.\n", nome);
            }

        } else if (strcmp(comando, "listar") == 0) {
            lista_listar(agenda);

        } else if (strcmp(comando, "sair") == 0) {
            break;
        }
    }

    /* Libera toda a memória antes de encerrar */
    lista_libera(agenda);
    return 0;
}

