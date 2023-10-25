#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/objeto.h"

void montadorDeObjeto(Objeto* obj, int altura, int largura, int posicaoX, int posicaoY, char* caminhoImagem) {

    obj->altura = altura;
    obj->largura = largura;
    obj->posicaoX = posicaoX;
    obj->posicaoY = posicaoY;
    obj->bitmap = al_load_bitmap(caminhoImagem);
}

/*
    Monta um objeto a partir das informações enviadas para a função
    Economiza linhas de código, afinal isso iria ser repetido para cada objeto instanciado
*/