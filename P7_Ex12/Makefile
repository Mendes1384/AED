CC = gcc
CFLAGS = -Wall -Wextra -std=c99
INCLUDE = -ILib

# Diretórios
LIB_DIR = Lib
S_DIR = S
OBJ_DIR = obj
BIN_DIR = .

# Ficheiros source da Lib
LIB_SOURCES = $(LIB_DIR)/Arvore.c \
              $(LIB_DIR)/DicionarioVetor.c \
              $(LIB_DIR)/FilaLista.c \
              $(LIB_DIR)/Info.c \
              $(LIB_DIR)/Int.c \
              $(LIB_DIR)/IteradorVetor.c \
              $(LIB_DIR)/Lista.c \
              $(LIB_DIR)/Par.c \
              $(LIB_DIR)/PilhaLista.c \
              $(LIB_DIR)/SequenciaVetor.c \
              $(LIB_DIR)/Str.c \
              $(LIB_DIR)/Util.c \
              $(LIB_DIR)/Vetor.c

# Ficheiro main
MAIN_SOURCE = $(S_DIR)/MainAntesDepoisLista.c

# Todos os sources
SOURCES = $(LIB_SOURCES) $(MAIN_SOURCE)

# Ficheiros objeto
OBJECTS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SOURCES)))

# Nome do executável
EXECUTABLE = $(BIN_DIR)/main

# Alvo padrão
all: $(EXECUTABLE)

# Compilar executável
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
	@echo "✓ Compilação concluída: $@"

# Compilar ficheiros objeto
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)/%.o: $(S_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Limpar ficheiros compilados
clean:
	rm -rf $(OBJ_DIR)
	rm -f $(EXECUTABLE)
	@echo "✓ Limpeza concluída"

# Reconstruir (clean + all)
rebuild: clean all

# Executar o programa
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Ajuda
help:
	@echo "Alvos disponíveis:"
	@echo "  make all      - Compila o programa"
	@echo "  make clean    - Remove ficheiros objeto e executável"
	@echo "  make rebuild  - Limpa e compila"
	@echo "  make run      - Compila e executa"
	@echo "  make help     - Mostra esta mensagem"

.PHONY: all clean rebuild run help
