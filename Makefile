CC=g++
CFLAGS=-O2 -std=c++14
BUILD_DIR=./build
SRC_DIR=./src
SOURCES=$(shell ls $(SRC_DIR)/*.cpp)
MK_DIR_CALL=mkdir
RM_CALL=rm
RM_RECURSIVE_FLAG=-R
PROGRAM_NAME=DDSService
MAIN_FILE=DDSMain.cpp
PATH_TO_COMMON=../Common
INC_DIR=-Iinclude -I$(PATH_TO_COMMON)/include

all: directories program examples

directories: $(BUILD_DIR)

program: Common $(PROGRAM_NAME)

examples:
	$(CC) -o SocketExamples SocketExamples.cpp

$(PROGRAM_NAME): UDPInterface ANetInterface
	$(CC) -o $(PROGRAM_NAME) $(INC_DIR) $(addsuffix .o,$(addprefix $(BUILD_DIR)/,$^)) $(MAIN_FILE) $(CFLAGS)

UDPInterface:
	$(CC) -o $(BUILD_DIR)/$@.o -c $(SRC_DIR)/$@.cpp $(INC_DIR) $(CFLAGS)
	
ANetInterface:
	$(CC) -o $(BUILD_DIR)/$@.o -c $(SRC_DIR)/$@.cpp $(INC_DIR) $(CFLAGS)

$(BUILD_DIR):
	$(MK_DIR_CALL) $(BUILD_DIR)

Common:
	cd $(PATH_TO_COMMON) && make lib
	cp $(PATH_TO_COMMON)/*.a .

clean:
	$(RM_CALL) $(RM_RECURSIVE_FLAG) $(BUILD_DIR)
	$(RM_CALL) $(PROGRAM_NAME)
	$(RM_CALL) *.a
