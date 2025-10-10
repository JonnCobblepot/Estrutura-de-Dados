#ifndef TASK_H
#define TASK_H

//? =========================== TAD TASK ===========================

typedef struct Task Task;

//? Cria a task com nome, descrição e duração; retorna ponteiro para a struct Task (t)
Task* task_create(const char* name, const char* desc, int duration); 

//? Destrói a task passada, liberando a memória e não retorna nada (void)
void task_destroy(Task* t);

//? Getters pro encapsulamento, retornando as informações da struct Task para leitura
const char* task_get_name(const Task* t);
const char* task_get_desc(const Task* t);
int task_get_duration(const Task* t);

//? Imprime a task no formato: [name, desc, XXmin]
void task_print(const Task* t);

#endif 