# Set the compiler and linker flags
CC = gcc
CFLAGS = -c

# Define the targets
Wakanda Forever: 
	@./output/custom_terminal.o

Build from scratch:
	$(CC) $(CFLAGS)  lib_terminal.c -o ./output/lib_terminal.o
	ar rcs ./library/lib_terminal.a ./output/lib_terminal.o
	$(CC)  custom_terminal.c -o ./output/custom_terminal.o -L. ./library/lib_terminal.a
	make Wakanda Forever