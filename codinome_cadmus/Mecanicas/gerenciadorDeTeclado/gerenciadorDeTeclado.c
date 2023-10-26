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

void gerenciadorDeTeclado( ALLEGRO_EVENT evento, Barco* barco, Objeto* campo ) {

    switch ( evento.keyboard.keycode ) {
        case ALLEGRO_KEY_W:
            movimentoSuperior( barco, campo );
            break;
        
        case ALLEGRO_KEY_S:
           movimentoInferior( barco, campo );
           break;

        case ALLEGRO_KEY_A:
            movimentoEsquerdo( barco, campo );
            break;

        case ALLEGRO_KEY_D:
             movimentoDireito( barco, campo );
             break;
    }
}

/*
    Verifica se alguma das teclas de movimento ( WASD ) foi teclada. Quando acontece,
    envia o barco e o campo de batalha para a função específica que verifica se o barco ainda
    esta dentro dos limites do campo.
*/