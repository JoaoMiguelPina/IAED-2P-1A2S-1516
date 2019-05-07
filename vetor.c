#include "vetor.h"


/*-------------------------------------------------------------------------------------------------------*/
/*--------------------------------------Funcoes-Auxiliares-do-Vetor--------------------------------------*/
/*-------------------------------------------------------------------------------------------------------*/


// qcompare: Auxiliar da sort() para comparar os elementos de um vetor
int qcompare(const void * a, const void * b) {
    int z;
    Item i = *(Item *) a;     //temos um ponteiro para void e queremos que passe a ser um ponteiro para item. //queremos o item
    Item j = *(Item *) b;
    
    z = sub(j->contador, i->contador);
    if (z != 0 ) 
        return z;
    return compare(i, j);    
}

//escolhe_node: copia uma arvore para um vetor
void escolhe_node(link h, int* i) { 

    if (h == NULL) return;
    escolhe_node(h->l, i);
    vetor[*i] = h->item;
    ++(*i);
    escolhe_node(h->r, i);   
}
