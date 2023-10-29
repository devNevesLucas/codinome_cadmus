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

/*
    Definindo a struct de objeto, que cont�m, como as pr�prias caracter�sticas j� dizem:
    um bitmap, ou seja, uma imagem
    ints que equivalem as posicoes no eixo X e Y na tela
    ints para a altura e largura do objeto
*/