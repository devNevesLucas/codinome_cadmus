#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/controle.h"

#ifndef gameOver_H
#define gameOver_H

int gameOver(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue);

#endif