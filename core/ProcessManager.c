#include "ProcessManager.h"
#include <stdio.h>
#include <string.h>

Process process_queue[MAX_PROCESSES];
int process_count = 0;

void init_process_manager() {
    process_count = 0;
}

void add_process(const char *name, int runtime) {
    if (process_count >= MAX_PROCESSES) {
        printf("No se pueden agregar más procesos.\n");
        return;
    }
    Process new_process = {process_count + 1, "", runtime, runtime, 0};
    strcpy(new_process.name, name);
    process_queue[process_count++] = new_process;
    printf("Proceso agregado: PID=%d, Nombre=%s, Runtime=%d\n", new_process.pid, new_process.name, runtime);
}

void list_active_processes() {
    if (process_count == 0) {
        printf("No hay procesos activos.\n");
        return;
    }
    printf("Procesos activos:\n");
    for (int i = 0; i < process_count; i++) {
        printf("- PID=%d, Nombre=%s, Tiempo restante=%d, Pausado=%s\n",
               process_queue[i].pid,
               process_queue[i].name,
               process_queue[i].remaining_time,
               process_queue[i].paused ? "Sí" : "No");
    }
}

void pause_process(int pid) {
    for (int i = 0; i < process_count; i++) {
        if (process_queue[i].pid == pid) {
            process_queue[i].paused = !process_queue[i].paused;
            printf("Proceso PID=%d %s.\n", pid, process_queue[i].paused ? "pausado" : "reanudo");
            return;
        }
    }
    printf("Proceso con PID=%d no encontrado.\n", pid);
}

void remove_process(int pid) {
    for (int i = 0; i < process_count; i++) {
        if (process_queue[i].pid == pid) {
            for (int j = i; j < process_count - 1; j++) {
                process_queue[j] = process_queue[j + 1];
            }
            process_count--;
            printf("Proceso PID=%d eliminado.\n", pid);
            return;
        }
    }
    printf("Proceso con PID=%d no encontrado.\n", pid);
}
