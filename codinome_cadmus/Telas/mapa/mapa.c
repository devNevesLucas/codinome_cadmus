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
#include "../../Mecanicas/getSpriteTexto/getSpriteTexto.h"

int mapa(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

    int screen_w = 1280;
    int screen_h = 720;
    bool finalizado = false;
    ALLEGRO_FONT* suprimentos = al_load_font("Auxiliar/AncientModern.ttf", 70 ,0);

    //Define o bot�o dentro da aplica��o, alocando a mem�ria necess�ria para ele e seus itens    
    Objeto* botaoPortugal;
    Objeto* botaoCaboVerde;
    Objeto* botaoMocambique;
    Objeto* botaoMelinde;
    Objeto* botaoCaboTor;
    Objeto* botaoGoa;
    Objeto* background;
    Objeto* voltar;

    //os argumentos são objeto, altura,largura,posição X,posição Y e caminho da imagem respectivamente.
    botaoPortugal = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(botaoPortugal, 72, 168, 120, 16, "Auxiliar/sprites/Mapa/botaoPortugal.png");

    botaoCaboVerde = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(botaoCaboVerde, 72, 168, 0, 222, "Auxiliar/sprites/Mapa/botaoCaboVer.png");

    botaoMocambique = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(botaoMocambique, 72, 168, 650, 455, "Auxiliar/sprites/Mapa/botaoMocambique.png");

    botaoMelinde = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(botaoMelinde , 72, 168, 703, 343, "Auxiliar/sprites/Mapa/botaoMelinde.png");

    botaoCaboTor = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(botaoCaboTor, 72, 168, 454, 628, "Auxiliar/sprites/Mapa/botaoCaboTor.png");

    botaoGoa = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(botaoGoa, 72, 168, 1020, 238, "Auxiliar/sprites/Mapa/botaoGoa.png");

    background = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(background, screen_h, screen_w, 0, 0, "Auxiliar/sprites/Mapa/fundoMapa.png");

    voltar = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(voltar, 80, 99, 9, 633, "Auxiliar/sprites/Mapa/voltar.png");

    //Verifica se a imagem do botao foi atribu�da de forma correta, finaliza a aplica��o caso n�o tenha acontecido
    verificadorDeBitmapVazio(botaoPortugal, controle, &finalizado);
    verificadorDeBitmapVazio(botaoCaboVerde, controle, &finalizado);
    verificadorDeBitmapVazio(botaoCaboTor, controle, &finalizado);
    verificadorDeBitmapVazio(botaoMelinde, controle, &finalizado);
    verificadorDeBitmapVazio(botaoMocambique, controle, &finalizado);
    verificadorDeBitmapVazio(botaoGoa, controle, &finalizado);
    verificadorDeBitmapVazio(voltar, controle, &finalizado);
    verificadorDeBitmapVazio(background, controle, &finalizado);

    float b = 0;
    float y = 0.3;

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

                if (verificadorDeClick(evento.mouse.x, evento.mouse.y, botaoPortugal)) {
                    controle->codFase = 1;
                    controle->suprimentos -= 50;
                    finalizado = true;
                }


                if (verificadorDeClick(evento.mouse.x, evento.mouse.y, botaoCaboTor)) {
                    controle->codFase = 2;
                    controle->suprimentos -= 50;
                    finalizado = true;
                }

                if (verificadorDeClick(evento.mouse.x, evento.mouse.y, botaoGoa)) {
                    controle->codFase = 3;
                    controle->suprimentos -= 50;
                    finalizado = true;
                }

                if (verificadorDeClick(evento.mouse.x, evento.mouse.y, botaoCaboVerde)) {
                    if(controle->caboVerde == false){
                    controle->codFase = 7;
                    controle->caboVerde = true;
                    finalizado = true;
                    }
                }

                if (verificadorDeClick(evento.mouse.x, evento.mouse.y, botaoMocambique)) {
                    if (controle->mocambique == false) {
                        controle->codFase = 7;
                        controle->mocambique = true;
                        finalizado = true;
                    }
                }

                if (verificadorDeClick(evento.mouse.x, evento.mouse.y, botaoMelinde)) {
                    if (controle->melinde == false) {
                        controle->codFase = 7;
                        controle->melinde = true;
                        finalizado = true;
                    }
                }
                
                if (verificadorDeClick(evento.mouse.x, evento.mouse.y, voltar)) {
                    controle->codFase = 0;
                    finalizado = true;
                }
            } 
        }
            // Preenchemos a janela 
   
        al_draw_tinted_bitmap(background->bitmap, al_map_rgb(b,b,b), background->posicaoX, background->posicaoY, 0);
        al_draw_tinted_bitmap(voltar->bitmap, al_map_rgb(b,b,b), voltar->posicaoX, voltar->posicaoY, 0);
        al_draw_tinted_bitmap(botaoPortugal->bitmap, al_map_rgb(b,b,b), botaoPortugal->posicaoX, botaoPortugal->posicaoY, 0);
        al_draw_tinted_bitmap(botaoCaboVerde->bitmap, al_map_rgb(b, b, b), botaoCaboVerde->posicaoX, botaoCaboVerde->posicaoY, 0);
        al_draw_tinted_bitmap(botaoCaboTor->bitmap, al_map_rgb(b,b,b), botaoCaboTor->posicaoX, botaoCaboTor->posicaoY, 0);
        al_draw_tinted_bitmap(botaoMelinde->bitmap, al_map_rgb(b, b, b), botaoMelinde->posicaoX, botaoMelinde->posicaoY, 0);
        al_draw_tinted_bitmap(botaoMocambique->bitmap, al_map_rgb(b, b, b), botaoMocambique->posicaoX, botaoMocambique->posicaoY, 0);
        al_draw_tinted_bitmap(botaoGoa->bitmap, al_map_rgb(b,b,b), botaoGoa->posicaoX, botaoGoa->posicaoY, 0);
        al_draw_textf(suprimentos, al_map_rgb(b, 0, 0),1020, 25, 0, "%i / 250",controle->suprimentos);
        if (b <= 255)
            b += y;

        if (controle->InesDeCastro == false) {
               al_draw_filled_circle(204, 16, 10, al_map_rgb(b, 0, 0));
        }
           else {
            al_draw_filled_circle(204, 16, 10, al_map_rgb(0, b, 0));
           }

        if (controle->adamastor == false) {
            al_draw_filled_circle(496, 709, 10, al_map_rgb(b, 0, 0));
        }
        else {
            al_draw_filled_circle(496, 709, 10, al_map_rgb(0, b, 0));
        }

        if (controle->dionisio == false) {
            al_draw_filled_circle(1094, 247, 10, al_map_rgb(b, 0, 0));
        }
        else {
            al_draw_filled_circle(1094, 247, 10, al_map_rgb(0, b, 0));
        }
        al_flip_display();
        
    }
        //Dest�i a imagem armazenada e libera a mem�ria usada pelo botao
    al_destroy_bitmap(botaoPortugal->bitmap);
    al_destroy_bitmap(botaoCaboVerde->bitmap);
    al_destroy_bitmap(botaoCaboTor->bitmap);
    al_destroy_bitmap(botaoMocambique->bitmap);
    al_destroy_bitmap(botaoMelinde->bitmap);
    al_destroy_bitmap(botaoGoa->bitmap);
    al_destroy_bitmap(background->bitmap);
    al_destroy_bitmap(voltar->bitmap);
    free(botaoPortugal);
    free(botaoCaboVerde);
    free(botaoCaboTor);
    free(botaoMocambique);
    free(botaoMelinde);
    free(botaoGoa);
    free(background);
    free(voltar);

    return 0;
}