#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/controle.h"
#include "../../Structs/objeto.h"

void verificadorDeBitmapVazio( Objeto* objeto, Controle* controle, bool* finalizado ) {
    if ( !objeto->bitmap ) {
        fprintf(stderr, "Erro ao carregar bitmap!\n");
        controle->finalizado = true;
        *finalizado = true;
    }
}