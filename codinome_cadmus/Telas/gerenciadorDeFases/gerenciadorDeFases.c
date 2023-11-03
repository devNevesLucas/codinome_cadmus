#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>

#include "../../Structs/controle.h"
#include "../menu/menu.h"
#include "../bossFight/bossFight.h"
#include "../mapa/mapa.h"

void gerenciadorDeFases(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

        switch (controle->codFase) {

            case 0:
                menu(controle, display, event_queue);
                return;
            case 1:
                bossFight(controle, display, event_queue);
                return;
            case 2:
                mapa(controle, display, event_queue);
                 return;
            default:
                break;
        }

        return;
}

/*
    Gerencia as fases atrav�s de um Switch, cada fase possui um c�digo �nico definido dentro do codFase
*/