CC ?= gcc
CFLAGS_common ?= -Wall -std=gnu99
CFLAGS_option = -O0 -g

EXEC = main.out
all: $(EXEC)

main.out: main.o levenshtein_distance
	$(CC) $(CFLAGS_common) $(CFLAGS_option) \
		main.o levenshtein_distance.o -o $@

main.o: main.c minunit.h
	$(CC) $(CFLAGS_common) $(CFLAGS_option) \
		-c main.c -o $@

levenshtein_distance: levenshtein_distance.c levenshtein_distance.h
	$(CC) $(CFLAGS_common) $(CFLAGS_option) \
		-c $@.c -o $@.o

.PHONY: clean
clean:
	$(RM) $(EXEC) *.o
