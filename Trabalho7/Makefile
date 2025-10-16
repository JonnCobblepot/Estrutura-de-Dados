EXEC = Lista_agenda

all: $(EXEC)

$(EXEC): main.c lista.c contato.c
	gcc main.c lista.c contato.c -o $(EXEC) -lm

run: all
	./$(EXEC)

clean:
	del /f /q $(EXEC) 2>nul || rm -f $(EXEC)
