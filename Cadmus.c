#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "Telas/gerenciadorDeFases/gerenciadorDeFases.h"
#include "Structs/controle.h"

// Nossa conhecida função main...
int main(void)
{
    int screen_w = 1280;
    int screen_h = 720;
    int FPS = 25;

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;

    al_init();
    al_init_font_addon();
    al_init_ttf_addon(); 
    al_init_image_addon();

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);


    display = al_create_display(screen_w, screen_h);
    event_queue = al_create_event_queue();

    if ( !display ) {
        fprintf(stderr, "erro ao iniciar o display!");
        return -1;
    }

    if ( !event_queue ) {
        fprintf(stderr, "erro ao iniciar a fila de eventos!");
        return -1;
    }

    Controle ctrl;
    ctrl.codFase = 0;
    ctrl.finalizado = false;

    al_init_primitives_addon();
    al_install_keyboard();
    al_install_mouse();

    al_register_event_source( event_queue, al_get_display_event_source( display ));
    al_register_event_source( event_queue, al_get_mouse_event_source());
    al_register_event_source( event_queue, al_get_timer_event_source( timer ));

    al_start_timer( timer );

    Controle* controle = &ctrl;

    while ( !controle->finalizado ) {
        gerenciadorDeFases( controle, display, event_queue ); 
    }
    
    al_destroy_event_queue( event_queue );
    al_uninstall_keyboard();
    al_uninstall_mouse();
    al_shutdown_font_addon();
    al_shutdown_image_addon();
    al_destroy_display( display );

    return 0;
}