EXEC = Calc_Polonesa

all: $(EXEC)

$(EXEC): main.c pilha.c
	gcc main.c pilha.c -o $(EXEC) -lm

run: all
	./$(EXEC)

clean:
	del /f /q $(EXEC) 2>nul || rm -f $(EXEC)