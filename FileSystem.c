#include "FileSystem.h"
#include <stdio.h>
#include <string.h>

#define MAX_FILES 10

typedef struct {
    char name[20];
    char content[100];
} File;

static File filesystem[MAX_FILES];
static int file_count = 0;

void init_filesystem() {
    file_count = 0;
}

void list_files() {
    if (file_count == 0) {
        printf("No hay archivos en el sistema.\n");
        return;
    }
    printf("Archivos en el sistema:\n");
    for (int i = 0; i < file_count; i++) {
        printf("- %s\n", filesystem[i].name);
    }
}

void create_file(const char *filename, const char *content) {
    if (file_count >= MAX_FILES) {
        printf("No se pueden agregar más archivos.\n");
        return;
    }
    strcpy(filesystem[file_count].name, filename);
    strcpy(filesystem[file_count].content, content);
    file_count++;
    printf("Archivo '%s' creado.\n", filename);
}

void delete_file(const char *filename) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(filesystem[i].name, filename) == 0) {
            for (int j = i; j < file_count - 1; j++) {
                filesystem[j] = filesystem[j + 1];
            }
            file_count--;
            printf("Archivo '%s' eliminado.\n", filename);
            return;
        }
    }
    printf("Archivo no encontrado.\n");
}

void show_file_content(const char *filename) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(filesystem[i].name, filename) == 0) {
            printf("Contenido de %s:\n%s\n", filename, filesystem[i].content);
            return;
        }
    }
    printf("Archivo no encontrado.\n");
}

void edit_file(const char *filename, const char *new_content) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(filesystem[i].name, filename) == 0) {
            strcpy(filesystem[i].content, new_content);
            printf("Archivo '%s' editado con éxito.\n", filename);
            return;
        }
    }
    printf("Archivo no encontrado.\n");
}
