EXEC = Fila_impressao

all: $(EXEC)

$(EXEC): main.c fila.c
	gcc main.c fila.c -o $(EXEC) -lm

run: all
	./$(EXEC)

clean:
	del /f /q $(EXEC) 2>nul || rm -f $(EXEC)
