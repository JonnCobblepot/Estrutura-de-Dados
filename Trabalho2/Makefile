# Makefile (windows)
EXEC = calculadoraConjuntos.exe

all: $(EXEC)

$(EXEC): main.c conjunto.c conjunto.h
	gcc main.c conjunto.c -o $(EXEC)

run: all
	.\$(EXEC)

clean:
	del /f /q $(EXEC) 2>nul || rm -f $(EXEC)
