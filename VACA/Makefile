# Variables
CC = gcc
AS = nasm
LD = ld
OBJCOPY = objcopy

CFLAGS = -m32 -ffreestanding -Wall -Wextra -I./include
LDFLAGS = -melf_i386 -T linker.ld -z noexecstack

KERNEL_ELF = kernel.elf
KERNEL_BIN = kernel.bin
ISO_NAME = vagOS.iso

# Objetivo principal
all: iso

# Generar ISO
iso: $(KERNEL_ELF)
	mkdir -p iso/boot/grub
	cp $(KERNEL_ELF) iso/boot/
	echo "set timeout=0" > iso/boot/grub/grub.cfg
	echo "menuentry 'vagOS' { multiboot /boot/kernel.elf }" >> iso/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO_NAME) iso

# Crear kernel ELF
$(KERNEL_ELF): multiboot_header.o kernel.o
	$(LD) $(LDFLAGS) -o $(KERNEL_ELF) multiboot_header.o kernel.o

# Ensamblar encabezado Multiboot
multiboot_header.o: src/multiboot_header.asm
	$(AS) -f elf32 src/multiboot_header.asm -o multiboot_header.o

# Compilar kernel en C
kernel.o: src/kernel.c
	$(CC) $(CFLAGS) -c src/kernel.c -o kernel.o

# Limpiar archivos generados
clean:
	rm -f *.o $(KERNEL_ELF) $(KERNEL_BIN) vagOS.iso
#Mantén la carpeta iso y su contenido
