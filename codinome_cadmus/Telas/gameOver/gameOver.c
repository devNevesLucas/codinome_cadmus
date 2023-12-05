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

int gameOver(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

    int screen_w = 1280;
    int screen_h = 720;
    bool finalizado = false;

    //Define o bot�o dentro da aplica��o, alocando a mem�ria necess�ria para ele e seus itens    
    Objeto* botaoSair;
    Objeto* botaoTentar;
    Objeto* fundoGameOver;

    //os argumentos são objeto, altura,largura,posição X,posição Y e caminho da imagem respectivamente.
    botaoSair = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(botaoSair, 369, 70, 235, 490, "Auxiliar/sprites/gameOver/sair.png");

    botaoTentar = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(botaoTentar, 369, 70, 831, 490, "Auxiliar/sprites/gameOver/tentar.png");

    fundoGameOver = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(fundoGameOver, screen_h, screen_w, 0, 0, "Auxiliar/sprites/gameOver/fundoGameOver.png");

    //Verifica se a imagem do botao foi atribu�da de forma correta, finaliza a aplica��o caso n�o tenha acontecido
    verificadorDeBitmapVazio(botaoSair, controle, &finalizado);
    verificadorDeBitmapVazio(botaoTentar, controle, &finalizado);
    verificadorDeBitmapVazio(fundoGameOver, controle, &finalizado);


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

                if (verificadorDeClick(evento.mouse.x, evento.mouse.y, botaoSair)) {
                    controle->finalizado = true;
                    finalizado = true;
                }

                if (verificadorDeClick(evento.mouse.x, evento.mouse.y, botaoTentar)) {
                    controle->codFase = 2;
                    finalizado = true;
                }
               
            } 
        }
            // Preenchemos a janela 
        al_draw_bitmap(fundoGameOver->bitmap, fundoGameOver->posicaoX, fundoGameOver->posicaoY, 0);
        al_draw_bitmap(botaoSair->bitmap, botaoSair->posicaoX, botaoSair->posicaoY, 0);
        al_draw_bitmap(botaoTentar->bitmap, botaoTentar->posicaoX, botaoTentar->posicaoY, 0);
        al_flip_display();
        
    }
        //Dest�i a imagem armazenada e libera a mem�ria usada pelo botao
    al_destroy_bitmap(botaoSair->bitmap);
    al_destroy_bitmap(botaoTentar->bitmap);
    al_destroy_bitmap(fundoGameOver->bitmap);
    free(botaoSair);
    free(botaoTentar);
    free(fundoGameOver);
    return 0;
}