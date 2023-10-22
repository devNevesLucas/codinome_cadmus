#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>

#include "../../Structs/controle.h"
#include "../menu/menu.h"

void gerenciadorDeFases(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

        switch (controle->codFase) {
            case 0:
                menu(controle, display, event_queue);
                return;
            
            default:
                break;
        }

        return;
}

