CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c
OUT = program

all: $(OUT)

$(OUT): $(SRC)	
	@$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	./$(OUT)

clean:
	@rm -f $(OUT)