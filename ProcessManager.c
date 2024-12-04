#include "ProcessManager.h"
#include <stdio.h>
#include <string.h>

// Definición de las variables globales
Process process_queue[MAX_PROCESSES];
int process_count = 0;

// Inicialización del gestor de procesos
void init_process_manager() {
    process_count = 0;
}

// Agrega un proceso a la cola
void add_process(const char *name, int runtime) {
    if (process_count >= MAX_PROCESSES) {
        printf("No se pueden agregar más procesos.\n");
        return;
    }
    Process new_process = {process_count + 1, "", runtime, runtime};
    strcpy(new_process.name, name);
    process_queue[process_count++] = new_process;
    printf("Proceso agregado: PID=%d, Nombre=%s, Runtime=%d\n", new_process.pid, new_process.name, runtime);
}

// Lista los procesos activos
void list_active_processes() {
    if (process_count == 0) {
        printf("No hay procesos activos.\n");
        return;
    }
    printf("Procesos activos:\n");
    for (int i = 0; i < process_count; i++) {
        printf("- PID=%d, Nombre=%s, Tiempo restante=%d\n", process_queue[i].pid, process_queue[i].name, process_queue[i].remaining_time);
    }
}

