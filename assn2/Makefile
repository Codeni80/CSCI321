CFLAGS =  $(shell sdl2-config --cflags)  -O2 
LIBS = -lSDL2_image $(shell sdl2-config --libs) -lm


main:	 assignment2.cpp
	g++ $(CFLAGS) assignment2.cpp -o assignment2 $(LIBS)