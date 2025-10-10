#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"
#include "task.h"


#define LINE_MAX 256

// chomp remove \n e \r finais para windows e run codes
static void chomp(char* s) {
    size_t L = strlen(s);
    while (L > 0 && (s[L-1] == '\n' || s[L-1] == '\r')) {
        s[L-1] = '\0';
        L--;
    }
}


int main(void) {
    // Cria o deque usando o TAD. main() NUNCA manipula internals do deque diretamente
    Deque* dq = deque_create();
    char line[LINE_MAX];

    // Flag auxiliar para evitar print duplicado de "A lista de tarefas esta vazia." que tava tendo no final
    int last_printed_empty = 0;

    // Loop principal: lê comandos linha a linha até o comando "sair"
    while (1) {

        // manipula as linhas
        if (!fgets(line, sizeof(line), stdin)) break;
        chomp(line);
        if (strlen(line) == 0) continue;

        char* cmd = strtok(line, " ");
        if (!cmd) continue;

        // Processa cada comando possível conforme especificação 
        if (strcmp(cmd, "sair") == 0) {
            break; // Encerra o programa 

        } else if (strcmp(cmd, "adicionar") == 0) {
            // adicionar <nome> <descricao> <duracao>
            char* name = strtok(NULL, " ");
            char* desc = strtok(NULL, " ");
            char* dur_s = strtok(NULL, " ");
            if (!name || !desc || !dur_s) continue; // argumentos insuficientes 
            int dur = atoi(dur_s);
            Task* t = task_create(name, desc, dur);
            deque_push_tail(dq, t);

            // alterou a fila então reseta a flag 
            last_printed_empty = 0;

        } else if (strcmp(cmd, "adicionar_prioritario") == 0) {
            // adicionar_prioritario <nome> <descricao> <duracao>
            char* name = strtok(NULL, " ");
            char* desc = strtok(NULL, " ");
            char* dur_s = strtok(NULL, " ");
            if (!name || !desc || !dur_s) continue;
            int dur = atoi(dur_s);
            Task* t = task_create(name, desc, dur);
            deque_push_head(dq, t);

            // alterou a fila então reseta a flag 
            last_printed_empty = 0;

        } else if (strcmp(cmd, "remover") == 0) {
            // remover <nome>
            char* name = strtok(NULL, " ");
            if (!name) continue;
            Task* removed = deque_remove_by_name(dq, name);
            if (removed) {
                printf("Tarefa %s removida.\n", name);
                task_destroy(removed);  // libera memória da Task removida 
                last_printed_empty = 0; // alterou a fila então reseta a flag 
            } else {
                printf("Tarefa %s nao encontrada.\n", name);
            }

        } else if (strcmp(cmd, "executar_proxima") == 0) {
            // verifica se está vazio o deque antes de dar o pop 
            if (deque_is_empty(dq)) {
                // se já imprimiu a mensagem anterior, suprime a repetição 
                if (!last_printed_empty) {
                    printf("A lista de tarefas esta vazia.\n");
                    last_printed_empty = 1;
                }
            } else {
                Task* t = deque_pop_head(dq); // executar_proxima
                if (!t) {
                    // caso se estiver como vazio
                    if (!last_printed_empty) {
                        printf("A lista de tarefas esta vazia.\n");
                        last_printed_empty = 1;
                    }
                } else {
                    printf("Tarefa Concluida: %s, %s, %dmin\n",
                           task_get_name(t),      // getter  para nome 
                           task_get_desc(t),      // getter para descrição 
                           task_get_duration(t)); // getter para duração
                    task_destroy(t);              // libera a Task após uso 

                    // alterou a fila então reseta a flag 
                    last_printed_empty = 0;
                }
            }
        } else if (strcmp(cmd, "executar_ultima") == 0) {
            if (deque_is_empty(dq)) {
                if (!last_printed_empty) {
                    printf("A lista de tarefas esta vazia.\n");
                    last_printed_empty = 1;
                }
            } else {
                Task* t = deque_pop_tail(dq); // executar_ultima
                if (!t) {
                    if (!last_printed_empty) {
                        printf("A lista de tarefas esta vazia.\n");
                        last_printed_empty = 1;
                    }
                } else {
                    printf("Tarefa Concluida: %s, %s, %dmin\n",
                           task_get_name(t),
                           task_get_desc(t),
                           task_get_duration(t));
                    task_destroy(t);

                    last_printed_empty = 0;
                }
            }

        } else if (strcmp(cmd, "listar") == 0) {
            // listar
            // deque_print(dq);
            if (deque_is_empty(dq)) {
                deque_print(dq);
                last_printed_empty = 1; // marcado que já mostrou a mensagem vazia (lista de tarefas vazia)
            } else {
                deque_print(dq);
                last_printed_empty = 0;
            }


        } else {
            // comando fora da lógica escrita não faz nada
        }
    }

    deque_destroy(dq); // antes de sair destrói o deque
    return 0;
}
