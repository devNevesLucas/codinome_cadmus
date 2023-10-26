#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "objeto.h"

#ifndef Barco_H
#define Barco_H

typedef struct Barco {

    Objeto* objeto;
    int vida;
    bool cooldown;

} Barco;

#endif

/*
    Definindo a struct de Barco, utilizada na batalha contra bosses
    cont�m um objeto, que serve como base para ela
    a vida e um booleano para cooldown, que ser� a invencibilidade ap�s receber um ataque
*/
