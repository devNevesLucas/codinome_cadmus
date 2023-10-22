#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/controle.h"

int menu(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

    int screen_w = 1280;
    int screen_h = 720;
    int fim = 0;

    ALLEGRO_FONT* fontT = al_load_font("../../Auxiliar/AncientModern.ttf", 100, 0);
    ALLEGRO_FONT* fontM = al_load_font("../../Auxiliar/AncientModern.ttf", 50, 0);

    while ( !controle->finalizado ) {

        while ( !al_is_event_queue_empty( event_queue ) ) {
             ALLEGRO_EVENT evento;

             al_wait_for_event(event_queue, &evento);

             if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                controle->finalizado = true;
                fim = 1;
             }
        }
/*
        al_draw_text(fontT, al_map_rgb(0, 0, 0), screen_w / 2, screen_h / 10, ALLEGRO_ALIGN_CENTRE, "Os Lusiadas");
        al_draw_text(fontM, al_map_rgb(0, 0, 0), screen_w / 2, screen_h / 2.6, ALLEGRO_ALIGN_CENTRE, "Iniciar");
        al_draw_text(fontM, al_map_rgb(0, 0, 0), screen_w / 2, screen_h / 2.2, ALLEGRO_ALIGN_CENTRE, "Opcoes");
        al_draw_text(fontM, al_map_rgb(0, 0, 0), screen_w / 2, screen_h / 1.9, ALLEGRO_ALIGN_CENTRE, "Creditos");

*/
             
        al_flip_display();
        // Preenchemos a janela 
        al_clear_to_color(al_map_rgb(135, 206, 235));
        }    

        return 0;
}
