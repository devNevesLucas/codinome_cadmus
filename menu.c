#include <iostream>
#include <allegro5/allegro.h>
//Coloca as fontes
#include <allegro5/allegro_font.h>
//True type font
#include <allegro5/allegro_ttf.h>
//Formas primitivas
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

int screen_w = 1280;
int screen_h = 720;


int menu(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue) {

        al_draw_text(fontT, al_map_rgb(0, 0, 0), screen_w / 2, screen_h / 10, ALLEGRO_ALIGN_CENTRE, "Os Lusíadas");
        al_draw_text(fontM, al_map_rgb(0, 0, 0), screen_w / 2, screen_h / 2.6, ALLEGRO_ALIGN_CENTRE, "Iniciar");
        al_draw_text(fontM, al_map_rgb(0, 0, 0), screen_w / 2, screen_h / 2.2, ALLEGRO_ALIGN_CENTRE, "Opções");
        al_draw_text(fontM, al_map_rgb(0, 0, 0), screen_w / 2, screen_h / 1.9, ALLEGRO_ALIGN_CENTRE, "Créditos");
        //o retangulo
        //al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(0, 0, 0));
        // Atualiza a tela
        al_flip_display();
        // Preenchemos a janela 
        al_clear_to_color(al_map_rgb(135, 206, 235));
}
