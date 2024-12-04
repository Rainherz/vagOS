#include "ProcessManager.h"
#include <stdio.h>

void run_scheduler() {
    int quantum = 2;
    printf("Ejecutando procesos con Round Robin (Quantum = %d)...\n", quantum);

    while (process_count > 0) {
        Process *current = &process_queue[0];
        printf("Ejecutando PID=%d, Nombre=%s, Tiempo restante=%d\n", current->pid, current->name, current->remaining_time);

        if (current->remaining_time <= quantum) {
            printf("Proceso PID=%d terminado.\n", current->pid);
            // Elimina el proceso terminado
            for (int i = 1; i < process_count; i++) {
                process_queue[i - 1] = process_queue[i];
            }
            process_count--;
        } else {
            current->remaining_time -= quantum;
            Process temp = *current;
            // Reorganiza la cola
            for (int i = 1; i < process_count; i++) {
                process_queue[i - 1] = process_queue[i];
            }
            process_queue[process_count - 1] = temp;
        }
    }
    printf("Todos los procesos han terminado.\n");
}

