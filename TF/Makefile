# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -I/usr/local/include/SDL2 -D_THREAD_SAFE
LDFLAGS = -L/usr/local/lib -lSDL2 -lSDL2_image

# Arquivos
SRC = main.c
OBJ = $(SRC:.c=.o)
TARGET = connect4

# Regras
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean