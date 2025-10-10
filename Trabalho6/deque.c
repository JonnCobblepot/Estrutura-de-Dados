//! ==================== Fila Duplamente Encadeada (Deque) ====================
//? Usa nós duplamente encadeados, sendo que cada nó armazena uma Task* (ponteiro)
//? Ser duplamente encadeado significa poder adicionar, remover ou imprimir antes e após um nó
//? Com isso será manipulado o head (cabeça da fila: início) e o tail (cauda da fila: fim)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"
#include "task.h" 


//? Struct Nó da lista duplamente encadeada
typedef struct Node {
    Task* task;         // ponteiro para a Task armazenada
    struct Node* prev;  // nó anterior; NULL se esse nó anterior for o head (cabeça da fila)
    struct Node* next;  // próximo nó; NULL se esse próximo nó for o tail (calda da fila)
} Node;


//? Struct Deque para ponteiros de head e tail da fila
struct Deque {
    Node* head; /* primeiro nó (frente da fila) */
    Node* tail; /* último nó (fim da fila) */
};


//? Cria a lista duplamente encadeada
// aloca a struct Deque e inicia head e tail como NULL (nenhum elemento para ambos no início)
// se der erro na alocação retorna NULL
Deque* deque_create(void) {
    Deque* dq = (Deque*) malloc(sizeof(Deque));
    if (!dq) return NULL;   
    dq->head = dq->tail = NULL; // deque começando vazio
    return dq;
}


//? Cria o nó de um ponteiro Task* já existente
// iniciando prev e next como NULL
// retorna NULL se falhar na alocação
static Node* node_create(Task* t) {
    Node* n = (Node*) malloc(sizeof(Node));
    if (!n) return NULL;
    n->task = t;
    n->prev = n->next = NULL;
    return n;
}


//? Insere no final do deque
// se o deque estiver vazio, head e tail recebem o novo nó
// se o deque não estiver vazio, o nó fica após o tail e atualiza o tail
void deque_push_tail(Deque* dq, Task* t) {
    if (!dq || !t) return;     // não faz nada se receber argumentos inválidos
    Node* n = node_create(t);
    if (!n) return;            // falha de alocação

    if (!dq->tail) {
        dq->head = dq->tail = n;  // deque vazio
    } else {
        dq->tail->next = n;       // encadeia depois do tail (cauda) atual se o deque não estiver vazio
        n->prev = dq->tail;
        dq->tail = n;
    }
}


//? Insere no início do deque
// se o deque estiver vazio, head e tail recebem o novo nó
// se o deque não estiver vazio, o nó fica antes do head e atualiza o head
void deque_push_head(Deque* dq, Task* t) {
    if (!dq || !t) return;       // garantia de argumentos inválidos
    Node* n = node_create(t);
    if (!n) return;

    if (!dq->head) {
        dq->head = dq->tail = n;  // deque vazio
    } else {
        dq->head->prev = n;       // deque não vazio
        n->next = dq->head;
        dq->head = n;
    }
}


//? Remove e retorna do início do deque (head)
// se o deque estiver vazio, retorna NULL
// se o deque não estiver vazio, libera o nó, mas não a task
// quem vai destrui a task é o task_destroy no TAD de task
Task* deque_pop_head(Deque* dq) {
    if (!dq || !dq->head) return NULL; 
    Node* n = dq->head;
    Task* t = n->task; // pega a task

    // atualiza head para o próximo nó
    dq->head = n->next;
    if (dq->head) {
        // existe novo head, assim prev deve ser NULL
        dq->head->prev = NULL;
    } else {
        // lista ficou vazia, atualiza então tail também
        dq->tail = NULL;
    }

    free(n); // libera o nó removido 
    return t;
}


//? Remove e retorna no final do deque (tail)
// se o deque estiver vazio, retorna NULL
// se o deque não estiver vazio, libera o nó, mas como antes a task não
Task* deque_pop_tail(Deque* dq) {
    if (!dq || !dq->tail) return NULL;
    Node* n = dq->tail;
    Task* t = n->task;

    dq->tail = n->prev;
    if (dq->tail) {
        dq->tail->next = NULL;
    } else {
        // a lista ficou vazia
        dq->head = NULL;
    }

    free(n);
    return t;
}


//? Remove uma task pelo nome
// Percorre a lista do head até tail procurando a task que tem o nome igual ao recebido (usa task_get_name)
// Se o nome for encontrado desfaz o encadeamento (unlink) do nó e atualiza da seguinte forma:
// - atualiza prev->next e next->prev
// - se o nó for head ou tail, atualiza os ponteiros head/tail do deque
// E com isso remove o nó da lista e retorna o ponteiro Task* encontrada, sem destruir ela
// Se o nome não for encontrado, retorna NULL
Task* deque_remove_by_name(Deque* dq, const char* name) {
    if (!dq || !dq->head || !name) return NULL;

    Node* cur = dq->head;
    while (cur) {
        // getter para acessar o nome da Task
        const char* tname = task_get_name(cur->task);

        if (tname && strcmp(tname, name) == 0) {
            // Aqui já foi encontrado o nome, faz unlink do nó cur
            if (cur->prev) {
                // nó não é head, assim conecta prev -> next do cur
                cur->prev->next = cur->next;
            } else {
                // cur era head, assim novo head é cur->next que pode ser NULL tbm
                dq->head = cur->next;
            }

            if (cur->next) {
                // nó não é tail, assim conecta next -> prev do cur 
                cur->next->prev = cur->prev;
            } else {
                // cur era tail, assim novo tail é cur->prev e que pode ser NULL
                dq->tail = cur->prev;
            }

            Task* t = cur->task;
            free(cur); // libera o nó
            return t;
        }

        cur = cur->next;
    }

    // se não for encontrado
    return NULL;
}


//? Verifica se o deque está vazio
int deque_is_empty(const Deque* dq) {
    return (dq == NULL) || (dq->head == NULL);
}


//? Imprime a lista de tarefas [name, desc, XXmin] -> [...] -> ....
// Se estiver vazia, imprime:
// - Lista de Tarefas:
// - A lista de tarefas esta vazia.
// task_print do TAD Task mantém a formatação
void deque_print(const Deque* dq) {
    printf("Lista de Tarefas:");
    if (!dq || !dq->head) {
        printf("\nA lista de tarefas esta vazia.\n");
        return;
    }

    printf(" ");
    Node* cur = dq->head;
    while (cur) {
        // imprime cada tarefa (task_print já coloca os colchetes e o formato correto)
        task_print(cur->task);
        if (cur->next) printf(" -> ");
        cur = cur->next;
    }
    printf("\n");
}


//? Libera a struct deque
void deque_destroy(Deque* dq) {
    if (!dq) return;

    Node* cur = dq->head;
    while (cur) {
        Node* nxt = cur->next;
        if (cur->task) task_destroy(cur->task); // libera recurso da Task
        free(cur); // libera o nó 
        cur = nxt;
    }

    free(dq); // libera a struct deque 
}