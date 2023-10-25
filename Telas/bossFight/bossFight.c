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
#include "../../Mecanicas/montadorDeObjeto/montadorDeObjeto.h"


int bossFight(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

    int ALTURA_TELA = 720;
    int LARGURA_TELA = 1280;
    bool finalizado = false;

    Objeto* AtaqueTeste;
    AtaqueTeste = (Objeto*)malloc(sizeof(Objeto));

    montadorDeObjeto(AtaqueTeste, 50, 50, ALTURA_TELA / 2, LARGURA_TELA / 2, "Auxiliar/sprites/bloco.png");
    
    if ( !AtaqueTeste->bitmap ) {
        fprintf(stderr, "Erro ao carregar bitmap do AtaqueTeste -> bossFight.c\n");
        finalizado = true;
        controle->finalizado = true;
    }

    Objeto* campoDeBatalha;
    campoDeBatalha = (Objeto*)malloc(sizeof(Objeto));

    montadorDeObjeto(campoDeBatalha, 300, 400, 440, 300, "Auxiliar/sprites/campo_batalha.png");

    if ( !campoDeBatalha->bitmap ) {
        fprintf(stderr, "Erro ao carregar bitmap do campoDeBatalha -> bossFight.c\n");
        finalizado = true;
        controle->finalizado = true;
    }
  
    while ( !finalizado ) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(event_queue, &evento);

        if ( evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
            controle->finalizado = true;
            finalizado = true;
        }

        al_draw_bitmap(campoDeBatalha->bitmap, campoDeBatalha->posicaoX, campoDeBatalha->posicaoY, 0);
        al_draw_bitmap(AtaqueTeste->bitmap, AtaqueTeste->posicaoX, AtaqueTeste->posicaoY, 0);

        al_flip_display();

        al_clear_to_color(al_map_rgb(0, 0, 0));
    }

    free(AtaqueTeste);
    free(campoDeBatalha);

    return 0;
}