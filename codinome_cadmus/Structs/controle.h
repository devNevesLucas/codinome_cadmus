#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#ifndef Controle_H
#define Controle_H

typedef struct Controle {

        int codFase;
        bool finalizado;

        //Variavel para verificar se um boss foi derrotado
        bool InesDeCastro;
        bool adamastor;
        bool dionisio;
        
} Controle;

#endif


/*
    Definindo a Struct de Controle, usada para passar fases e dizer se o jogo ainda está funcionando ou não

    Contém: codFase, código da fase em que o jogo deve rodar atualmente, sendo utilizado principalmente no gerenciadorDeFases
    e um finalizado, caso seja falso, o jogo continua funcionando
*/