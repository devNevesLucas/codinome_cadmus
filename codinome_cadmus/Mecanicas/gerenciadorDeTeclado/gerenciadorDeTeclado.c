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
#include "../../Structs/teclas.h"
#include "../movimentoEmCampo/movimentoEmCampo.h"


void verificaTeclaPressionada( ALLEGRO_EVENT evento, bool teclas[] ) {

    Teclas teclado;

    switch ( evento.keyboard.keycode ) {
        case ALLEGRO_KEY_W:
            teclas[ W ] = true;
            break;
    
        case ALLEGRO_KEY_A:
            teclas[ A ] = true;
            break;

        case ALLEGRO_KEY_S:
            teclas[ S ] = true;
            break;

        case ALLEGRO_KEY_D :
            teclas[ D ] = true;
            break;
    }
}

void verificaTeclaSolta( ALLEGRO_EVENT evento,  bool teclas[] ) {

    Teclas teclado;

    switch ( evento.keyboard.keycode ) {
        case ALLEGRO_KEY_W:
            teclas[ W ] = false;
            break;

        case ALLEGRO_KEY_A:
            teclas[ A ] = false;
            break;

        case ALLEGRO_KEY_S:
            teclas[ S ] = false;
            break;

        case ALLEGRO_KEY_D :
            teclas[ D ] = false;
            break;
    }
}

void gerenciadorDeMovimento( Barco* barco, Objeto* campo, bool teclas[] ) {

    Teclas teclado;

    if ( teclas[ W ] )
        movimentoSuperior( barco, campo );

    if ( teclas[ A ] )
        movimentoEsquerdo( barco, campo );

    if ( teclas[ S ] )
        movimentoInferior( barco, campo );

    if ( teclas[ D ] )
        movimentoDireito( barco, campo );
}