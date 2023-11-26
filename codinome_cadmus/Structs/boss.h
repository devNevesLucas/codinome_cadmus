#include <stdio.h>
#include <stdlib.h>

#ifndef Boss_H
#define Boss_H

typedef struct Boss {

    int HPinicial;
    int HP;
    char nome[60];
    char pathBackground[100];
    char pathAtaques[100];
    int codDialogs[4];

} Boss;

#endif