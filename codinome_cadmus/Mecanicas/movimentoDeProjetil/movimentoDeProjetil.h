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


float mapeamento(int iterador, float rangeInicial, float rangeFinal, float posInicial, float posFinal);

void idaVolta(Projetil *projetil);

void ida(Projetil *projetil);