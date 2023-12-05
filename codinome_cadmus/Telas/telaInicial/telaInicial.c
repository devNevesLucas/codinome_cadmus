#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_native_dialog.h"  

#include "../../Structs/controle.h"
#include "../../Structs/objeto.h"
#include "../../Mecanicas/verificadorDeClick/verificadorDeClick.h"
#include "../../Mecanicas/montadorDeObjeto/montadorDeObjeto.h"
#include "../../Mecanicas/verificadorDeBitmapVazio/verificadorDeBitmapVazio.h"

int telaInicial(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

    int screen_w = 1280;
    int screen_h = 720;
    bool finalizado = false;
    
    Objeto* telaInicial;
    telaInicial = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(telaInicial, screen_h, screen_w, 0, 0, "Auxiliar/telaInicial/telaInicial.png");

    float b = 0;
    float y = 0.3;

    float proxFase = 0;


    while (!finalizado) {

        while (!al_is_event_queue_empty(event_queue)) {
            ALLEGRO_EVENT evento;

            al_wait_for_event(event_queue, &evento);

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                controle->finalizado = true;
                finalizado = true;
            }

            if (verificadorDeClick(evento.mouse.x, evento.mouse.y, telaInicial)) {
                controle->codFase = 1;
                finalizado = true;
            }


        }

        al_draw_tinted_bitmap(telaInicial->bitmap, al_map_rgb(b, b, b), telaInicial->posicaoX, telaInicial->posicaoY, 0);

        if (b <= 255) {
            b += y;
        }
        if (proxFase <= 255) {
            proxFase += y;
        }

        al_flip_display();
    }

    al_destroy_bitmap(telaInicial->bitmap);
    free(telaInicial);
    return 0;
}