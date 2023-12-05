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

            //Ines
        case 5:
            return "Auxiliar/sprites/projeteis/ines/caveira.png";

        case 6:
            return "Auxiliar/sprites/projeteis/ines/ossogrande.png";

        case 7:
            return "Auxiliar/sprites/projeteis/ines/ossosimples.png";

            //Adamastor
        case 8:
            return "Auxiliar/sprites/projeteis/adamastor/onda.png";

        case 9:
            return "Auxiliar/sprites/projeteis/adamastor/punhoD.png";

        case 10:
            return "Auxiliar/sprites/projeteis/adamastor/punhoE.png";

        case 11:
            return "Auxiliar/sprites/projeteis/adamastor/raio.png";
            //Dionisio
        case 12:
            return "Auxiliar/sprites/projeteis/dionisio/barco.png";

        case 13:
            return "Auxiliar/sprites/projeteis/dionisio/bom.png";

        case 14:
            return "Auxiliar/sprites/projeteis/dionisio/mal.png";

        case 15:
            return "Auxiliar/sprites/projeteis/dionisio/poison.png";

        case 16:
            return "Auxiliar/sprites/projeteis/zcaixa.png";

        default:
            return "Auxiliar/sprites/projeteis/bloco.png";
    }
}