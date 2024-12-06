section .text
global boot_start

boot_start:
    ; Código del bootloader
    cli
    hlt
