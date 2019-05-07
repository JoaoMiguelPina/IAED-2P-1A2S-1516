#include "item.h"
#include <string.h>


/*-------------------------------------------------------------------------------------------------------*/
/*--------------------------------------Funcoes-Auxiliares-do-Item---------------------------------------*/
/*-------------------------------------------------------------------------------------------------------*/


//cria_item: Cria um novo item com a palavra que recebe
Item cria_item(char *palavra) {
    int len = strlen(palavra) + 1;
    Item x = malloc(sizeof(struct item));
    x->texto = malloc(sizeof(char) * len);
    strcpy(x->texto, palavra); 
    x -> contador = 1;
    return x;
}
