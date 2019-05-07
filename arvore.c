#include "arvore.h"
int Ntags;
int Ntotal;
Item maior;


/*-------------------------------------------------------------------------------------------------------*/
/*-------------------------------------Funcoes-Auxiliares-das-Arvores------------------------------------*/
/*-------------------------------------------------------------------------------------------------------*/


//cria_link: cria um novo link da arvore com o Item que recebe
link cria_link(Item g, link l, link r) {
    link x = malloc(sizeof(struct node));
    x-> item = g;
    x-> l = l;
    x-> r = r;
    x->height = 1;
    return x;
}

//insere_item: insere um item na arvore ou incrementa o seu contador se ja la estiver
link insere_item(link h, Item x) {
    int z;
    if (h == NULL) {
	    if(Ntags == 0)
		    maior = x;
	    else if(maior->contador == 1)
		    if(compare(x, maior) < 0)
			    maior = x;
	    Ntags++;
            return cria_link(x, NULL, NULL);
   }
        
    z = compare(x, h->item);
    
    if (z == 0) {
	    z = sub(++h->item->contador, maior->contador);         
	    if(z > 0 || (z == 0 && compare(x, maior) < 0))
		    maior = h->item;
		    free(x->texto);
            free(x); 
    }    
    else if (z < 0)
        h->l = insere_item(h->l, x);
    
    else
        h->r = insere_item(h->r, x);
    
    h = AVLbalance(h); 
 
    return h; 
        
}

// liberta: liberta a memoria alocada para a arvore
void liberta(link h) {
    if(h != NULL) {
        liberta(h->l);
        free(h->item->texto);
        free(h->item);
        liberta(h->r);
        free(h);
    }
}


/*-------------------------------------------------------------------------------------------------------*/
/*-------------------------------------Funcoes-Auxiliares-das-Arvores------------------------------------*/
/*-------------------------------------------------AVL---------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------*/

//height: devolve a profundidade do node que recebe
int height(link h) {
    if (h == NULL) 
        return 0;
    return h->height;
}

//rotL: rotacao da arvore para a esquerda de modo a balancea-la
link rotL(link h) {
    int height_left, height_right;
    link x = h->r;
    h->r = x->l;
    x->l = h;

    height_left = height(h->l);
    height_right = height(h->r);
    h->height = height_left > height_right ? height_left + 1 : height_right + 1;

    height_left = height(h->l);
    height_right = height(x->r);
    x->height = height_left > height_right ? height_left + 1 : height_right + 1;

    return x;
}

//rotR: rotacao da arvore para a direita de modo a balancea-la
link rotR(link h) {
    int height_left, height_right;
    link x = h->l;
    h->l = x->r;
    x->r = h;

    height_left = height(h->l);
    height_right = height(h->r);
    h->height = height_left > height_right ? height_left + 1 : height_right + 1;

    height_left = height(x->l);
    height_right = height(h->r);
    x->height = height_left > height_right ? height_left + 1 : height_right + 1;

    return x; 
}

//rotLR: rotacao dupla esquerda direita
link rotLR(link h) { 
    if (h==NULL) 
        return h;
    h->l=rotL(h->l);
    return rotR(h); 
}

//rotLR: rotacao dupla direita esquerda
link rotRL(link h) { 
    if (h==NULL) 
        return h;
    h->r=rotR(h->r); 
    return rotL(h); 
}


//balance: devolve a diferenca entre a profundidade dos ramos
int balance(link h) { 
    if (h == NULL) 
        return 0; 
    return sub(height(h->l),height(h->r)); 
} 

//AVLbalance: aplica as auxiliares de modo a balancear a arvore de modo a que nao seja degenerada
link AVLbalance(link h) {    
    int balanceFactor, height_left, height_right;

    if (h==NULL) 
        return h;

    balanceFactor = balance(h); 

    if (balanceFactor > 1) {            
        if (balance(h->l) > 0) 
            h = rotR(h); //se o novo elemento e introduzido na sub arvore da esquerda da sub arvore da esquerda
        else 
            h = rotLR(h); //se o novo elemento e introduzido na sub arovre da direita da sub arvore da esquerda
    }
   
    else if (balanceFactor < -1) { 
        if (balance(h->r) < 0) 
            h = rotL(h); //se o novo elemento e introduzido na sub arvore direita da sub arvore da direita
        else  
            h = rotRL(h); //se o novo elemento e introduzido na sub arvore da esquerda da sub arvore da direita 
    } 
    else {
        height_left = height(h->l);
        height_right = height(h->r);
        h->height = height_left > height_right ?  height_left + 1 : height_right + 1;
    }

  return h; 
}  
