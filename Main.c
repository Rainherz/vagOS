#include "FileSystem.h"
#include "ProcessManager.h"
#include "Scheduler.h"
#include <stdio.h>
#include <string.h>

void show_help() {
    printf("Comandos disponibles:\n");
    printf("- ls: Lista archivos\n");
    printf("- create [archivo] [contenido]: Crea un archivo\n");
    printf("- delete [archivo]: Elimina un archivo\n");
    printf("- cat [archivo]: Muestra el contenido de un archivo\n");
    printf("- run [nombre] [tiempo]: Agrega un proceso\n");
    printf("- scheduler: Ejecuta el planificador\n");
    printf("- listproc: Lista procesos activos\n");
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
        } else if (strcmp(command, "scheduler") == 0) {
            run_scheduler();
        } else if (strcmp(command, "listproc") == 0) {
            list_active_processes();
        } else if (strcmp(command, "exit") == 0) {
            break;
        }
    }
    return 0;
}

