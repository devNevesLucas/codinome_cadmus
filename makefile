CFLAGS = -Wall
LIBS = -lallegro -lallegro_main -lallegro_image -lallegro_font -lallegro_ttf -lallegro_primitives

all: inicio

inicio: Cadmus.cpp
	gcc $(CFLAGS) -o cadmus Cadmus.cpp $(LIBS)

clean:
	rm -f inicio