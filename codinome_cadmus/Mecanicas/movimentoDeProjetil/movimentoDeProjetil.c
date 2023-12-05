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
#include "../../Structs/barco.h"
#include "../../Mecanicas/montadorDeObjeto/montadorDeObjeto.h"
#include "../../Mecanicas/getSpriteProjetil/getSpriteProjetil.h"


float mapeamento(int iterador, float rangeInicial, float rangeFinal, float posInicial, float posFinal) {

    float variacaoPosicao = posFinal - posInicial;
    float variacaoRange = rangeFinal - rangeInicial;

    float mult =  iterador * variacaoPosicao;
    float produto = mult / variacaoRange;

    return produto + posInicial;
}

void idaVolta(Projetil *projetil) {

    if (projetil->acumulador <= 0) {
        projetil->acumulador = 0;
        projetil->ativado = false;
    }

    if (projetil->acumulador >= 100) {
        projetil->acumulador = 100;
        projetil->operadorX *= -1;
    }


    projetil->acumulador += projetil->velocidadeX * projetil->operadorX;

    float posicaoXfinal = mapeamento(projetil->acumulador, 0, 100, projetil->xInicial, projetil->xFinal);
    float posicaoYfinal = mapeamento(projetil->acumulador, 0, 100, projetil->yInicial, projetil->yFinal);

    projetil->objeto->posicaoX = posicaoXfinal;
    projetil->objeto->posicaoY = posicaoYfinal;
}

void ida(Projetil *projetil) {

    if (projetil->acumulador >= 100) 
            projetil->ativado = false;
    
    projetil->acumulador += projetil->velocidadeX * projetil->operadorX;

    float posicaoXfinal = mapeamento(projetil->acumulador, 0, 100, projetil->xInicial, projetil->xFinal);
    float posicaoYfinal = mapeamento(projetil->acumulador, 0, 100, projetil->yInicial, projetil->yFinal);

    projetil->objeto->posicaoX = posicaoXfinal;
    projetil->objeto->posicaoY = posicaoYfinal;
}

void estatico(Projetil *projetil) {

    if (projetil->acumulador >= 100)
        projetil->ativado = false;

    projetil->acumulador += projetil->velocidadeX;
}

void teleguiado(Projetil* projetil, Barco *barco) {

    if (projetil->acumulador >= 100)
        projetil->ativado = false;

    if (projetil->acumulador < 80) {
        projetil->xFinal = barco->objeto->posicaoX;
        projetil->yFinal = barco->objeto->posicaoY;
    }
    
    projetil->acumulador += projetil->velocidadeX * projetil->operadorX;

    float posicaoXfinal = mapeamento(projetil->acumulador, 0, 100, projetil->xInicial, projetil->xFinal);
    float posicaoYfinal = mapeamento(projetil->acumulador, 0, 100, projetil->yInicial, projetil->yFinal);

    projetil->objeto->posicaoX = posicaoXfinal;
    projetil->objeto->posicaoY = posicaoYfinal;
}

void rastro(Projetil* projetil, Barco *barco) {
    
  if (projetil->acumulador >= 100)
        projetil->ativado = false;

    if (projetil->xFinal == 0 && projetil->yFinal == 0) {
        projetil->xFinal = barco->objeto->posicaoX;
        projetil->yFinal = barco->objeto->posicaoY;
    }

    projetil->acumulador += projetil->velocidadeX * projetil->operadorX;

    float posicaoXfinal = mapeamento(projetil->acumulador, 0, 100, projetil->xInicial, projetil->xFinal);
    float posicaoYfinal = mapeamento(projetil->acumulador, 0, 100, projetil->yInicial, projetil->yFinal);

    projetil->objeto->posicaoX = posicaoXfinal;
    projetil->objeto->posicaoY = posicaoYfinal;
}