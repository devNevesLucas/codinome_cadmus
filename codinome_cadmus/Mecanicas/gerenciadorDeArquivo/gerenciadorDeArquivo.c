#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "../../Structs/objeto.h"
#include "../../Structs/projetil.h"
#include "../../Mecanicas/montadorDeObjeto/montadorDeObjeto.h"
#include "../../Mecanicas/verificadorDeBitmapVazio/verificadorDeBitmapVazio.h"
#include "../../Mecanicas/getSpriteProjetil/getSpriteProjetil.h"


void gravaProjetil(FILE* arquivo, Projetil* projetil) {
    char linha[100];
    memset(linha, 0, 100);

    char dado[10];
    memset(dado, 0, 10);

    sprintf(dado, "%04.0f ", projetil->xInicial);
    strcat(linha, dado);

    sprintf(dado, "%04.0f ", projetil->yInicial);
    strcat(linha, dado);

    sprintf(dado, "%04d ", projetil->objeto->altura);
    strcat(linha, dado);

    sprintf(dado, "%04d ", projetil->objeto->largura);
    strcat(linha, dado);

    sprintf(dado, "%04d ", projetil->codSprite);
    strcat(linha, dado);

    sprintf(dado, "%04d ", projetil->codMov);
    strcat(linha, dado);

    sprintf(dado, "%04d ", projetil->dano);
    strcat(linha, dado);
    
    sprintf(dado, "%04.1f ", projetil->velocidade);
    strcat(linha, dado);

    sprintf(dado, "%04.0f ", projetil->xFinal);
    strcat(linha, dado);

    sprintf(dado, "%04.0f ", projetil->yFinal);
    strcat(linha, dado);

    strcat(linha, "\n");

    fprintf(arquivo, linha);
}

int contadorDeTurnos(char* caminho) {

    int contador = 0;

    char linha[60];

    FILE* arquivo;
    arquivo = fopen(caminho, "r");

    if ( arquivo == NULL )
        fprintf(stderr, "Erro ao abrir arquivo!\n");

    while ( fgets(linha, sizeof(linha), arquivo) ) 
        if ( strcmp(linha, "\n") == 0 || strcmp(linha, "") == 0 )
            contador++;
    
    fclose( arquivo );

    return contador;
}

int contadorDeAtaques(char* caminho, int turno) {
    
    int contador = 0;
    int turnoLeitura = 0;

    char linha[60];

    FILE* arquivo;
    arquivo = fopen(caminho, "r");

    if ( arquivo == NULL )
        fprintf(stderr, "Erro ao abrir arquivo!\n");

    while( fgets(linha, sizeof(linha), arquivo) ) {

        if ( strcmp(linha, "\n") == 0 || strcmp(linha, "") == 0 )
            turnoLeitura++;

        if ( turnoLeitura == turno - 1) 
            contador++;
    }

    fclose( arquivo );

    return contador;
}

void montadorDeProjetil( Projetil *projeteis[], char* caminho, int turno ) {

    int tamanho = contadorDeAtaques(caminho, turno);
    float dados[10];

    int contadorTurno = 0;
    int index = 0;

    char linha[100];
    char* resultado;
    
    FILE *arquivo;
    arquivo = fopen(caminho, "r");

    if ( arquivo == NULL ) 
            fprintf(stderr, "Erro ao abrir arquivo!");

    while( fgets(linha, 100, arquivo )) {

        if ( strcmp(linha, "\n") == 0 || strcmp(linha, "") == 0 )
            contadorTurno++;

        if ( contadorTurno == turno - 1 ) {

            int iteradorLinha = 0;

            for( int j = 0; j < 10; j++ ) {
                char substring[5];

                strncpy(substring, linha + iteradorLinha, 5);
                substring[4] = '\0';

                dados[ j ] = atof( substring );
                iteradorLinha += 5;
            }

            projeteis[ index ] = (Projetil*)malloc(sizeof(Projetil));
            projeteis[ index ]->objeto = (Objeto*)malloc(sizeof(Objeto));
            projeteis[ index ]->objeto->posicaoX = dados[ 0 ];
            projeteis[ index ]->objeto->posicaoY = dados[ 1 ];
            projeteis[ index ]->objeto->altura = dados[ 2 ];
            projeteis[ index ]->objeto->largura = dados[ 3 ];
            projeteis[ index ]->objeto->bitmap = al_load_bitmap(getSpriteProjetil((int)dados[ 4 ]));
            projeteis[ index ]->ativado = true;
            projeteis[ index ]->codMov = (int)dados[ 5 ];
            projeteis[ index ]->codSprite = (int)dados[ 4 ];
            projeteis[ index ]->dano = (int)dados[ 6 ];
            projeteis[ index ]->acumulador = 1;
            projeteis[ index ]->operador = 1;
            projeteis[ index ]->velocidade = dados[ 7 ];
            projeteis[ index ]->xInicial = dados[ 0 ];
            projeteis[ index ]->yInicial = dados[ 1 ];
            projeteis[ index ]->xFinal = dados[ 8 ];
            projeteis[ index ]->yFinal = dados[ 9 ];

            if ( !projeteis[ index ]->objeto->bitmap ) {
                fprintf(stderr, "Erro ao abrir a imagem do projétil %d!\n", index);
            }
            index++;
        }
    }
    fclose( arquivo );
}