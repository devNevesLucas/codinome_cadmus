#include <stdio.h>
#include <stdlib.h>

const char* getSpriteProjetil( int codSprite ) {
    
    switch( codSprite ) {
        case 0: 
            return "Auxiliar/sprites/projeteis/bloco.png";
            
        case 1:
            return "Auxiliar/sprites/projeteis/blocoLaranja.png";

        case 2:
            return "Auxiliar/sprites/projeteis/blocoAzul.png";

        case 3: 
            return "Auxiliar/sprites/projeteis/blocoVermelho.png";
        
        case 4:
            return "Auxiliar/sprites/projeteis/blocoVerde.png";

        default:
            return "Auxiliar/sprites/projeteis/bloco.png";
    }
}