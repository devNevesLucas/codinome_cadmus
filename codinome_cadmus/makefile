CFLAGS = -Wall -g
LIBS = -lallegro -lallegro_main -lallegro_image -lallegro_font -lallegro_ttf -lallegro_primitives  

STRUCTS = Structs/controle.h Structs/objeto.h Structs/boss.h Structs/barco.h Structs/teclas.h Structs/projetil.h
MECANICAS_A = Mecanicas/verificadorDeBitmapVazio/verificadorDeBitmapVazio.c Mecanicas/getSpriteProjetil/getSpriteProjetil.c Mecanicas/verificadorDeClick/verificadorDeClick.c Mecanicas/montadorDeObjeto/montadorDeObjeto.c
MECANICAS_B = Mecanicas/movimentoDeProjetil/movimentoDeProjetil.c Mecanicas/gerenciadorDeArquivo/gerenciadorDeArquivo.c Mecanicas/gerenciadorDeProjetil/gerenciadorDeProjetil.c Mecanicas/gerenciadorDeColisao/gerenciadorDeColisao.c
MECANICAS_C = Mecanicas/turnoJogador/turnoJogador.c Mecanicas/movimentoEmCampo/movimentoEmCampo.c Mecanicas/gerenciadorDeTeclado/gerenciadorDeTeclado.c
TELAS = Telas/designBossFight/designBossFight.c Telas/mapa/mapa.c Telas/bossFight/bossFight.c Telas/menu/menu.c Telas/gerenciadorDeFases/gerenciadorDeFases.c

all: inicio

inicio: Cadmus.c

	gcc $(CFLAGS) $(LIBS) $(STRUCTS) $(MECANICAS_A) $(MECANICAS_B) $(MECANICAS_C) $(TELAS) Cadmus.c -o cadmus

clean:
	rm -f inicio