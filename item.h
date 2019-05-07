#ifndef ITEM_H 
#define ITEM_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCARACTERES 141
#define compare(x,y) strcmp(x->texto,y->texto) 


typedef struct item {
        char *texto;
        int contador;
        } *Item;


Item cria_item(char * palavra);

#endif
