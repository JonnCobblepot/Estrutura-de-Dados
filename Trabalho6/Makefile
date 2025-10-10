EXEC = task_in_deque

all: $(EXEC)

$(EXEC): main.c deque.c task.c
	gcc main.c deque.c task.c -o $(EXEC) -lm

run: all
	./$(EXEC)

clean:
	del /f /q $(EXEC) 2>nul || rm -f $(EXEC)