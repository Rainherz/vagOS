section .multiboot
align 4
dd 0x1BADB002              ; Magic number Multiboot
dd 0x00010003              ; Flags: requerimos memoria y vídeo
dd -(0x1BADB002 + 0x00010003) ; Checksum

section .text
global _start
extern kernel_main

_start:
    ; Configurar el stack (opcional, pero recomendado)
    mov esp, 0x90000       ; Establece un stack simple en memoria alta
    call kernel_main       ; Llama a la función principal del kernel
    hlt                    ; Detén la CPU si el kernel retorna
