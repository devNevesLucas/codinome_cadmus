#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/objeto.h"
#include "../../Structs/barco.h"

void movimentoSuperior ( Barco* barco, Objeto* campo ) {
    if ( barco->objeto->posicaoY >= campo->posicaoY )
        barco->objeto->posicaoY -= 5;
}

void movimentoInferior ( Barco* barco, Objeto* campo ) {
    if ( barco->objeto->posicaoY + barco->objeto->altura <= campo->posicaoY + campo->altura)
        barco->objeto->posicaoY += 5;
}

void movimentoEsquerdo ( Barco* barco, Objeto* campo ) {
    if ( barco->objeto->posicaoX >= campo->posicaoX )
        barco->objeto->posicaoX -= 5;
}

void movimentoDireito ( Barco* barco, Objeto* campo ) {
    if ( barco->objeto->posicaoX + barco->objeto->largura <= campo->posicaoX + campo->largura)
        barco->objeto->posicaoX += 5;
}

/*
    Verifica se alguma cada ponta encostou ou não no ponto máximo do campo, e então, realiza 
    o movimento ou não
*/