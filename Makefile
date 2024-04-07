# Makefile for CSE 13S, Winter 2024, Assignment 3

CC = clang
CFLAGS = -Wall -Wextra -Wconversion -Wdouble-promotion -Wstrict-prototypes -Werror -pedantic
CFLAGS += -g

.PHONY: all clean format test
all: xd test

xd: xd.o
	$(CC) $(CFLAGS) $< -o xd

xd.o: xd.c
	$(CC) $(CFLAGS) -c xd.c

format:
	clang-format -i -style=file *.[ch]

clean:
	rm -f xd *.o

test: tests
