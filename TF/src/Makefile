# Variáveis
CC = gcc
CFLAGS = -I /System/Volumes/Data/opt/homebrew/Cellar/sdl2/2.30.9/include/SDL2
LDFLAGS = -L /System/Volumes/Data/opt/homebrew/Cellar/sdl2/2.30.9/lib -lSDL2 -lSDL2_image

# Arquivos fonte e objeto
SRC = main.c game.c board.c player.c graphics.c utils.c types.c
OBJ = $(SRC:.c=.o)
TARGET = conecta4

# Regra padrão para compilar o programa
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

# Limpeza
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean