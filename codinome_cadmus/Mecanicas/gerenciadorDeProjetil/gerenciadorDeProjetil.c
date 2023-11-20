#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/projetil.h"
#include "../../Structs/objeto.h"
#include "../../Mecanicas/montadorDeObjeto/montadorDeObjeto.h"
#include "../../Mecanicas/getSpriteProjetil/getSpriteProjetil.h"


void desenhaProjeteis( Projetil *projeteis[]) {

    int tamanho = 6;

    for ( int i = 0; i < tamanho; i++ ) 
        if( projeteis[ i ]->ativado )
            al_draw_bitmap( projeteis[i]->objeto->bitmap, 
                            projeteis[i]->objeto->posicaoX,
                            projeteis[i]->objeto->posicaoY,
                            0);
}

void destroiProjeteis( Projetil *projeteis[]) {

    int tamanho = 6;

    for( int i = 0; i < tamanho; i++ ) {
        al_destroy_bitmap(projeteis[i]->objeto->bitmap);
        free(projeteis[i]->objeto);
    }
}

float mapeamento(int iterador, float rangeInicial, float rangeFinal, float posInicial, float posFinal) {

    float variacaoPosicao = posFinal - posInicial;
    float variacaoRange = rangeFinal - rangeInicial;

    float mult =  iterador * variacaoPosicao;
    float produto = mult / variacaoRange;

    return produto + posInicial;
}

void movimentoEmLinhaReta(Projetil *projetil) {

    float posicaoXfinal = mapeamento(projetil->acumulador, 0, 100, projetil->xInicial, projetil->xFinal);
    float posicaoYfinal = mapeamento(projetil->acumulador, 0, 100, projetil->yInicial, projetil->yFinal);

    projetil->objeto->posicaoX = posicaoXfinal;
    projetil->objeto->posicaoY = posicaoYfinal;
}

void gerenciadorDeMovimentoDeProjeteis(Projetil *projeteis[]) {

    int tamanho = 6;

    for ( int i = 0; i < tamanho; i++ ) {

        if (projeteis[i]->acumulador <= 0) {
            projeteis[i]->acumulador = 0;
            projeteis[ i ]->operador *= -1;
        }

        if (projeteis[i]->acumulador >= 100) {
            projeteis[i]->acumulador = 100;
            projeteis[i]->operador *= -1;
        }


        projeteis[ i ]->acumulador += projeteis[ i ]->velocidade * projeteis[ i ]->operador;

        switch(projeteis[i]->codMov) {
            case 1:
                movimentoEmLinhaReta(projeteis[i]);
                break;
        }
    }
}