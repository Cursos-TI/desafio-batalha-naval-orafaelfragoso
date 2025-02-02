# Variáveis de compilação
CC = clang
CFLAGS = -Wall -Iinclude

# Diretórios
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = .
INCLUDE_DIR = include

# Arquivos fonte e objetos
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
EXEC = batalhanaval

# Regras de compilação
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(EXEC) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)/$(EXEC)

.PHONY: all clean
