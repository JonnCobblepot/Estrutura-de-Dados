#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    // Cria a playlist vazia
    Lista* playlist = lista_cria();
    char comando[10], nome[100], artista[100];
    int duracao;

    // Loop principal do programa
    while (1) {
        // Lê o comando do usuário
        scanf("%s", comando);

        // Verifica qual comando foi digitado
        if (strcmp(comando, "off") == 0) {
            // Comando OFF: encerra o programa
            break;
        } else if (strcmp(comando, "add") == 0) {
            // Comando ADD: adiciona nova música
            // Lê nome, artista e duração
            scanf("%s %s %d", nome, artista, &duracao);
            // Insere no final da playlist
            lista_insere_fim(playlist, nome, artista, duracao);
            // Não imprime nada, conforme especificação
        } else if (strcmp(comando, "remove") == 0) {
            // Comando REMOVE: remove música pelo nome
            scanf("%s", nome);
            if (lista_remove_por_nome(playlist, nome)) {
                // Se encontrou e removeu: mensagem de confirmação
                printf("Musica %s removida.\n", nome);
            } else {
                // Se não encontrou: mensagem de erro
                printf("Musica %s nao encontrada.\n", nome);
            }
        } else if (strcmp(comando, "play") == 0) {
            // Comando PLAY: toca a próxima música (remove do início)
            if (lista_esta_vazia(playlist)) {
                // Playlist vazia: mensagem informativa
                printf("Playlist vazia.\n");
            } else {
                // Remove a primeira música e obtém seus dados
                Musica* m = lista_remove_inicio(playlist);
                // Imprime a música que está tocando
                printf("Tocando: %s, %s, %ds\n", m->nome, m->artista, m->duracao);
                // Libera a memória da música retornada
                free(m->nome);
                free(m->artista);
                free(m);
            }
        } else if (strcmp(comando, "list") == 0) {
            // Comando LIST: mostra toda a playlist sem remover
            lista_imprime(playlist);
        }
        // Comandos desconhecidos são ignorados silenciosamente
    }

    // Libera toda a memória alocada para a playlist antes de encerrar
    lista_finaliza(&playlist);
    return 0;
}
