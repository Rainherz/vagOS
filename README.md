

# VagOS - Sistema Operativo Básico

Este proyecto consiste en el desarrollo de un sistema operativo básico (VagOS) que se ejecuta en un emulador como QEMU. Incluye un kernel que maneja comandos básicos en una interfaz de línea de comandos (CLI).

## Requisitos

### Herramientas necesarias
1. **QEMU**: Un emulador para probar el sistema operativo.
2. **GNU GRUB**: Un gestor de arranque que carga el kernel.
3. **GNU Make**: Para automatizar el proceso de compilación.
4. **i386-elf-gcc**: Compilador para código de 32 bits para sistemas embebidos.

---

## Instalación

### 1. **Instalar QEMU**
Para instalar QEMU en tu sistema, usa los siguientes comandos dependiendo de tu sistema operativo:

#### En Ubuntu/Debian:
```bash
sudo apt update
sudo apt install qemu qemu-system-i386
```



#### En Windows:
Puedes seguir las instrucciones en [QEMU for Windows](https://www.qemu.org/download/#windows) o instalarlo usando [WSL](https://docs.microsoft.com/en-us/windows/wsl/).

### 2. **Instalar GNU GRUB**
GRUB se usa para cargar el kernel en la memoria. Si aún no tienes GRUB instalado, sigue los siguientes pasos:

#### En Ubuntu/Debian:
```bash
sudo apt update
sudo apt install grub-pc grub-common
```


### 3. **Instalar el compilador y las herramientas de ensamblador**
Necesitamos las herramientas de compilación para generar el binario del kernel y la imagen de arranque:

#### En Ubuntu/Debian:
```bash
sudo apt update
sudo apt install build-essential gcc-multilib nasm
sudo apt install i386-elf-gcc i386-elf-binutils
```



## Compilación del Proyecto

### 1. **Limpiar el proyecto**
Para limpiar archivos temporales o antiguos generados durante compilaciones anteriores, usa el siguiente comando:
```bash
make clean
```



## Ejecución del Sistema Operativo en QEMU

### 1. **Generar la imagen ISO**
Para crear una imagen ISO que pueda ser arrancada por QEMU o un dispositivo físico, usa el siguiente comando:

```bash
make 
```


### 2. **Ejecutar en QEMU**
Una vez que tengas la imagen ISO generada, puedes arrancar el sistema operativo en QEMU con el siguiente comando:

```bash
 qemu-system-i386 -cdrom vagOS.iso
```
Este comando iniciará QEMU con la imagen ISO generada y asignará 128MB de RAM al sistema virtual. Puedes ajustar la cantidad de memoria según sea necesario.

---



---

## Estructura de Directorios

- `/src`: Código fuente del kernel y otros componentes.
- `/include`: Archivos de cabecera.
- `/bin`: Archivos binarios compilados.
- `/iso`: Contiene la imagen ISO generada para el arranque.
- `Makefile`: Archivo para automatizar la compilación y creación de la ISO.

---



