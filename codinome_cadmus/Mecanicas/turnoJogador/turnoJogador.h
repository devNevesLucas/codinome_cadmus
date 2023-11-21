#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/objeto.h"
#include "../../Structs/boss.h"
#include "../../Structs/projetil.h"


float parabola( float posicaoX );

void movimentaAtaque( Projetil* ataqueJogador );

void causaDano( Projetil* ataqueJogador, Boss* boss );