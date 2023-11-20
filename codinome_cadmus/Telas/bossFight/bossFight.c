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
#include "../../Structs/barco.h"
#include "../../Structs/projetil.h"
#include "../../Mecanicas/montadorDeObjeto/montadorDeObjeto.h"
#include "../../Mecanicas/gerenciadorDeTeclado/gerenciadorDeTeclado.h"
#include "../../Mecanicas/verificadorDeBitmapVazio/verificadorDeBitmapVazio.h"
#include "../../Mecanicas/gerenciadorDeProjetil/gerenciadorDeProjetil.h"
#include "../../Mecanicas/gerenciadorDeColisao/gerenciadorDeColisao.h"
#include "../../Mecanicas/gerenciadorDeArquivo/gerenciadorDeArquivo.h"

int bossFight(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

    //Declarando as dimens�es da tela
    int ALTURA_TELA = 720;
    int LARGURA_TELA = 1280;

    bool finalizado = false;
    bool redesenhar = true;

    bool teclas[] = { false, false, false, false };
    
    Objeto* AtaqueTeste;
    AtaqueTeste = (Objeto*)malloc(sizeof(Objeto));

    montadorDeObjeto(AtaqueTeste, 50, 50, ALTURA_TELA / 2, LARGURA_TELA / 2, "Auxiliar/sprites/projeteis/bloco.png");
    verificadorDeBitmapVazio(AtaqueTeste, controle, &finalizado);
    
    Projetil *projeteis[6];
    montadorDeProjetil(projeteis, "teste.txt", 2);


    //Definindo vari�vel "campoDeBatalha", que � o campo que o player poder� se mover
    Objeto* campoDeBatalha;
    campoDeBatalha = (Objeto*)malloc(sizeof(Objeto));

    montadorDeObjeto(campoDeBatalha, 300, 400, 440, 300, "Auxiliar/sprites/campo_batalha.png");

    verificadorDeBitmapVazio(campoDeBatalha, controle, &finalizado);
  
    Barco* barco;
    barco = (Barco*)malloc(sizeof(Barco));
    barco->objeto = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(barco->objeto, 40, 40, 620, 410, "Auxiliar/sprites/barco.png");
    barco->vida = 50;
    barco->cooldown = 0;

    verificadorDeBitmapVazio(barco->objeto, controle, &finalizado);
    //Enquanto o programa n�o for finalizado de alguma forma, execute isso
    while ( !finalizado ) {

        while( !al_is_event_queue_empty( event_queue ) ) {
            ALLEGRO_EVENT evento;
            al_wait_for_event( event_queue, &evento );

            //Verifica se o bot�o de fechar foi clicado
            if ( evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
                controle->finalizado = true;
                finalizado = true;
            }

            if ( evento.type == ALLEGRO_EVENT_KEY_DOWN ) 
                verificaTeclaPressionada(evento, teclas);
            

            if ( evento.type == ALLEGRO_EVENT_KEY_UP ) 
                verificaTeclaSolta(evento, teclas);


            if (evento.type == ALLEGRO_EVENT_TIMER)
                redesenhar = true;
        }

        if (redesenhar) {

            redesenhar = false;
            gerenciadorDeMovimento( barco, campoDeBatalha, teclas );

            if( barco->cooldown > 0 ) 
                barco->cooldown--;

            if ( barco-> vida <= 0 ) {
                fprintf(stderr, "game over!\n");
                controle->finalizado = true;
                finalizado = true;
            }
            
            //Desenha na tela o campo de batalha e o teste de ataque
            al_draw_bitmap(AtaqueTeste->bitmap, AtaqueTeste->posicaoX, AtaqueTeste->posicaoY, 0);
            al_draw_bitmap(campoDeBatalha->bitmap, campoDeBatalha->posicaoX, campoDeBatalha->posicaoY, 0);
            
            gerenciadorDeMovimentoDeProjeteis( projeteis );
            
            gerenciadorDeColisao( projeteis, barco );
            
            desenhaProjeteis( projeteis );

            al_draw_bitmap(barco->objeto->bitmap, barco->objeto->posicaoX, barco->objeto->posicaoY, 0);

            al_draw_filled_rectangle(570, 600, 710, 635, al_map_rgb(38, 3, 1));

            if( barco->vida > 0 ) {
                float pixels = barco->vida * 2.8; 
                al_draw_filled_rectangle(570, 600, 570 + pixels, 635, al_map_rgb(255, 47, 34));
            }


            //Realiza o flip do display, que limpa a tela e cria os novos bitmaps, igual a como acontecia no P5.js...
            al_flip_display();

            al_clear_to_color(al_map_rgb(0, 0, 0));
        }
    }

    destroiProjeteis(projeteis);
    free(AtaqueTeste);
    free(campoDeBatalha);

    //Retorna 0 
    return 0;
}