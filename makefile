CFLAGS = -Wall
LIBS = -lallegro -lallegro_main -lallegro_image -lallegro_font -lallegro_ttf -lallegro_primitives Structs/controle.h Telas/bossFight/bossFight.c Telas/menu/menu.c Telas/gerenciadorDeFases/gerenciadorDeFases.c 

all: inicio

inicio: Cadmus.c

	gcc $(CFLAGS) $(LIBS) Cadmus.c -o cadmus

clean:
	rm -f inicio