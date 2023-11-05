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

int menu(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

    int screen_w = 1280;
    int screen_h = 720;
    bool finalizado = false;

    //   Define o bot�o de jogar dentro da aplica��o, alocando a mem�ria necess�ria para ele e seus itens    
    Objeto* buttonJogar;
    Objeto* buttonDesign;

    buttonJogar = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(buttonJogar, 90, 500, 390, 283, "Auxiliar/sprites/jogar.png");
    
    buttonDesign = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(buttonDesign, 45, 250, 35, 650, "Auxiliar/sprites/devFase.png");

    //Verifica se a imagem do buttonJogar foi atribu�da de forma correta, finaliza a aplica��o caso n�o tenha acontecido
    verificadorDeBitmapVazio( buttonJogar, controle, &finalizado );
    verificadorDeBitmapVazio( buttonDesign, controle, &finalizado );

        //Enquanto n�o for finalizado, fa�a...
    while ( !finalizado ) {

        //Enquanto a fila de eventos n�o estiver vazia, fa�a...
        while ( !al_is_event_queue_empty( event_queue ) ) {
             ALLEGRO_EVENT evento;

             al_wait_for_event(event_queue, &evento);


             //Caso o bot�o de fechar seja clicado, encerra a aplica��o
             if ( evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
                controle->finalizado = true;
                finalizado = true;
             }

             //Verifica se o mouse foi usado. Caso aconte�a, ativa o verificadorDeClick para verificar se foi dentro do buttonJogar
             if ( evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ) {

                if ( verificadorDeClick( evento.mouse.x, evento.mouse.y, buttonJogar ) ) {
                    controle->codFase = 1;
                    finalizado = true;
                }

                if( verificadorDeClick( evento.mouse.x, evento.mouse.y, buttonDesign ) ) {
                    controle->codFase = 2;
                    finalizado = true;
                }
             }  
        }
        
        al_draw_filled_rectangle(200, 200, 230, 230, al_map_rgb(0, 0, 0));
        
        al_draw_bitmap(buttonJogar->bitmap, buttonJogar->posicaoX, buttonJogar->posicaoY, 0);
        al_draw_bitmap(buttonDesign->bitmap, buttonDesign->posicaoX, buttonDesign->posicaoY, 0);

        al_flip_display();
        // Preenchemos a janela 
        al_clear_to_color(al_map_rgb(135, 206, 235));
        }

        //Dest�i a imagem armazenada e libera a mem�ria usada pelo buttonJogar
        al_destroy_bitmap(buttonJogar->bitmap);
        al_destroy_bitmap(buttonDesign->bitmap);

        free(buttonDesign);
        free(buttonJogar);
        
        return 0;
}