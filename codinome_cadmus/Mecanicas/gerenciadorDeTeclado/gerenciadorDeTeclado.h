#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/barco.h"
#include "../../Structs/objeto.h"
#include "../movimentoEmCampo/movimentoEmCampo.h"

void verificaTeclaPressionada( ALLEGRO_EVENT evento, bool teclas[] );

void verificaTeclaSolta( ALLEGRO_EVENT evento, bool teclas[] );

void gerenciadorDeMovimento( Barco* barco, Objeto* campo,  bool teclas[] );

/*
    funções verificaTeclaPressionada e verificaTeclaSolta: são chamadas quando uma tecla é 
    pressionada ou solta, verificam qual foi e ao fazer isso, trocam o valor da respectiva tecla
    para true ou false; Fazendo com que, na função 'gerenciadorDeMovimento', o barco se mova ou não
    de acordo com quais teclas estão pressionadas ou soltas( true ou false );
*/



