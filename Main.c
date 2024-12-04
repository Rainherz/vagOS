#include "FileSystem.h"
#include "ProcessManager.h"
#include "Scheduler.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void show_time() {
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    printf("Hora actual: %02d:%02d:%02d\n", local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
}

void show_help() {
    printf("Comandos disponibles:\n");
    printf("- ls: Lista archivos\n");
    printf("- create [archivo] [contenido]: Crea un archivo\n");
    printf("- delete [archivo]: Elimina un archivo\n");
    printf("- cat [archivo]: Muestra el contenido de un archivo\n");
    printf("- run [nombre] [tiempo]: Agrega un proceso\n");
    printf("- pause [pid]: Pausa/Reanuda un proceso por su PID\n");
    printf("- remove [pid]: Elimina un proceso por su PID\n");
    printf("- scheduler: Ejecuta el planificador\n");
    printf("- listproc: Lista procesos activos\n");
    printf("- time: Muestra la hora actual\n");
    printf("- exit: Salir\n");
}

int main() {
    char command[100];

    init_filesystem();
    init_process_manager();

    printf("Bienvenido a VagOS CLI\n");

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "help") == 0) {
            show_help();
        } else if (strcmp(command, "ls") == 0) {
            list_files();
        } else if (strncmp(command, "create ", 7) == 0) {
            char filename[20], content[100];
            if (sscanf(command + 7, "%s %[^\n]", filename, content) == 2) {
                create_file(filename, content);
            }
        } else if (strncmp(command, "delete ", 7) == 0) {
            delete_file(command + 7);
        } else if (strncmp(command, "run ", 4) == 0) {
            char name[20];
            int runtime;
            if (sscanf(command + 4, "%s %d", name, &runtime) == 2) {
                add_process(name, runtime);
            }
        } else if (strncmp(command, "pause ", 6) == 0) {
            int pid;
            if (sscanf(command + 6, "%d", &pid) == 1) {
                pause_process(pid);
            } else {
                printf("Uso: pause [pid]\n");
            }
        } else if (strncmp(command, "remove ", 7) == 0) {
            int pid;
            if (sscanf(command + 7, "%d", &pid) == 1) {
                remove_process(pid);
            } else {
                printf("Uso: remove [pid]\n");
            }
        } else if (strcmp(command, "scheduler") == 0) {
            run_scheduler();
        } else if (strcmp(command, "listproc") == 0) {
            list_active_processes();
        } else if (strcmp(command, "time") == 0) {
            show_time();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Comando no reconocido: %s\n", command);
        }
    }
    return 0;
}
