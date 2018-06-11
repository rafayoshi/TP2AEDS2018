CC = gcc
CFLAGS = -Wall -Werror
OBJ = main.o dinamica.o
DEPS = dinamica.h
VFLAGS = --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes
EXEC = ./exec < samples/input10.txt > samples/saida10.txt
TIMED_RUN = time ./exec < samples/input5.txt > samples/saida5.txt

all: exec

exec: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o exec dinamica.

valgrind:
	valgrind $(VFLAGS) $(EXEC)
run:
	$(EXEC)
timed:
	$(TIMED_RUN)
