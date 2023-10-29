CFLAGS = -Wall -g
LIBS = -lallegro -lallegro_main -lallegro_image -lallegro_font -lallegro_ttf -lallegro_primitives  

STRUCTS = Structs/controle.h Structs/objeto.h Structs/barco.h Structs/teclas.h Structs/projetil.h
MECANICAS_A = Mecanicas/verificadorDeBitmapVazio/verificadorDeBitmapVazio.c Mecanicas/verificadorDeClick/verificadorDeClick.c Mecanicas/montadorDeObjeto/montadorDeObjeto.c
MECANICAS_B = Mecanicas/gerenciadorDeProjetil/gerenciadorDeProjetil.c Mecanicas/movimentoEmCampo/movimentoEmCampo.c Mecanicas/gerenciadorDeTeclado/gerenciadorDeTeclado.c
TELAS = Telas/bossFight/bossFight.c Telas/menu/menu.c Telas/gerenciadorDeFases/gerenciadorDeFases.c

all: inicio

inicio: Cadmus.c

	gcc $(CFLAGS) $(LIBS) $(STRUCTS) $(MECANICAS_A) $(MECANICAS_B) $(TELAS) Cadmus.c -o cadmus

clean:
	rm -f inicio