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
#include "../designBossFight/designBossFight.h"
#include "../Dialogos/dPortugal1.h"
#include "../Dialogos/dPortugal2.h"
#include "../Dialogos/dCaboV1.h"
#include "../Dialogos/dCaboV2.h"
#include "../Dialogos/dCaboT1.h"
#include "../Dialogos/dCaboT2.h"
#include "../Dialogos/dGoa1.h"
#include "../Dialogos/dGoa2.h"
#include "../Dialogos/dMelinde.h"
#include "../Dialogos/dMocambique.h"
#include "../mapa/mapa.h"
#include "../gameOver/gameOver.h"
#include "../telainicial/telaInicial.h"

void gerenciadorDeFases(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

        switch (controle->codFase) {

            case 0:
                telaInicial(controle, display, event_queue);
                return;

            case 1:
                menu(controle, display, event_queue);
                return;

            case 2:
                mapa(controle, display, event_queue);
                return;

            case 3:
                dPortugal1(controle, display, event_queue);
                return;

            case 4:
                dPortugal2(controle, display, event_queue);
                return;

            case 5:
                bossFight(controle, display, event_queue);
                return;

            case 6:
                dCaboV1(controle, display, event_queue);
                return;

            case 7:
                dCaboV2(controle, display, event_queue);
                return;

            case 8:
                bossFight(controle, display, event_queue);
                return;

            case 9:
                dCaboT1(controle, display, event_queue);
                return;

            case 10:
                dCaboT2(controle, display, event_queue);
                return;

            case 11:
                bossFight(controle, display, event_queue);
                return;

            case 12:
                dMocambique(controle, display, event_queue);
                return;

            case 13:
                dMelinde(controle, display, event_queue);
                return;

            case 14:
                dGoa1(controle, display, event_queue);
                return;

            case 15:
                dGoa2(controle, display, event_queue);
                return;

            case 16:
                bossFight(controle, display, event_queue);
                return;

            case 17:
                gameOver(controle, display, event_queue);
                return;

            default:
                break;
        }
        return;
}

/*
    Gerencia as fases atrav�s de um Switch, cada fase possui um c�digo �nico definido dentro do codFase
*/