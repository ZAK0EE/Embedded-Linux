#@Ziad (Learn-in-Depth)

CC=
LIB_PATH= .
CFLAGS= -std=c11 -O0 -Wall -g
INCS= ./include
LIBS= -lrt 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As  = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name = Femto_Shell
STATIC=YES
all: $(Project_name)
	@echo ====================== Build Succeded ======================
%.o: %.c
	$(CC)gcc $(CFLAGS) -c  -I $(INCS)  $< -o $@
%.o: %.s
	$(CC)as $(CFLAGS) -c  $(INCS) $< -o $@
$(Project_name): $(OBJ) $(AsOBJ)
	$(CC)gcc  $(CFLAGS) $^ -I $(INCS) -l$(LIBS) -L $(LIB_PATH)  -o $@
%.a: 
		$(CC)gcc -c *.c
		ar -rs $@ *.o
%.so:
		$(CC)gcc -c -fPIC *.c
		$(CC)gcc -shared *.o -o $@

	

	

clean_all:
	@rm -f *.o *.exe $(Project_name)
clean:
	@rm -f $(Project_name)
