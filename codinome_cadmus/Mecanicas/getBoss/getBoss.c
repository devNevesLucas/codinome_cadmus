#define _CRT_SECURE_NO_DEPRECATE
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>

#include "../../Structs/controle.h"
#include "../../Structs/boss.h"

void getBoss(Controle* controle, Boss* boss) {

    switch (controle->codFase) {

    case 1:
        boss->HPinicial = 5000;
        boss->HP = 5000;
        strcpy(boss->nome, "Inês de castro");
        strcpy(boss->pathBackground, "Auxiliar/bosses/ines/inesDeCastro.png");
        strcpy(boss->pathAtaques, "Auxiliar/bosses/ines/ines.txt");
        break;

    case 2:
        boss->HPinicial = 7500;
        boss->HP = 7500;
        strcpy(boss->nome, "Gigante Adamastor");
        strcpy(boss->pathBackground, "Auxiliar/bosses/adamastor/adamastor.png");
        strcpy(boss->pathAtaques, "Auxiliar/bosses/adamastor/adamastor.txt");
        break;

    case 3:
        boss->HPinicial = 9000;
        boss->HP = 9000;
        strcpy(boss->nome, "Dionísio");
        strcpy(boss->pathBackground, "Auxiliar/bosses/dionisio/dionisio.png");
        strcpy(boss->pathAtaques, "Auxiliar/bosses/dionisio/dionisio.txt");
        break;

    default:
        boss->HPinicial = 25000;
        boss->HP = 25000;
        strcpy(boss->nome, "Algo deu errado");
        strcpy(boss->pathBackground, "Auxiliar/bosses/dionisio/dionisio.png");
        strcpy(boss->pathAtaques, "Auxiliar/bosses/dionisio/dionisio.txt");
        break;
    }
}