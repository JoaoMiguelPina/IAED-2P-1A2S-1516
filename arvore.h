#ifndef ARVORE_H
#define ARVORE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
extern int Ntags;
extern int Ntotal;
extern Item maior;
#define sub(x,y) x-y


typedef struct node {
        Item item;
        struct node*l;
        struct node*r;
        int height;
        } *link;

        
void imprime_arvore(link h); 

link cria_link(Item g, link l, link r);

link insere_item(link h, Item x);

int height(link h);

link rotL(link h);

link rotR(link h);

link rotLR(link h);

link rotRL(link h);

int balance(link h);

link AVLbalance(link h);

void liberta(link h);
 
#endif
