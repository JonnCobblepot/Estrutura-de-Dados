EXEC = playlist

all: $(EXEC)

$(EXEC): main.c lista.c
	gcc main.c lista.c -o $(EXEC) -lm

run: all
	./$(EXEC)

clean:
	del /f /q $(EXEC) 2>nul || rm -f $(EXEC)