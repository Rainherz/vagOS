#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#define MAX_PROCESSES 5

// Definición de la estructura Process
typedef struct {
    int pid;
    char name[20];
    int runtime;
    int remaining_time;
} Process;

// Variables globales expuestas
extern Process process_queue[MAX_PROCESSES];
extern int process_count;

// Funciones públicas
void init_process_manager();
void add_process(const char *name, int runtime);
void list_active_processes();

#endif

