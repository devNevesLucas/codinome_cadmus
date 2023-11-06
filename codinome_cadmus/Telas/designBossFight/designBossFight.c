#define _CRT_SECURE_NO_DEPRECATE
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
#include "../../Mecanicas/verificadorDeClick/verificadorDeClick.h"
#include "../../Mecanicas/montadorDeObjeto/montadorDeObjeto.h"
#include "../../Mecanicas/verificadorDeBitmapVazio/verificadorDeBitmapVazio.h"

int designBossFight(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue){

    bool finalizado = false;
    bool redesenhar = true;

    bool dialogInicial = true;

    char nomeArquivo[50];
    memset(nomeArquivo, 0, 50);
    //bzero(nomeArquivo, 50);

    char letra[5];
    //bzero(letra, 5);
    memset(letra, 0, 5);

    char pathArquivo[100];
    //bzero(pathArquivo, 100);
    memset(pathArquivo, 0, 100);
    strcpy(pathArquivo, "Auxiliar/ataques/");

/*
    float teste = 1.45;
    char teste2[20];
    bzero(teste2, 20);

    sprintf(teste2, "%.2f", teste);
    strcpy(nomeArquivo, teste2);
*/

    ALLEGRO_FONT* fonte = al_load_font("Auxiliar/FiraCode-Regular.ttf", 20, 0);

    Objeto* controlBar;
    Objeto* spriteButton;
    Objeto* movimentacaoButton;
    Objeto* turnoButton;
    Objeto* ataqueButton;
    Objeto* campoDeBatalha;
    Objeto* setaUp;
    Objeto* setaDown;

    Objeto* dialogInicialBase;
    Objeto* dialogInicialButton;

    controlBar = (Objeto*)malloc(sizeof(Objeto));
    spriteButton = (Objeto*)malloc(sizeof(Objeto));
    movimentacaoButton = (Objeto*)malloc(sizeof(Objeto));
    turnoButton = (Objeto*)malloc(sizeof(Objeto));
    ataqueButton = (Objeto*)malloc(sizeof(Objeto));
    campoDeBatalha = (Objeto*)malloc(sizeof(Objeto));
    setaUp = (Objeto*)malloc(sizeof(Objeto));
    setaDown = (Objeto*)malloc(sizeof(Objeto));

    dialogInicialBase = (Objeto*)malloc(sizeof(Objeto));
    dialogInicialButton = (Objeto*)malloc(sizeof(Objeto));

    montadorDeObjeto(controlBar, 80, 1280, 0, 0, "Auxiliar/sprites/designBossFight/controlBar.png");
    verificadorDeBitmapVazio(controlBar, controle, &finalizado);

    montadorDeObjeto(spriteButton, 60, 280, 40, 10, "Auxiliar/sprites/designBossFight/buttonSelecionar.png");
    verificadorDeBitmapVazio(spriteButton, controle, &finalizado);

    montadorDeObjeto(movimentacaoButton, 60, 361, 559, 10, "Auxiliar/sprites/designBossFight/buttonMov.png");
    verificadorDeBitmapVazio(movimentacaoButton, controle, &finalizado);

    montadorDeObjeto(turnoButton, 60, 280, 940, 10, "Auxiliar/sprites/designBossFight/buttonTurno.png");
    verificadorDeBitmapVazio(turnoButton, controle, &finalizado);

    montadorDeObjeto(ataqueButton, 60, 280, 958, 635, "Auxiliar/sprites/designBossFight/buttonAtaque.png");
    verificadorDeBitmapVazio(ataqueButton, controle, &finalizado);

    montadorDeObjeto(campoDeBatalha, 300, 400, 440, 280, "Auxiliar/sprites/campo_batalha.png");
    verificadorDeBitmapVazio(campoDeBatalha, controle, &finalizado);

    montadorDeObjeto(setaUp, 15, 30, 493, 19, "Auxiliar/sprites/designBossFight/setaUp.png");
    verificadorDeBitmapVazio(setaUp, controle, &finalizado);

    montadorDeObjeto(setaDown, 15, 30, 493, 47, "Auxiliar/sprites/designBossFight/setaDown.png");
    verificadorDeBitmapVazio(setaDown, controle, &finalizado);

    montadorDeObjeto(dialogInicialBase, 720, 1280, 0, 0, "Auxiliar/sprites/designBossFight/dialogTxT.png");
    verificadorDeBitmapVazio(dialogInicialBase, controle, &finalizado);

    montadorDeObjeto(dialogInicialButton, 70, 120, 784, 357, "Auxiliar/sprites/designBossFight/buttonPlay.png");
    verificadorDeBitmapVazio(dialogInicialButton, controle, &finalizado);


    while( !finalizado ) {

        while( !al_is_event_queue_empty( event_queue ) ) {
            ALLEGRO_EVENT evento;
            al_wait_for_event( event_queue, &evento );

            if ( evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
                controle->finalizado = true;
                finalizado = true;
            }

            if ( evento.type == ALLEGRO_EVENT_TIMER )
                redesenhar = true;

            if( dialogInicial ) {

                if ( evento.type == ALLEGRO_EVENT_KEY_CHAR ) {

                    if ( evento.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && strlen(nomeArquivo) >= 0 )
                        nomeArquivo[ strlen(nomeArquivo) - 1 ] = NULL;
                    
                    else {
                        int unichar = evento.keyboard.unichar;

                        letra[0] = (char)unichar;
                        strcat(nomeArquivo, letra);
                    }
                }

                if ( evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ) {

                    if ( verificadorDeClick(evento.mouse.x, evento.mouse.y, dialogInicialButton)) {
                        strcat(pathArquivo, nomeArquivo);
                        strcat(pathArquivo, ".txt");
                        
                        dialogInicial = false;
                    }
                }
            }
        }

        if ( redesenhar ) {

            al_draw_bitmap(controlBar->bitmap, controlBar->posicaoX, controlBar->posicaoY, 0);
            al_draw_bitmap(spriteButton->bitmap, spriteButton->posicaoX, spriteButton->posicaoY, 0);
            al_draw_bitmap(movimentacaoButton->bitmap, movimentacaoButton->posicaoX, movimentacaoButton->posicaoY, 0);
            al_draw_bitmap(turnoButton->bitmap, turnoButton->posicaoX, turnoButton->posicaoY, 0);
            al_draw_bitmap(ataqueButton->bitmap, ataqueButton->posicaoX, ataqueButton->posicaoY, 0);
            al_draw_bitmap(campoDeBatalha->bitmap, campoDeBatalha->posicaoX, campoDeBatalha->posicaoY, 0);
            al_draw_bitmap(setaUp->bitmap, setaUp->posicaoX, setaUp->posicaoY, 0);
            al_draw_bitmap(setaDown->bitmap, setaDown->posicaoX, setaDown->posicaoY, 0);
            
            al_draw_text(fonte, al_map_rgb(255, 255, 255), 422, 28, 0, "1.0");

            if ( dialogInicial ) {
                al_draw_bitmap(dialogInicialBase->bitmap, dialogInicialBase->posicaoX, dialogInicialBase->posicaoY, 0);
                al_draw_bitmap(dialogInicialButton->bitmap, dialogInicialButton->posicaoX, dialogInicialButton->posicaoY, 0);

                al_draw_text(fonte, al_map_rgb(0, 0, 0), 388, 379, 0, nomeArquivo);
            }

            al_flip_display();
            al_clear_to_color( al_map_rgb( 0, 0, 0 ) );
        }
    }

    al_destroy_bitmap(controlBar->bitmap);
    al_destroy_bitmap(spriteButton->bitmap);
    al_destroy_bitmap(movimentacaoButton->bitmap);
    al_destroy_bitmap(turnoButton->bitmap);
    al_destroy_bitmap(ataqueButton->bitmap);
    al_destroy_bitmap(campoDeBatalha->bitmap);
    al_destroy_bitmap(setaUp->bitmap);
    al_destroy_bitmap(setaDown->bitmap);

    al_destroy_bitmap(dialogInicialBase->bitmap);
    al_destroy_bitmap(dialogInicialButton->bitmap);

    free( controlBar );
    free( spriteButton );
    free( movimentacaoButton );
    free( turnoButton );
    free( ataqueButton );
    free( campoDeBatalha );
    free( setaUp );
    free( setaDown );

    free( dialogInicialBase );
    free( dialogInicialButton );

    return 0;
}

