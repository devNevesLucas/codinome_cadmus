#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/controle.h"

typedef struct Objeto {
    ALLEGRO_BITMAP* bitmap;
    int posicaoX;
    int posicaoY;
    int largura;
    int altura;
} Objeto;

int bossFight(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

    int ALTURA_TELA = 720;
    int LARGURA_TELA = 1280;

    Objeto* AtaqueTeste;

    AtaqueTeste = (Objeto*)malloc(sizeof(Objeto));
    AtaqueTeste->altura = 50;
    AtaqueTeste->largura = 50;
    AtaqueTeste->posicaoX = ALTURA_TELA / 2;
    AtaqueTeste->posicaoY = LARGURA_TELA / 2;
    AtaqueTeste->bitmap = al_load_bitmap("Auxiliar/sprites/bloco.png");


    while ( !controle->finalizado ) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(event_queue, &evento);

        if ( evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) 
            controle->finalizado = true;

        al_draw_bitmap(AtaqueTeste->bitmap, AtaqueTeste->posicaoX, AtaqueTeste->posicaoY, 0);

        al_flip_display();

        al_clear_to_color(al_map_rgb(0, 0, 0));
    }

    free(AtaqueTeste);

    return 0;
}