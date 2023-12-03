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
#include "../../Mecanicas/movimentoDeProjetil/movimentoDeProjetil.h"

bool desenhaProjeteis( Projetil *projeteis[], int tamanho) {

    bool desenhado = false;

    for ( int i = 0; i < tamanho; i++ ) 
        if( projeteis[ i ]->ativado ) {
            al_draw_bitmap( projeteis[i]->objeto->bitmap, 
                            projeteis[i]->objeto->posicaoX,
                            projeteis[i]->objeto->posicaoY,
                            0);
            desenhado = true;
        }

    return desenhado;
}

void destroiProjeteis( Projetil *projeteis[], int tamanho) {
    for( int i = 0; i < tamanho; i++ ) {
        al_destroy_bitmap(projeteis[i]->objeto->bitmap);
        free(projeteis[i]->objeto);
    }
}

void gerenciadorDeMovimentoDeProjeteis(Projetil *projeteis[], Barco *barco, int tamanho) { 
    for ( int i = 0; i < tamanho; i++ ) {
        switch(projeteis[i]->codMov) {
            case 1:
                idaVolta(projeteis[i]);
                break;

            case 2:
                ida(projeteis[i]);
                break;

            case 3:
                estatico(projeteis[i]);
                break;

            case 4: 
                teleguiado(projeteis[i], barco);
                break;

            default:
                ida(projeteis[i]);
                break;
        }
    }
}