#include "ConsoleInterface.h"

#include <stdio.h>

enum COLOR {
  RED = 31,
  BLUE = 34,
  GREEN = 32,
  YELLOW = 33,
  WHITE = 37,
  BLACK = 30,
  MAGENTA = 35,
  CYAN = 36,
  B_BLACK = 40,
  B_RED = 41,
  B_GREEN = 42,
  B_YELLOW = 43,
  B_BLUE = 44,
  B_MAGENTA = 45,
  B_CYAN = 46,
  B_WHITE = 47,
};

struct console_t {
  enum COLOR color;
};

struct config_t {
  struct console_t system_console;
  struct console_t user_console;
};

struct config_t global_config = {
  {GREEN},
  {MAGENTA}
};

void set_console_color(enum COLOR c_color) {
  printf("\033[%im", c_color);
}
void reset_console_color() {
  printf("\033[0m");
}

void input_command(char *command) {
    set_console_color(global_config.system_console.color);
    printf("> ");
    set_console_color(global_config.user_console.color);
    fgets(command, sizeof(command), stdin);
    reset_console_color();
    //command[strcspn(command, "\n")] = '\0';
}

void print_hello() {
    set_console_color(GREEN);
    printf("Bienvenido a VagOS CLI\n");
    set_console_color(BLUE);
    printf("Escribe 'help' para ver los comandos disponibles.\n");
    reset_console_color();
}

void print_text(char* text){
    set_console_color(global_config.system_console.color);
    printf("%s",text);
    reset_console_color();
    printf("\n");
}