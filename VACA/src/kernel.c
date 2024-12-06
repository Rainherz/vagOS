#include "kernel.h"

// Función para comparar cadenas
int str_cmp(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}

// Función para obtener la longitud de una cadena
int str_len(const char *str) {
    int len = 0;
    while (*str++) {
        len++;
    }
    return len;
}

void print_char(char c) {
    static unsigned short *video = (unsigned short *)0xB8000;
    static unsigned int pos = 0;

    if (c == '\n') {
        pos += 80 - (pos % 80);  // Salto de línea (80 caracteres por fila)
    } else {
        video[pos] = (0x0F << 8) | c;
        pos++;
    }

    if (pos >= 2000) {
        pos = 0;  // Reinicia la pantalla si se llena
    }
}

void print_string(const char *str) {
    while (*str) {
        print_char(*str);
        str++;
    }
}

void clear_screen() {
    for (int i = 0; i < 2000; i++) {
        print_char(' ');  // Llena la pantalla de espacios
    }
}

// Simula entrada de usuario
void simulate_input(char *buffer, const char *input) {
    int i = 0;
    while (input[i]) {
        buffer[i] = input[i];
        i++;
    }
    buffer[i] = '\0';
}

// Función principal del kernel
void kernel_main() {
    char buffer[256];

    print_string("Bienvenido a VagOS CLI\n");
    print_string("Escribe 'help' para ver los comandos disponibles.\n");

    while (1) {
        print_char('>');
        simulate_input(buffer, "help");  // Cambiar "help" por otros comandos para pruebas

        if (str_cmp(buffer, "help")) {
            print_string("Comandos disponibles: help, reboot, clear\n");
        } else if (str_cmp(buffer, "clear")) {
            clear_screen();
        } else if (str_cmp(buffer, "reboot")) {
            print_string("Reiniciando...\n");
            // Implementa el reinicio aquí (requiere código adicional en el bootloader)
        } else {
            print_string("Comando no reconocido.\n");
        }
    }
}
