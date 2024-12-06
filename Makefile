CC = gcc
C_FLAGS = -Wall -c -g
SRC = Main.c core/FileSystem.c core/Scheduler.c core/ProcessManager.c core/MainSystem.c # Archivos fuente
OBJ = $(SRC:.cpp=.o) # Archivos objeto correspondientes
HEAD = core/FileSystem.h core/Scheduler.h core/ProcessManager.h core/MainSystem.h # Archivos de cabecera
EXEC = VagOS

$(EXEC): $(OBJ)
		$(CC) -o $(EXEC) $(OBJ)

Main.o: Main.c core/FileSystem.h core/Scheduler.h core/ProcessManager.h core/MainSystem.h
		@echo [#] Compilando MAIN
		$(CC) $(CFLAGS) -c $< -o $@

FileSystem.o: core/FileSystem.c core/FileSystem.h
		@echo [#] Compilando FYLESYSTEM
		$(CC) $(CFLAGS) -c $< -o $@

Scheduler.o: core/Scheduler.c core/Scheduler.h
		@echo [#] Compilando SCHEDULER
		$(CC) $(CFLAGS) -c $< -o $@

ProcessManager.o: core/ProcessManager.c core/ProcessManager.h
		@echo [#] Compilando PROCESSMANAGER
		$(CC) $(CFLAGS) -c $< -o $@

MainSystem.o: core/MainSystem.c core/MainSystem.h
		@echo [#] Compilando MAINSYSTEM
		$(CC) $(CFLAGS) -c $< -o $@

run: $(EXEC)
		@echo "Ejecutando $(EXEC)"
		./$(EXEC)

clean:
		@echo "Limpiando archivos objeto y ejecutable"
		rm -f $(OBJ) $(EXEC) $(EXEC).tar.gz

deploy: $(EXEC)
		@echo "Empaquetando archivos para entrega"
		tar -czvf $(EXEC).tar.gz $(EXEC) 

help:
		@echo "Makefile para LinkedList"
		@echo "Comandos disponibles:"
		@echo " make - Compila el programa"
		@echo " make run - Ejecuta el programa"
		@echo " make clean - Elimina los archivos objeto y el ejecutable"
		@echo " make deploy - Empaqueta los archivos para entrega"
		@echo " make help - Muestra esta ayuda"