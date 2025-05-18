CC=gcc

all: main

main: src/main.c
	$(CC) src/main.c -o primecalculator