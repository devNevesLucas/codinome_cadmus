#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/barco.h"
#include "../../Structs/objeto.h"
#include "../movimentoEmCampo/movimentoEmCampo.h"

void gerenciadorDeTeclado( ALLEGRO_EVENT evento, Barco* barco, Objeto* campo );