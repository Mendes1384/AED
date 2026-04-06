# Makefile for P3_Parque Project
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -I./H
LDFLAGS = -lm

# Directories
SRC_DIR = S
HEADER_DIR = H
OBJ_DIR = obj
BIN_DIR = .

# Output executable
TARGET = $(BIN_DIR)/main

# Source files (excluding ParqueOriginal.c which appears to be an alternate version)
SOURCES = $(SRC_DIR)/MainParque.c \
          $(SRC_DIR)/Automovel.c \
          $(SRC_DIR)/Parque.c \
          $(SRC_DIR)/Util.c

# Object files (place them in obj directory)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Header dependencies
HEADERS = $(HEADER_DIR)/*.h

# Default target
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

# Help target
help:
	@echo "Available targets:"
	@echo "  make              - Build the project"
	@echo "  make clean        - Remove object files and executable"
	@echo "  make distclean    - Remove all generated files"
	@echo "  make rebuild      - Clean and build from scratch"
	@echo "  make run          - Build and run the program"
	@echo "  make help         - Show this help message"

# Phony targets (not actual files)
.PHONY: all clean distclean rebuild run help
