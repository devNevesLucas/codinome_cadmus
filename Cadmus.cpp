// Testes.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <allegro5/allegro.h>
//Coloca as fontes
#include <allegro5/allegro_font.h>
//True type font
#include <allegro5/allegro_ttf.h>
//Formas primitivas
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

//Adicionando arquivo criado
#include "menu.h"

// Nossa conhecida função main...
int main(void)
{
    //Variáveis com o width e height para melhor edição 
    int screen_w = 1280;
    int screen_h = 720;
    bool fim = false;

    int fasesIterator = 0;
/*
    int pos_x = screen_w / 2;
    int pos_y = screen_h / 2;

*/
    int FPS = 25;

// Variável representando a janela principal e fila de eventos dentre outras
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;

    ALLEGRO_TIMER* timer = NULL;

    // Inicializamos as bibliotecas
    al_init();

    // Criamos a nossa janela - dimensões de 640x480 px
    display = al_create_display(screen_w, screen_h);
    event_queue = al_create_event_queue();

    al_init_font_addon();
    al_init_ttf_addon();

    //A fonte em si
    ALLEGRO_FONT* fontT = al_load_font("Auxiliar/AncientModern.ttf", 100, 0);
    ALLEGRO_FONT* fontM = al_load_font("Auxiliar/AncientModern.ttf", 50, 0);

    timer = al_create_timer(1.0 / FPS);
    
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_mouse();

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    //al_hide_mouse_cursor(display);

    while (!fim) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            fim = true;
        }
        /*
        else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {

            pos_x = ev.mouse.x;
            pos_y = ev.mouse.y;
        }

        if( ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            bossFight(display, event_queue);
        }
        */

        switch (fasesIterator) {
            case 0:
                menu(display, event_queue);
                return;
            
            default:
                break;
        }

        //Coloca o texto na tela  
    }

    // Finaliza a janela
    al_destroy_display(display);

    return 0;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
