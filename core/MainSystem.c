#include "MainSystem.h"

#include <time.h>
#include <stdio.h>

void show_help() {
    printf("Comandos disponibles:\n");
    printf("- ls: Lista archivos\n");
    printf("- create [archivo] [contenido]: Crea un archivo\n");
    printf("- delete [archivo]: Elimina un archivo\n");
    printf("- cat [archivo]: Muestra el contenido de un archivo\n");
    printf("- edit [archivo] [nuevo contenido]: Edita el contenido de un archivo\n");
    printf("- run [nombre] [tiempo]: Agrega un proceso\n");
    printf("- pause [pid]: Pausa/Reanuda un proceso por su PID\n");
    printf("- remove [pid]: Elimina un proceso por su PID\n");
    printf("- scheduler: Ejecuta el planificador\n");
    printf("- listproc: Lista procesos activos\n");
    printf("- time: Muestra la hora actual\n");
    printf("- exit: Salir\n");
}

void show_time() {
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    printf("Hora actual: %02d:%02d:%02d\n", local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
}