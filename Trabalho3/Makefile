EXEC = Calc_Polonesa.exe

all: $(EXEC)

$(EXEC): main.c pilha.c pilha.h
	gcc main.c pilha.c -o $(EXEC) -lm

run: all
	.\$(EXEC)

clean:
	del /f /q $(EXEC) 2>nul || rm -f $(EXEC)