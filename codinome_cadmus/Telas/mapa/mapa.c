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

int mapa(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

    int screen_w = 1280;
    int screen_h = 720;
    bool finalizado = false;

    //   Define o bot�o dentro da aplica��o, alocando a mem�ria necess�ria para ele e seus itens    
    Objeto* botaoBoss1;
    Objeto* background;

    botaoBoss1 = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(botaoBoss1, 90, 500, 390, 283, "Auxiliar/sprites/boss1.png");

    background = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(background, screen_h, screen_w, 0, 0, "Auxiliar/sprites/fundoMapa.png");

    //Verifica se a imagem do buttonJogar foi atribu�da de forma correta, finaliza a aplica��o caso n�o tenha acontecido
    verificadorDeBitmapVazio(botaoBoss1, controle, &finalizado);

    while (!finalizado) {

        //Enquanto a fila de eventos n�o estiver vazia, fa�a...
        while (!al_is_event_queue_empty(event_queue)) {
            ALLEGRO_EVENT evento;

            al_wait_for_event(event_queue, &evento);

            //Caso o bot�o de fechar seja clicado, encerra a aplica��o
            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                controle->finalizado = true;
                finalizado = true;
            }

            //Verifica se o mouse foi usado. Caso aconte�a, ativa o verificadorDeClick para verificar se foi dentro do botao
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

                if (verificadorDeClick(evento.mouse.x, evento.mouse.y, botaoBoss1)) {
                    controle->codFase = 1;
                    finalizado = true;
                }
            }
            // Preenchemos a janela 
            al_clear_to_color(al_map_rgb(196, 164, 132));
            al_draw_bitmap(background->bitmap, background->posicaoX, background->posicaoY, 0);
            al_draw_bitmap(botaoBoss1->bitmap, botaoBoss1->posicaoX, botaoBoss1->posicaoY, 0);

            al_flip_display();

            // Preenchemos a janela 
            
        }

        //Dest�i a imagem armazenada e libera a mem�ria usada pelo botao
        al_destroy_bitmap(botaoBoss1->bitmap);
        al_destroy_bitmap(background->bitmap);
        free(botaoBoss1);
        free(background);

        return 0;
    }
}