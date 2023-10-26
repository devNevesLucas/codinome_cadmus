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

void movimentoSuperior ( Barco* barco, Objeto* campo );

void movimentoInferior ( Barco* barco, Objeto* campo );

void movimentoEsquerdo ( Barco* barco, Objeto* campo );

void movimentoDireito ( Barco* barco, Objeto* campo );