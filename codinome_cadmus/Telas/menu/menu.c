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

int menu(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

    int screen_w = 1280;
    int screen_h = 720;
    bool finalizado = false;

/*
    ALLEGRO_FONT* fontT = al_load_font("Auxiliar/AncientModern.ttf", 100, 0);
    ALLEGRO_FONT* fontM = al_load_font("Auxiliar/AncientModern.ttf", 50, 0);

*/

    /*
        Define o botão de jogar dentro da aplicação, alocando a memória necessária para ele e seus itens
    */

    Objeto* buttonJogar;

    buttonJogar = (Objeto*)malloc(sizeof(Objeto));
    buttonJogar->posicaoX = 390;
    buttonJogar->posicaoY = 283;
    buttonJogar->largura = 500;
    buttonJogar->altura = 90;
    buttonJogar->bitmap = al_load_bitmap("Auxiliar/sprites/jogar.png");;

/*
        if ( !fontT || !fontM ) {
            fprintf(stderr, "Erro ao carregar fonte -> menu.c\n");
            controle->finalizado = true;
        }
*/

    //Verifica se a imagem do buttonJogar foi atribuída de forma correta, finaliza a aplicação caso não tenha acontecido
        if ( !buttonJogar->bitmap ) {
            fprintf(stderr, "Erro ao carregar o bitmap do buttonJogar -> menu.c\n");
            controle->finalizado = true;
        }

        //Enquanto não for finalizado, faça...
    while ( !finalizado ) {

        //Enquanto a fila de eventos não estiver vazia, faça...
        while ( !al_is_event_queue_empty( event_queue ) ) {
             ALLEGRO_EVENT evento;

             al_wait_for_event(event_queue, &evento);


             //Caso o botão de fechar seja clicado, encerra a aplicação
             if ( evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
                controle->finalizado = true;
                finalizado = true;
             }

             //Verifica se o mouse foi usado. Caso aconteça, ativa o verificadorDeClick para verificar se foi dentro do buttonJogar
             if ( evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ) {

                if ( verificadorDeClick( evento.mouse.x, evento.mouse.y, buttonJogar ) ) {
                    controle->codFase = 1;
                    finalizado = true;

                    fprintf(stderr, "Erro no verificadorDeClick");
                }
             }  
        }
/*
        al_draw_text(fontT, al_map_rgb(0, 0, 0), screen_w / 2, screen_h / 10, ALLEGRO_ALIGN_CENTRE, "Os Lusiadas");
        al_draw_text(fontM, al_map_rgb(0, 0, 0), screen_w / 2, screen_h / 2.6, ALLEGRO_ALIGN_CENTRE, "Iniciar");
        al_draw_text(fontM, al_map_rgb(0, 0, 0), screen_w / 2, screen_h / 2.2, ALLEGRO_ALIGN_CENTRE, "Opcoes");
        al_draw_text(fontM, al_map_rgb(0, 0, 0), screen_w / 2, screen_h / 1.9, ALLEGRO_ALIGN_CENTRE, "Creditos");
*/


        al_draw_filled_rectangle(200, 200, 230, 230, al_map_rgb(0, 0, 0));
        al_draw_bitmap(buttonJogar->bitmap, buttonJogar->posicaoX, buttonJogar->posicaoY, 0);

        al_flip_display();
        // Preenchemos a janela 
        al_clear_to_color(al_map_rgb(135, 206, 235));
        }

        //Destói a imagem armazenada e libera a memória usada pelo buttonJogar
        al_destroy_bitmap(buttonJogar->bitmap);
        free(buttonJogar);
        return 0;
}