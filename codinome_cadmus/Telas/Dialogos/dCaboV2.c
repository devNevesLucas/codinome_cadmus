#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_native_dialog.h"  

#include "../../Structs/controle.h"
#include "../../Structs/objeto.h"
#include "../../Mecanicas/verificadorDeClick/verificadorDeClick.h"
#include "../../Mecanicas/montadorDeObjeto/montadorDeObjeto.h"
#include "../../Mecanicas/verificadorDeBitmapVazio/verificadorDeBitmapVazio.h"

int dCaboV2(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {
	int screen_w = 1280;
	int screen_h = 720;
	bool finalizado = false;

	Objeto* dialogo;
	Objeto* botaoPular;
	Objeto* botaoProximo;
	Objeto* background;
	Objeto* voltar;

	float b = 0;
	float y = 0.2;


	background = (Objeto*)malloc(sizeof(Objeto));
	montadorDeObjeto(background, screen_h, screen_w, 0, 0, "Auxiliar/sprites/Mapa/fundoMapa.png");

	dialogo = (Objeto*)malloc(sizeof(Objeto));
	montadorDeObjeto(dialogo, screen_h, screen_w, 40, 0, "Auxiliar/caixasDeTexto/caboVerde2.png");

	botaoPular = (Objeto*)malloc(sizeof(Objeto));
	montadorDeObjeto(botaoPular, 41, 89, 255, 570, "Auxiliar/caixasDeTexto/pular.png");

	botaoProximo = (Objeto*)malloc(sizeof(Objeto));
	montadorDeObjeto(botaoProximo, 41, 131, 875, 570, "Auxiliar/caixasDeTexto/next.png");

	voltar = (Objeto*)malloc(sizeof(Objeto));
	montadorDeObjeto(voltar, 80, 99, 9, 633, "Auxiliar/sprites/Mapa/voltar.png");

	while (!finalizado) {

		while (!al_is_event_queue_empty(event_queue)) {
			ALLEGRO_EVENT evento;

			al_wait_for_event(event_queue, &evento);

			if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				controle->finalizado = true;
				finalizado = true;
			}
			if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				if (verificadorDeClick(evento.mouse.x, evento.mouse.y, botaoPular)) {
					controle->codFase = 8;
					controle->caboVerde = true;
					finalizado = true;

				}

				if (verificadorDeClick(evento.mouse.x, evento.mouse.y, botaoProximo)) {
					controle->codFase = 8;
					controle->caboVerde = true;
					finalizado = true;
				}

				if (verificadorDeClick(evento.mouse.x, evento.mouse.y, voltar)) {
					controle->codFase = 2;
					finalizado = true;
				}

			}

		}

		al_draw_bitmap(background->bitmap, background->posicaoX, background->posicaoY, 0);
		al_draw_tinted_bitmap(dialogo->bitmap, al_map_rgb(b, b, b), dialogo->posicaoX, dialogo->posicaoY, 0);
		al_draw_tinted_bitmap(botaoPular->bitmap, al_map_rgb(b, b, b), botaoPular->posicaoX, botaoPular->posicaoY, 0);
		al_draw_tinted_bitmap(botaoProximo->bitmap, al_map_rgb(b, b, b), botaoProximo->posicaoX, botaoProximo->posicaoY, 0);
		al_draw_bitmap(voltar->bitmap, voltar->posicaoX, voltar->posicaoY, 0);

		if (b <= 255) {
			b += y;
		}


		al_flip_display();

	}

	al_destroy_bitmap(background->bitmap);
	al_destroy_bitmap(dialogo->bitmap);
	al_destroy_bitmap(botaoProximo->bitmap);
	al_destroy_bitmap(botaoPular->bitmap);
	al_destroy_bitmap(voltar->bitmap);
	free(dialogo);
	free(botaoPular);
	free(botaoProximo);
	free(voltar);
	free(background);


	return 0;

}