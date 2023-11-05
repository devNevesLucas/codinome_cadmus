#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/controle.h"
#include "../../Structs/objeto.h"
#include "../../Mecanicas/verificadorDeClick/verificadorDeClick.h"
#include "../../Mecanicas/montadorDeObjeto/montadorDeObjeto.h"
#include "../../Mecanicas/verificadorDeBitmapVazio/verificadorDeBitmapVazio.h"

int designBossFight(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue){

    bool finalizado = false;
    bool redesenhar = true;

    Objeto* controlBar;
    Objeto* spriteButton;
    Objeto* movimentacaoButton;
    Objeto* turnoButton;
    Objeto* ataqueButton;

    controlBar = (Objeto*)malloc(sizeof(Objeto));
    spriteButton = (Objeto*)malloc(sizeof(Objeto));
    movimentacaoButton = (Objeto*)malloc(sizeof(Objeto));
    turnoButton = (Objeto*)malloc(sizeof(Objeto));
    ataqueButton = (Objeto*)malloc(sizeof(Objeto));

    montadorDeObjeto(controlBar, 80, 1280, 0, 0, "Auxiliar/sprites/designBossFight/controlBar.png");
    verificadorDeBitmapVazio(controlBar, controle, &finalizado);

    montadorDeObjeto(spriteButton, 60, 280, 40, 10, "Auxiliar/sprites/designBossFight/buttonSelecionar.png");
    verificadorDeBitmapVazio(spriteButton, controle, &finalizado);

    montadorDeObjeto(movimentacaoButton, 60, 361, 559, 10, "Auxiliar/sprites/designBossFight/buttonMov.png");
    verificadorDeBitmapVazio(movimentacaoButton, controle, &finalizado);

    montadorDeObjeto(turnoButton, 60, 280, 940, 10, "Auxiliar/sprites/designBossFight/buttonTurno.png");
    verificadorDeBitmapVazio(turnoButton, controle, &finalizado);

    montadorDeObjeto(ataqueButton, 60, 280, 958, 635, "Auxiliar/sprites/designBossFight/buttonAtaque.png");
    verificadorDeBitmapVazio(ataqueButton, controle, &finalizado);

    while( !finalizado ) {

        while( !al_is_event_queue_empty( event_queue ) ) {
            ALLEGRO_EVENT evento;
            al_wait_for_event( event_queue, &evento );

            if ( evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
                controle->finalizado = true;
                finalizado = true;
            }

            if( evento.type == ALLEGRO_EVENT_TIMER )
                redesenhar = true;
        }

        if ( redesenhar ) {

            al_draw_bitmap(controlBar->bitmap, controlBar->posicaoX, controlBar->posicaoY, 0);
            al_draw_bitmap(spriteButton->bitmap, spriteButton->posicaoX, spriteButton->posicaoY, 0);
            al_draw_bitmap(movimentacaoButton->bitmap, movimentacaoButton->posicaoX, movimentacaoButton->posicaoY, 0);
            al_draw_bitmap(turnoButton->bitmap, turnoButton->posicaoX, turnoButton->posicaoY, 0);
            al_draw_bitmap(ataqueButton->bitmap, ataqueButton->posicaoX, ataqueButton->posicaoY, 0);

            al_flip_display();
            al_clear_to_color( al_map_rgb( 0, 0, 0 ) );
        }
    }

    al_destroy_bitmap(controlBar->bitmap);
    al_destroy_bitmap(spriteButton->bitmap);
    al_destroy_bitmap(movimentacaoButton->bitmap);
    al_destroy_bitmap(turnoButton->bitmap);
    al_destroy_bitmap(ataqueButton->bitmap);

    free( controlBar );
    free( spriteButton );
    free( movimentacaoButton );
    free( turnoButton );
    free( ataqueButton );

    return 0;
}

