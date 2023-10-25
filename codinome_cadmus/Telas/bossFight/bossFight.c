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
#include "../../Mecanicas/montadorDeObjeto/montadorDeObjeto.h"


int bossFight(Controle* controle, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {

    //Declarando as dimensões da tela
    int ALTURA_TELA = 720;
    int LARGURA_TELA = 1280;

    //Definindo a variável "finalizado", que controla o fechamento desta página em específico
    bool finalizado = false;

    //Definindo um objeto entitulado "AtaqueTeste", feito num primeiro momento para testar se funcionava ou não a função
    Objeto* AtaqueTeste;
    //Alocando a memória necessária para ele
    AtaqueTeste = (Objeto*)malloc(sizeof(Objeto));


    //Enviando ele para o montadorDeObjetos, uma função que criei para poupar linhas na aplicação; Ao abrir a função talvez fique mais claro...
    montadorDeObjeto(AtaqueTeste, 50, 50, ALTURA_TELA / 2, LARGURA_TELA / 2, "Auxiliar/sprites/bloco.png");
    
    //Verifica se o AtaqueTeste recebeu sua devida imagem, caso não ocorra, encerra o programa
    if ( !AtaqueTeste->bitmap ) {
        fprintf(stderr, "Erro ao carregar bitmap do AtaqueTeste -> bossFight.c\n");
        finalizado = true;
        controle->finalizado = true;
    }

    //Definindo variável "campoDeBatalha", que é o campo que o player poderá se mover
    Objeto* campoDeBatalha;

    //Alocando a memória necessária para ela
    campoDeBatalha = (Objeto*)malloc(sizeof(Objeto));

    //Enviando ele para o montadorDeObjetos, uma função que criei para poupar linhas na aplicação; Ao abrir a função talvez fique mais claro...
    montadorDeObjeto(campoDeBatalha, 300, 400, 440, 300, "Auxiliar/sprites/campo_batalha.png");

    //Verifica se o campoDeBatalha recebeu sua devida imagem, caso não ocorra, encerra o programa
    if ( !campoDeBatalha->bitmap ) {
        fprintf(stderr, "Erro ao carregar bitmap do campoDeBatalha -> bossFight.c\n");
        finalizado = true;
        controle->finalizado = true;
    }
  
    //Enquanto o programa não for finalizado de alguma forma, execute isso
    while ( !finalizado ) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(event_queue, &evento);

        //Verifica se o botão de fechar foi clicado
        if ( evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
            controle->finalizado = true;
            finalizado = true;
        }

        //Desenha na tela o campo de batalha e o teste de ataque
        al_draw_bitmap(campoDeBatalha->bitmap, campoDeBatalha->posicaoX, campoDeBatalha->posicaoY, 0);
        al_draw_bitmap(AtaqueTeste->bitmap, AtaqueTeste->posicaoX, AtaqueTeste->posicaoY, 0);

        //Realiza o flip do display, que limpa a tela e cria os novos bitmaps, igual a como acontecia no P5.js...
        al_flip_display();

        al_clear_to_color(al_map_rgb(0, 0, 0));
    }

    //Libera a memória do AtaqueTeste e campoDeBatalha
    free(AtaqueTeste);
    free(campoDeBatalha);


    //Retorna 0 
    return 0;
}