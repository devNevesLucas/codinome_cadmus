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
#include "../../Structs/barco.h"

void gerenciadorDeColisao(Projetil *projeteis[], int tamanho, Barco *barco) {

    for(int i = 0; i < tamanho; i++ ) {
        float xBarco_inicial = barco->objeto->posicaoX;
        float xBarco_final = xBarco_inicial + barco->objeto->largura;
        float yBarco_inicial = barco->objeto->posicaoY;
        float yBarco_final = yBarco_inicial + barco->objeto->altura;

        float xProjetil_inicial = projeteis[i]->objeto->posicaoX;
        float xProjetil_final = xProjetil_inicial + projeteis[i]->objeto->largura;
        float yProjetil_inicial = projeteis[i]->objeto->posicaoY;
        float yProjetil_final = yProjetil_inicial + projeteis[i]->objeto->altura;

        bool colisao = false;

        if( xBarco_inicial >= xProjetil_inicial &&
            xBarco_inicial <= xProjetil_final &&
            yBarco_inicial >= yProjetil_inicial &&
            yBarco_inicial <= yProjetil_final )
            colisao = true;
        
        if( xBarco_inicial >= xProjetil_inicial &&
            xBarco_inicial <= xProjetil_final &&
            yBarco_final >= yProjetil_inicial &&
            yBarco_final <= yProjetil_final )
            colisao = true;

        if( xBarco_final >= xProjetil_inicial &&
            xBarco_final <= xProjetil_final &&
            yBarco_inicial >= yProjetil_inicial &&
            yBarco_inicial <= yProjetil_final )
            colisao = true;

        if( xBarco_final >= xProjetil_inicial &&
            xBarco_final <= xProjetil_final &&
            yBarco_final >= yProjetil_inicial &&
            yBarco_final <= yProjetil_final )
            colisao = true;


        if ( colisao && barco->cooldown == 0 ) {
            barco->vida -= projeteis[i]->dano;
            barco->cooldown = 100;
        }
    }
}


