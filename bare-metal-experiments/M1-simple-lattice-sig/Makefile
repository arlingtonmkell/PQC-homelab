CC=gcc
CFLAGS=-Wall -Wextra -I./src
SRC=src/main.c src/lattice.c src/keygen.c src/sign.c src/verify.c src/utils.c
OBJ=$(SRC:.c=.o)
TARGET=lattice_sig

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
