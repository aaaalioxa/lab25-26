CC = gcc
LD = gcc
CCFLAGS = -std=c99
LDFLAGS =
OBJ = main.o dequeue.o
HDR = deque.h
all: $(OBJ)
	@$(LD) $(LDFLAGS) -o main $(OBJ)
main.o: main.c $(HDR)
	@$(CC) $(CCFLAGS) -c main.c
dequeue.o: dequeue.c $(HDR)
	@$(CC) $(CCFLAGS) -c dequeue.c
clean:
	@rm -f *.o main
