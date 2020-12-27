CC = gcc
CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm 
EXEC = main
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
all:	$(EXEC)
main:	$(OBJ)
		$(CC) -o $@ $^ $(LDFLAGS)
%.o:	%.c
		$(CC) -o $@ -c $< $(CFLAGS)
clean:
		rm -rf *.o *~
mrproper: clean
		rm -rf $(EXEC)