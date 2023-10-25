CFLAGS = -Wall -g
LIBS = -lallegro -lallegro_main -lallegro_image -lallegro_font -lallegro_ttf -lallegro_primitives  

STRUCTS = Structs/controle.h Structs/objeto.h Structs/barco.h
MECANICAS = Mecanicas/verificadorDeClick/verificadorDeClick.c Mecanicas/montadorDeObjeto/montadorDeObjeto.c
TELAS = Telas/bossFight/bossFight.c Telas/menu/menu.c Telas/gerenciadorDeFases/gerenciadorDeFases.c

all: inicio

inicio: Cadmus.c

	gcc $(CFLAGS) $(LIBS) $(STRUCTS) $(MECANICAS) $(TELAS) Cadmus.c -o cadmus

clean:
	rm -f inicio