CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm 

INC = constante.h
SRC = main.c init_jeu.c keyboard_event.c screen.c jeu.c 
OBJ = $(SRC:%.c=%.o)

PROG = TheNaughtyBird

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<

TheNaughtyBird: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

clean:
	rm -f *~ *.o $(PROG)
