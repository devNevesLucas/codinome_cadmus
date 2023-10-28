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

void verificadorDeBitmapVazio( Objeto* objeto, Controle* controle, bool* finalizado );

/*
    Verifica se a imagem de um objeto não foi carregada, caso ocorra erro,
    que acontece quando houve uma tentativa de carregar o bitmap mal sucedida, o que faz com que
    aquele item retorne NULL dentro do objeto, o jogo é encerrado.
*/