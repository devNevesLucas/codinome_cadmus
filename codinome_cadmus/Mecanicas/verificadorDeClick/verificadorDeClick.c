#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/objeto.h"

bool verificadorDeClick(int clickX, int clickY, Objeto* objeto) {

    if ( 
        clickX >= objeto->posicaoX && clickX <= objeto->posicaoX + objeto->largura &&
        clickY >= objeto->posicaoY && clickY <= objeto->posicaoY + objeto->altura
        )
        return true;

    return false;
}