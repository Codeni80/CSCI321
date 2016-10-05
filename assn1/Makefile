

CFLAGS =  $(shell sdl2-config --cflags)  -O2 
LIBS = -lSDL2_image $(shell sdl2-config --libs) -lm


main:	 assignment1.cpp Fixed_print.c
	gcc $(CFLAGS) -c Fixed_print.c
	g++ $(CFLAGS) assignment1.cpp  Fixed_print.o -o assignment1 $(LIBS)