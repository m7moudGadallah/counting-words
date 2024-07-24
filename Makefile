CC = gcc
CFLAGS = -Wall -g

SRC_DIR = src
LIB_DIR = lib
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
LIB_FILES = $(wildcard $(LIB_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES)) \
            $(patsubst $(LIB_DIR)/%.c, $(OBJ_DIR)/%.o, $(LIB_FILES))

TARGET = wordcount

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
