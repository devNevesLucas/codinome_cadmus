#include <stdio.h>
#include <stdlib.h>

const char* getSpriteTexto( int codSprite ) {
    
    switch( codSprite ) {
        case 0: 
            return "Auxiliar/caixasDeTexto/portugal1.png";
            
        case 1:
            return "Auxiliar/caixasDeTexto/portugal2.png";

        case 2:
            return "Auxiliar/caixasDeTexto/caboVerde1.png";

        case 3: 
            return "Auxiliar/caixasDeTexto/caboVerde2.png";
        
        case 4:
            return "Auxiliar/caixasDeTexto/caboDasTormentas1.png";

        case 5:
            return "Auxiliar/caixasDeTexto/caboDasTormentas2.png";

        case 6:
            return "Auxiliar/caixasDeTexto/mocambique.png";

        case 7:
            return "Auxiliar/caixasDeTexto/melinde.png";

        case 8:
            return "Auxiliar/caixasDeTexto/melinde.png";

        case 9:
            return "Auxiliar/caixasDeTexto/goa1.png";

        case 10:
            return "Auxiliar/caixasDeTexto/goa2.png";

        default:
            return "Auxiliar/caixasDeTexto/portugal1.png";
    }
}