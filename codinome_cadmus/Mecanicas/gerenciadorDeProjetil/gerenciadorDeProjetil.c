#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/projetil.h"
#include "../../Structs/objeto.h"
#include "../../Mecanicas/montadorDeObjeto/montadorDeObjeto.h"

void montadorDeProjetil( Projetil *projeteis[], int tamanho ) {
    
    projeteis[0] = (Projetil*)malloc(sizeof(Projetil));
    projeteis[0]->objeto = (Objeto*)malloc(sizeof(Objeto));
    projeteis[0]->objeto->posicaoX = 400;
    projeteis[0]->objeto->posicaoY = 250;
    projeteis[0]->objeto->altura = 50;
    projeteis[0]->objeto->largura = 50;
    projeteis[0]->objeto->bitmap = al_load_bitmap("Auxiliar/sprites/bloco.png");
    projeteis[0]->codMov = 1;
    projeteis[0]->dano = 5;
    projeteis[0]->velocidade = 1;
    projeteis[0]->xInicial = 400;
    projeteis[0]->yInicial = 250;
    projeteis[0]->xFinal = 1100;
    projeteis[0]->yFinal = 600;
    if ( !projeteis[0]->objeto->bitmap ) {
        fprintf(stderr, "Erro ao abrir a imagem do projetil 0");
    }

    projeteis[1] = (Projetil*)malloc(sizeof(Projetil));
    projeteis[1]->objeto = (Objeto*)malloc(sizeof(Objeto));
    projeteis[1]->objeto->posicaoX = 600;
    projeteis[1]->objeto->posicaoY = 0;
    projeteis[1]->objeto->altura = 50;
    projeteis[1]->objeto->largura = 50;
    projeteis[1]->objeto->bitmap = al_load_bitmap("Auxiliar/sprites/blocoLaranja.png");
    projeteis[1]->codMov = 1;
    projeteis[1]->dano = 10;
    projeteis[1]->velocidade = 2;
    projeteis[1]->xInicial = 600;
    projeteis[1]->yInicial = 0;
    projeteis[1]->xFinal = 50;
    projeteis[1]->yFinal = 600;

    if ( !projeteis[1]->objeto->bitmap ) {
        fprintf(stderr, "Erro ao abrir a imagem do projetil 1");
    }
    projeteis[2] = (Projetil*)malloc(sizeof(Projetil));
    projeteis[2]->objeto = (Objeto*)malloc(sizeof(Objeto));
    projeteis[2]->objeto->posicaoX = 750;
    projeteis[2]->objeto->posicaoY = 600;
    projeteis[2]->objeto->altura = 50;
    projeteis[2]->objeto->largura = 50;
    projeteis[2]->objeto->bitmap = al_load_bitmap("Auxiliar/sprites/blocoAzul.png");
    projeteis[2]->codMov = 1;
    projeteis[2]->dano = 15;
    projeteis[2]->velocidade = 3;
    projeteis[2]->xInicial = 25;
    projeteis[2]->yInicial = 250;
    projeteis[2]->xFinal = 600;
    projeteis[2]->yFinal = 450;

    if ( !projeteis[2]->objeto->bitmap ) {
        fprintf(stderr, "Erro ao abrir a imagem do projetil 2");
    }

    projeteis[3] = (Projetil*)malloc(sizeof(Projetil));
    projeteis[3]->objeto = (Objeto*)malloc(sizeof(Objeto));
    projeteis[3]->objeto->posicaoX = 140;
    projeteis[3]->objeto->posicaoY = 125;
    projeteis[3]->objeto->altura = 50;
    projeteis[3]->objeto->largura = 50;
    projeteis[3]->objeto->bitmap = al_load_bitmap("Auxiliar/sprites/blocoVermelho.png");
    projeteis[3]->codMov = 1;
    projeteis[3]->dano = 1;
    projeteis[3]->velocidade = 3;
    projeteis[3]->xInicial = 140;
    projeteis[3]->yInicial = 125;
    projeteis[3]->xFinal = 980;
    projeteis[3]->yFinal = 700;

    if ( !projeteis[3]->objeto->bitmap ) {
        fprintf(stderr, "Erro ao abrir a imagem do projetil 3");
    }

    projeteis[4] = (Projetil*)malloc(sizeof(Projetil));
    projeteis[4]->objeto = (Objeto*)malloc(sizeof(Objeto));
    projeteis[4]->objeto->posicaoX = 500;
    projeteis[4]->objeto->posicaoY = 250;
    projeteis[4]->objeto->altura = 50;
    projeteis[4]->objeto->largura = 50;
    projeteis[4]->objeto->bitmap = al_load_bitmap("Auxiliar/sprites/blocoVerde.png");
    projeteis[4]->codMov = 1;
    projeteis[4]->dano = 25;
    projeteis[4]->velocidade = 1;
    projeteis[4]->xInicial = 500;
    projeteis[4]->yInicial = 250;
    projeteis[4]->xFinal = 900;
    projeteis[4]->yFinal = 675;

    if ( !projeteis[4]->objeto->bitmap ) {
        fprintf(stderr, "Erro ao abrir a imagem do projetil 4");
    }
}

void desenhaProjeteis( Projetil *projeteis[], int tamanho ) {
    for ( int i = 0; i < tamanho; i++ ) {
        al_draw_bitmap( projeteis[i]->objeto->bitmap, 
                        projeteis[i]->objeto->posicaoX,
                        projeteis[i]->objeto->posicaoY,
                        0);
    }
}

void destroiProjeteis( Projetil *projeteis[], int tamanho ) {
    for( int i = 0; i < tamanho; i++ ) {
        al_destroy_bitmap(projeteis[i]->objeto->bitmap);
        free(projeteis[i]->objeto);
    }
}

float mapeamento(int iterador, float rangeInicial, float rangeFinal, float posInicial, float posFinal) {

    float variacaoPosicao = posFinal - posInicial;
    float variacaoRange = rangeFinal - rangeInicial;

    float mult = iterador * variacaoPosicao;
    float produto = mult / variacaoRange;

    return produto + posInicial;
}

void movimentoEmLinhaReta(Projetil *projetil, int *iterador) {

    float posicaoXfinal = mapeamento(iterador, 0, 100, projetil->xInicial, projetil->xFinal);
    float posicaoYfinal = mapeamento(iterador, 0, 100, projetil->yInicial, projetil->yFinal);

    projetil->objeto->posicaoX = posicaoXfinal;
    projetil->objeto->posicaoY = posicaoYfinal;
}

void gerenciadorDeMovimentoDeProjeteis(Projetil *projeteis[], int tamanho, int *iterador) {
    for ( int i = 0; i < tamanho; i++ ) {
        switch(projeteis[i]->codMov) {
            case 1:
                movimentoEmLinhaReta(projeteis[i], iterador);
                break;
        }
    }
}