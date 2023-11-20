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

#include "../../Structs/objeto.h"
#include "../../Structs/projetil.h"


void gravaProjetil(FILE* arquivo, Projetil* projetil);

int contadorDeTurnos(char* caminho);

int contadorDeAtaques(char* caminho, int turno);

void montadorDeProjetil(Projetil *projeteis[], char* caminho, int turno);