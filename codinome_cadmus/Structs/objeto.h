#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#ifndef Objeto_H
#define Objeto_H

typedef struct Objeto {
    ALLEGRO_BITMAP* bitmap;
    int posicaoX;
    int posicaoY;
    int largura;
    int altura;
} Objeto;

#endif