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

void montadorDeProjetil( Projetil *projeteis[], int tamanho ) {
    
    FILE *arquivo;
    char linha[100];
    char* resultado;

    float dados[12];
    arquivo = fopen("teste.txt", "r");

    if ( arquivo == NULL ) 
            fprintf(stderr, "Erro ao abrir arquivo!");
    

    for( int i = 0; i < tamanho; i++ ) {
        resultado = fgets( linha, 100, arquivo );

        int iteradorLinha = 0;

        for( int j = 0; j < 12; j++ ) {
            char substring[5];

            strncpy(substring, resultado + iteradorLinha, 5);
            substring[4] = '\0';

            dados[ j ] = atof( substring );
            iteradorLinha += 5;
        }

        projeteis[ i ] = (Projetil*)malloc(sizeof(Projetil));
        projeteis[ i ]->objeto = (Objeto*)malloc(sizeof(Objeto));
        projeteis[ i ]->objeto->posicaoX = dados[ 0 ];
        projeteis[ i ]->objeto->posicaoY = dados[ 1 ];
        projeteis[ i ]->objeto->altura = dados[ 2 ];
        projeteis[ i ]->objeto->largura = dados[ 3 ];
        projeteis[ i ]->objeto->bitmap = al_load_bitmap(getSpriteProjetil((int)dados[ 4 ]));
        projeteis[ i ]->ativado = true;
        projeteis[ i ]->codMov = (int)dados[ 5 ];
        projeteis[ i ]->codSprite = (int)dados[ 4 ];
        projeteis[ i ]->dano = (int)dados[ 6 ];
        projeteis[ i ]->incremento = 0;
        projeteis[ i ]->operador = 1;
        projeteis[ i ]->velocidade = dados[ 7 ];
        projeteis[ i ]->xInicial = dados[ 8 ];
        projeteis[ i ]->yInicial = dados[ 9 ];
        projeteis[ i ]->xFinal = dados[ 10 ];
        projeteis[ i ]->yFinal = dados[ 11 ];

        if ( !projeteis[ i ]->objeto->bitmap ) {
            fprintf(stderr, "Erro ao abrir a imagem do projétil %d!\n", i);
        }
    }
    fclose( arquivo );
}

void desenhaProjeteis( Projetil *projeteis[], int tamanho ) {
    for ( int i = 0; i < tamanho; i++ ) 
        if( projeteis[ i ]->ativado )
            al_draw_bitmap( projeteis[i]->objeto->bitmap, 
                            projeteis[i]->objeto->posicaoX,
                            projeteis[i]->objeto->posicaoY,
                            0);
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

void movimentoEmLinhaReta(Projetil *projetil) {

    float posicaoXfinal = mapeamento(projetil->incremento, 0, 100, projetil->xInicial, projetil->xFinal);
    float posicaoYfinal = mapeamento(projetil->incremento, 0, 100, projetil->yInicial, projetil->yFinal);

    projetil->objeto->posicaoX = posicaoXfinal;
    projetil->objeto->posicaoY = posicaoYfinal;
}

void gerenciadorDeMovimentoDeProjeteis(Projetil *projeteis[], int tamanho) {
    for ( int i = 0; i < tamanho; i++ ) {

        if( projeteis[ i ]->incremento == 100 )
            projeteis[ i ]->operador *= -1;

        projeteis[ i ]->incremento += projeteis[ i ]->operador;

        switch(projeteis[i]->codMov) {
            case 1:
                movimentoEmLinhaReta(projeteis[i]);
                break;
        }
    }
}