#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/objeto.h"
#include "../../Structs/boss.h"
#include "../../Structs/projetil.h"

float parabola( float posicaoX ) {
    return -(posicaoX * posicaoX) + 12.8 * posicaoX;
}

void movimentaAtaque( Projetil* ataqueJogador ) {

    float multiplicador = parabola( ataqueJogador->objeto->posicaoX / 100 );
    float xResultante = 8 * (multiplicador / 10);

    if ( ataqueJogador->objeto->posicaoX <= 169 ) {
        ataqueJogador->objeto->posicaoX = 170;
        ataqueJogador->operador *= -1;
    }

    if ( ataqueJogador->objeto->posicaoX + ataqueJogador->objeto->largura >= 1123 ) {
        ataqueJogador->objeto->posicaoX = 1100;
        ataqueJogador->operador *= -1;
    }

    ataqueJogador->objeto->posicaoX += xResultante * ataqueJogador->operador;
}

void causaDano( Projetil* ataqueJogador, Boss* boss ) {

    float multiplicador = parabola( ataqueJogador->objeto->posicaoX / 100 );
    int dano = ataqueJogador->dano * (multiplicador / 2);
    float bonus = 1;

    if ( multiplicador >= 40.6 )
        bonus = 2;

    if ( multiplicador >= 35 && multiplicador < 40.6 )
        bonus = 1.5;

    if ( multiplicador > 25 && multiplicador < 35 )
        bonus = 1.2;

    boss->HP -= dano * bonus;
}