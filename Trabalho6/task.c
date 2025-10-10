#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

//? Struct Task
// Aqui cumpre a definição de uma task que terá nome e descrição, ambos string sem espaços
// e também duração em minutos estimada da task (inteiro)
struct Task {
    char* name;   // nome da task
    char* desc;   // descrição da task
    int duration; // duração da task
};
// escolhi fazer essa struct sem colocar o nome após o ";" para diferenciar melhor já que estamos lidando com dois TADs


//? Aloca e inicia uma task
// Alocação separada para name e desc; se alguma alocação falhar, libera a memória e retorna NULL
Task* task_create(const char* name, const char* desc, int duration) {
    
    Task* t = (Task*) malloc(sizeof(Task)); // aloca a struct Task
    if (!t) return NULL; 

    // aloca espaço na memória para as strings com +1 para o indicador de fim (esse caracter é terminador nulo)
    t->name = (char*) malloc(strlen(name) + 1);
    t->desc = (char*) malloc(strlen(desc) + 1);

    // se alguma das alocações de string falhar, limpa e retorna NULL 
    if (!t->name || !t->desc) {
        free(t->name);
        free(t->desc);
        free(t);
        return NULL;
    }

    // copia as strings para os locais onde foram alocadas
    strcpy(t->name, name);  
    strcpy(t->desc, desc);

    // armazena a duração que é um inteiro para os minutos
    t->duration = duration;

    return t;
}


//? Destrói uma task, ou seja, libera aquela struct task em si da memória
void task_destroy(Task* t) {
    if (!t) return;
    free(t->name);  // libera a string alocada para name
    free(t->desc);  // libera a string alocada para desc 
    free(t);        // libera a struct 
}


//! Encapsulamento (para não expor a struct), e eis aqui os getters
// retornam dados internos sem permitir que modifique eles; e se não tiver nada retorna NULL
const char* task_get_name(const Task* t) {
    return t ? t->name : NULL;
}
const char* task_get_desc(const Task* t) {
    return t ? t->desc : NULL;
}
int task_get_duration(const Task* t) {
    return t ? t->duration : -1;
}


//? Imprime a task no formato: [name, desc, XXmin]
void task_print(const Task* t) {
    if (!t) return;
    printf("[%s, %s, %dmin]", t->name, t->desc, t->duration);
}