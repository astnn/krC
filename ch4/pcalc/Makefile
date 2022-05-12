# Makefile for pcalc
# Creates objectfiles from %.c and %.h files and compiles it into the executable
# defined as BIN (for binary).
# Usage: call "make" in the directory to compile binary, or "make clean" to
# remove binary and object files.
BIN = pcalc
SRC = main.c stack.c getch.c getop.c
OBJ = $(SRC:.c=.o)
HDR = $(SRC:.c=.h)

CC = gcc
CFLAGS = -Wall	#Compile flags: -Wall: Warnings all
LDLIBS = -lm 		#Linked libraries: -lm: Link Math

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(LDLIBS)

%.o: %.c $(HDR) # Note1
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rvf *.o $(BIN)
