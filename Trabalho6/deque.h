#ifndef DEQUE_H
#define DEQUE_H

//? =========================== TAD LISTA DUPLAMENTE ENCADEADA (DEQUE) ===========================

#include "task.h"

typedef struct Deque Deque;


Deque* deque_create(void); // cria o deque

void deque_destroy(Deque* dq); // desaloca todas as tarefas internas 

void deque_push_tail(Deque* dq, Task* t);   // insere no fim (tail)

void deque_push_head(Deque* dq, Task* t);  // insere no início (head)

Task* deque_pop_head(Deque* dq); // remove no início (head)

Task* deque_pop_tail(Deque* dq); // remove no fim (tail)

Task* deque_remove_by_name(Deque* dq, const char* name); // remove uma task pelo nome

int deque_is_empty(const Deque* dq); // verifica se o deque está vazio

void deque_print(const Deque* dq); // imprime o deque no formato correto (ou mensagem de vazio)

#endif