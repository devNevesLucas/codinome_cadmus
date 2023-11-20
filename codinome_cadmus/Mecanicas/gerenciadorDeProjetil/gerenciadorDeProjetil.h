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

void desenhaProjeteis(Projetil *projeteis[]);

void destroiProjeteis(Projetil *projeteis[]);

float mapeamento(int iterador, float rangeInicial, float rangeFinal, float posInicial, float posFinal);

void movimentoEmLinhaReta(Projetil *projetil);

void gerenciadorDeMovimentoDeProjeteis(Projetil *projeteis[]);