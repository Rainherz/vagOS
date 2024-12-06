ENTRY(_start)

SECTIONS
{
    . = 0x00100000; /* Dirección de carga */
    .text : {
        *(.multiboot)
        *(.text)
    }
    .data : {
        *(.data)
    }
    .bss : {
        *(.bss)
    }
}
