#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/projetil.h"
#include "../../Structs/barco.h"
#include "../../Structs/objeto.h"


bool desenhaProjeteis(Projetil *projeteis[], int tamanho);

void destroiProjeteis(Projetil *projeteis[], int tamanho);

void gerenciadorDeMovimentoDeProjeteis(Projetil *projeteis[], Barco *barco, int tamanho);