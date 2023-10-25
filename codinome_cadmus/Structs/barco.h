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
    int velocidade;
    bool cooldown;

} Barco;

#endif

/*
    Definindo a struct de Barco, utilizada na batalha contra bosses
    contém um objeto, que serve como base para ela
    a vida, a velocidade e um booleano para cooldown, que será a invencibilidade após receber um ataque
*/
