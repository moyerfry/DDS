CC=g++
CFLAGS=-O2 -std=c++14
OBJ_DIR=./build
INC_DIR=./include
SRC_DIR=./src
SOURCES=$(shell ls $(SRC_DIR)/*.cpp)
MK_CALL=mkdir
RM_CALL=rm
RM_RECURSIVE_FLAG=-R
PROGRAM_NAME=DDSService
MAIN_FILE=DDSMain.cpp

all: directories program

directories: $(OBJ_DIR)

program: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJ_DIR)/%.o
	$(CC) -o $@ -I$(INC_DIR) $(shell ls $(OBJ_DIR)/*.o) $(MAIN_FILE)

$(OBJ_DIR)/%.o: $(SOURCES)
	$(CC) -o $(OBJ_DIR)/$(basename $(<F)).o -I$(INC_DIR) -c $<

$(OBJ_DIR):
	$(MK_CALL) $(OBJ_DIR)

clean:
	$(RM_CALL) $(RM_RECURSIVE_FLAG) $(OBJ_DIR)
	$(RM_CALL) $(PROGRAM_NAME)
