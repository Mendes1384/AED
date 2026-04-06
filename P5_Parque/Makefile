# Makefile para o P5_Parque
# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -g -I./h
LDFLAGS = -lm

# Pastas
SRC_DIR = s
HEADER_DIR = h
OBJ_DIR = obj
BIN_DIR = .

# Output executavel
TARGET = $(BIN_DIR)/main

# Ficheiros Source
SOURCES = $(SRC_DIR)/MainParque.c \			###############################
          $(SRC_DIR)/Automovel.c \			# Mudar consoante o exercicio #
          $(SRC_DIR)/Parque.c \				###############################
          $(SRC_DIR)/SequenciaVetor.c \
          $(SRC_DIR)/Vetor.c \
          $(SRC_DIR)/Info.c \
          $(SRC_DIR)/Int.c \
          $(SRC_DIR)/Par.c \
          $(SRC_DIR)/IteradorVetor.c \
          $(SRC_DIR)/Util.c

# Ficheiros Object (Por na pasta obj)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Fi8cheiros Header
HEADERS = $(HEADER_DIR)/*.h

# Target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "✓ Build successful: $(TARGET)"

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "✓ Compiled: $<"

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET)
	@echo "✓ Cleaned build artifacts"

# Clean everything including executables and binaries
distclean: clean
	rm -f *.o
	@echo "✓ Full clean complete"

# Recompile everything
rebuild: clean all

# Run the program
run: $(TARGET)
	@echo "Running $(TARGET)..."
	./$(TARGET)

# Run with input file
run-input: $(TARGET)
	@echo "Running $(TARGET) with input..."
	./$(TARGET) < in.txt

# Help 
help:
	@echo "Available targets:"
	@echo "  make              - Build the project"
	@echo "  make clean        - Remove object files and executable"
	@echo "  make distclean    - Remove all generated files"
	@echo "  make rebuild      - Clean and build from scratch"
	@echo "  make run          - Build and run the program"
	@echo "  make run-input    - Build and run with input file"
	@echo "  make help         - Show this help message"

# Phony targets (not actual files)
.PHONY: all clean distclean rebuild run run-input help
