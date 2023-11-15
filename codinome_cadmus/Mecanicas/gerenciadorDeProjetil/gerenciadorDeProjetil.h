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

void montadorDeProjetil(Projetil *projeteis[], int tamanho);

void desenhaProjeteis(Projetil *projeteis[], int tamanho);

void destroiProjeteis(Projetil *projeteis[], int tamanho);

float mapeamento(int iterador, float rangeInicial, float rangeFinal, float posInicial, float posFinal, float velocidade);

void movimentoEmLinhaReta(Projetil *projetil);

void gerenciadorDeMovimentoDeProjeteis(Projetil *projeteis[], int tamanho);