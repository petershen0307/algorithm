CC ?= gcc
CFLAGS_common ?= -Wall -std=gnu99
CFLAGS_option = -O0
EXEC = test_main.out
all: $(EXEC)

debug: CFLAGS_option += -g -DDEBUG
debug: $(EXEC)

test_main.out: test_main levenshtein_distance
	$(CC) $(CFLAGS_common) $(CFLAGS_option) \
		test_main.o levenshtein_distance.o -o $@

test_main: test_main.c minunit.h
	$(CC) $(CFLAGS_common) $(CFLAGS_option) \
		-c $@.c -o $@.o

levenshtein_distance: levenshtein_distance.c levenshtein_distance.h
	$(CC) $(CFLAGS_common) $(CFLAGS_option) \
		-c $@.c -o $@.o

.PHONY: clean
clean:
	$(RM) $(EXEC) *.o
