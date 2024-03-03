CC = gcc
CFLAGS = -Wall -Wextra -g 

EXEC = main
SRC = main.c stack.c 
OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

all: $(EXEC)

%.o:%.c 
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

-include $(DEPS)

clean: 
	$(RM) $(OBJ) $(DEPS) $(EXEC)