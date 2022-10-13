CC=gcc

SRC_DIR := src
SRC_SUB:= $(dir $(wildcard $(SRC_DIR)/*/))

BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj
DIRS := $(OBJ_DIR) $(OBJ_DIR)/femto_utilities
BIN_DIR := $(BUILD_DIR)/bin

LIB_SRC := libfiles
LIB_DIR := $(BUILD_DIR)/libfiles

EXE := $(BIN_DIR)/Femto_Shell
SRC := $(wildcard $(SRC_DIR)/*.c  $(SRC_DIR)/*/*.c) 
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iinclude
CFLAGS   := -Wall
LDFLAGS  := -lfemtomath
LDLIBS   :=  -L $(LIB_DIR)

SHARED=NO

ifeq ($(SHARED), NO)
LIB_TYPE =libfemtomath.a
else ifeq ($(SHARED), YES)
LIB_TYPE =libfemtomath.so
endif

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)| $(BIN_DIR)  library
	$(CC)    $^  $(LDFLAGS) $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DIRS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
		
$(LIB_DIR)/%.o: $(LIB_SRC)/%.c | $(LIB_DIR)
ifeq ($(SHARED), NO)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
else ifeq ($(SHARED), YES)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -fPIC $< -o $@
endif
	
	
	
library: $(LIB_DIR)/$(LIB_TYPE) 

$(LIB_DIR)/%.a: build/libfiles/femto_fact.o  build/libfiles/femto_fib.o build/libfiles/femto_rand.o 
		ar -rs $@ $^


		
%.so: build/libfiles/femto_fact.o  build/libfiles/femto_fib.o build/libfiles/femto_rand.o 
	$(CC) $(CPPFLAGS) $(CFLAGS) -shared $^ -o $@
	
		
$(BIN_DIR) $(DIRS) $(LIB_DIR):
	mkdir -p $@
	


clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR) $(LIB_DIR)

-include $(OBJ:.o=.d)