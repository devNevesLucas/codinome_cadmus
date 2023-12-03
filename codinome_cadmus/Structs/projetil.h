#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "objeto.h"

#ifndef Projetil_H
#define Projetil_H

typedef struct Projetil {

    Objeto* objeto;
    bool ativado;
    int codMov;
    int dano;
    int acumulador;
    int operadorX;
    int operadorY;
    float xInicial;
    float yInicial;
    float xFinal;
    float yFinal;
    float velocidadeX;
    float velocidadeY;
    int cooldown;

} Projetil;


#endif

/*
    Definição da struct projetil. Ela recebe um objeto como base, com seu bitmap, posições e tamanhos
    contém um codMov, seu código utilizado para movimentação em tela, suas posições finais,
    sua velocidade e o dano que gera ao jogador.
*/