CC = gcc

DEBUG = @ 

APP_NAME = EmpMGR
APP_SRC_FILES = main.c 

MAIN_DIR = .

# -I is a linux label to "include" 
INCLUDE_DIR = -I $(MAIN_DIR)/include

# This command finds all files within src/ 
LIB_SRC_FILES = $(shell find $(MAIN_DIR)/src/ -name '*.c')

SRC_FILES += $(APP_SRC_FILES)
SRC_FILES += $(LIB_SRC_FILES)

MAKE_CMD = $(CC) $(SRC_FILES) -o bin/$(APP_NAME) $(INCLUDE_DIR)

all:
	$(DEBUG)$(MAKE_CMD)

clean: 
	rm -f $(MAIN_DIR)/$(APP_NAME)