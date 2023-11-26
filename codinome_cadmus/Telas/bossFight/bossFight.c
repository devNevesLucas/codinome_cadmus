#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/controle.h"
#include "../../Structs/objeto.h"
#include "../../Structs/barco.h"
#include "../../Structs/projetil.h"
#include "../../Structs/boss.h"
#include "../../Mecanicas/montadorDeObjeto/montadorDeObjeto.h"
#include "../../Mecanicas/gerenciadorDeTeclado/gerenciadorDeTeclado.h"
#include "../../Mecanicas/verificadorDeBitmapVazio/verificadorDeBitmapVazio.h"
#include "../../Mecanicas/gerenciadorDeProjetil/gerenciadorDeProjetil.h"
#include "../../Mecanicas/gerenciadorDeColisao/gerenciadorDeColisao.h"
#include "../../Mecanicas/gerenciadorDeArquivo/gerenciadorDeArquivo.h"
#include "../../Mecanicas/turnoJogador/turnoJogador.h"
#include "../../Mecanicas/getBoss/getBoss.h"


int bossFight(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

    srand(time(NULL));

    int ALTURA_TELA = 720;
    int LARGURA_TELA = 1280;

    bool finalizado = false;
    bool redesenhar = true;

    bool teclas[] = { false, false, false, false };

    Boss* boss;
    boss = (Boss*)malloc(sizeof(Boss));

    getBoss(controle, boss);

    bool reloadProjetil = true;
    bool turnoMaquina = true;

    int qtdTurnos = contadorDeTurnos(boss->pathAtaques);
    int qtdAtaques = 0;
    int projeteisCooldown = 50;

    fprintf(stderr, "%d -> quantidade de turnos!\n", qtdTurnos);

    Objeto* AtaqueTeste;
    AtaqueTeste = (Objeto*)malloc(sizeof(Objeto));

    montadorDeObjeto(AtaqueTeste, 50, 50, ALTURA_TELA / 2, LARGURA_TELA / 2, "Auxiliar/sprites/projeteis/bloco.png");
    verificadorDeBitmapVazio(AtaqueTeste, controle, &finalizado);
    
    Projetil *projeteis[100];
    
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
  
    Objeto* turnoJogador;
    turnoJogador = (Objeto*)malloc(sizeof(Objeto));

    montadorDeObjeto(turnoJogador, 250, 985, 150, 299, "Auxiliar/sprites/turno_player.png");
    verificadorDeBitmapVazio(turnoJogador, controle, &finalizado);

    Projetil* ataqueJogador;
    ataqueJogador = (Projetil*)malloc(sizeof(Projetil));

    ataqueJogador->objeto = (Objeto*)malloc(sizeof(Objeto));
    montadorDeObjeto(ataqueJogador->objeto, 235, 15, 170, 306, "Auxiliar/sprites/ponteiro_player.png");
    verificadorDeBitmapVazio(ataqueJogador->objeto, controle, &finalizado);
    
    ataqueJogador->dano = 25;
    ataqueJogador->operador = 1;


    while ( !finalizado ) {

        while( !al_is_event_queue_empty( event_queue ) ) {
            ALLEGRO_EVENT evento;
            al_wait_for_event( event_queue, &evento );

            //Verifica se o bot�o de fechar foi clicado
            if ( evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
                controle->finalizado = true;
                finalizado = true;
            }

            if ( evento.type == ALLEGRO_EVENT_KEY_DOWN ) {
                verificaTeclaPressionada(evento, teclas);

                if( evento.keyboard.keycode == ALLEGRO_KEY_SPACE && !turnoMaquina ) {
                    causaDano(ataqueJogador, boss);
                    turnoMaquina = true;
                    reloadProjetil = true;

                    ataqueJogador->objeto->posicaoX = 170;
                    ataqueJogador->operador = 1;

                    barco->cooldown = 0; 
                    barco->objeto->posicaoX = 620; 
                    barco->objeto->posicaoY = 410;

                    projeteisCooldown = 50;
                }
            }
            
            if ( evento.type == ALLEGRO_EVENT_KEY_UP ) 
                verificaTeclaSolta(evento, teclas);


            if (evento.type == ALLEGRO_EVENT_TIMER)
                redesenhar = true;
        }

        if (redesenhar) {

            redesenhar = false;

            al_draw_filled_rectangle(570, 600, 710, 635, al_map_rgb(38, 3, 1));

            if( barco->vida > 0 ) {
                float pixels = barco->vida * 2.8; 
                al_draw_filled_rectangle(570, 600, 570 + pixels, 635, al_map_rgb(255, 47, 34));
            }


            al_draw_filled_rectangle(65, 39, 1215, 79, al_map_rgb(38, 3, 1));

            if ( boss->HP > 0) {
                float variacaoTamanho = 1215 - 65;
                float diferenca = variacaoTamanho / boss->HPinicial;

                float pixels = boss->HP * diferenca;
                al_draw_filled_rectangle(65, 39, 65 + pixels, 79, al_map_rgb(255, 47, 34));
            }

            if ( turnoMaquina ) {
                gerenciadorDeMovimento( barco, campoDeBatalha, teclas );

                if( reloadProjetil ) {   
                    int turnoRandom = rand() % qtdTurnos + 1;
                    montadorDeProjetil(projeteis, boss->pathAtaques, turnoRandom);
                    qtdAtaques = contadorDeAtaques(boss->pathAtaques, turnoRandom);
                    reloadProjetil = false;
                }

                if( barco->cooldown > 0 ) 
                    barco->cooldown--;

                if ( barco-> vida <= 0 ) {
                    fprintf(stderr, "Game over!\n");
                    controle->codFase = 4;
                    finalizado = true;
                }

                if (boss->HP <= 0) {
                    fprintf(stderr, "%s foi a baixo!\n", boss->nome);
                    controle->codFase = 5;
                    controle->InesDeCastro = true;
                    finalizado = true;
                }

                al_draw_bitmap(AtaqueTeste->bitmap, AtaqueTeste->posicaoX, AtaqueTeste->posicaoY, 0);
                al_draw_bitmap(campoDeBatalha->bitmap, campoDeBatalha->posicaoX, campoDeBatalha->posicaoY, 0);
                
                if ( projeteisCooldown > 0 )
                    projeteisCooldown--;
                    
                if ( projeteisCooldown == 0 ) {
                    gerenciadorDeMovimentoDeProjeteis( projeteis, qtdAtaques );           
                    gerenciadorDeColisao( projeteis, barco, qtdAtaques );
                    
                    turnoMaquina = desenhaProjeteis( projeteis, qtdAtaques );
                }

                al_draw_bitmap(barco->objeto->bitmap, barco->objeto->posicaoX, barco->objeto->posicaoY, 0);
            
            } else {
                movimentaAtaque(ataqueJogador);

                al_draw_bitmap(turnoJogador->bitmap, turnoJogador->posicaoX, turnoJogador->posicaoY, 0);
                al_draw_bitmap(ataqueJogador->objeto->bitmap, ataqueJogador->objeto->posicaoX, ataqueJogador->objeto->posicaoY, 0);
            }

            //Realiza o flip do display, que limpa a tela e cria os novos bitmaps, igual a como acontecia no P5.js...
            al_flip_display();

            al_clear_to_color(al_map_rgb(0, 0, 0));
        }
    }

    destroiProjeteis(projeteis, qtdAtaques);
    free(turnoJogador);
    free(ataqueJogador);
    free(AtaqueTeste);
    free(campoDeBatalha);

    //Retorna 0 
    return 0;
}