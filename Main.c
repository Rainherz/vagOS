#include "core/FileSystem.h"
#include "core/ProcessManager.h"
#include "core/Scheduler.h"
#include "core/MainSystem.h"
#include "core/ConsoleInterface.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main() {
    char command[100];

    init_filesystem();
    init_process_manager();

    print_hello();

    while (1) {
        input_command(command);
        // fgets(command, sizeof(command), stdin);
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
        } else if (strncmp(command, "cat ", 4) == 0) {
            show_file_content(command + 4);
        } else if (strncmp(command, "edit ", 5) == 0) {
            char filename[20], new_content[100];
            if (sscanf(command + 5, "%s %[^\n]", filename, new_content) == 2) {
                edit_file(filename, new_content);
            } else {
                printf("Uso: edit [archivo] [nuevo contenido]\n");
            }
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
