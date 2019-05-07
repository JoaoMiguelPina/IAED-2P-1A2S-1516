#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "item.h"
#include "arvore.h"
#include "vetor.h"
#define NUMSEP 11
#define MAXCARACTERES 141


static link head;
static const char separators[] = {' ', '\t', ',' , ';', '.', '?', '!', '"', '\n', ':', '\0'};

void split(char *line);




int main() {
    int i, j;
    char mensagem[MAXCARACTERES], cmd;
    head = NULL;
    vetor = NULL;
    Ntags = 0;
    Ntotal= 0;
    maior = NULL;
    while (1) {
        fgets(mensagem, MAXCARACTERES, stdin);
        cmd = mensagem[0];
        switch(cmd) {
            case 'a':
                split(mensagem);
                break;
                
            case 's':
                printf("%d %d\n", Ntags, Ntotal);
                break;
                
            case 'm':
	            if(maior != NULL)
		            printf("#%s %d\n", maior->texto, maior->contador);
                break;
                
            case 'l':
                j = 0;
                vetor = malloc(sizeof(struct item)*Ntags);
                escolhe_node(head, &j);
                qsort(vetor,(size_t) Ntags,(size_t) sizeof(Item),qcompare);
                for (i=0; i<Ntags; i++) {
                    printf("#%s %d\n",vetor[i]->texto, vetor[i]->contador);
                }
                free(vetor);
                break;
            
            case 'x':
                liberta(head);
                return 0;
        }
        
    }
}

// split: divide uma string em varias palavras guardando-as no buffer
void split(char *line) {
    int i, j, k;
    char buffer[MAXCARACTERES];
    for(i = 0, k = 0; line[i] != '\0'; i++, k++) {
        buffer[k] = tolower(line[i]); 
        for(j = 0;j < NUMSEP; j++) {
            if (line[i] == separators[j]) {
                if(k != 0) {
                    buffer[k] = '\0';
                    if (buffer[0] == '#') {
                        head = insere_item(head, cria_item(buffer + 1)); 
			            Ntotal++;
                    }
                }
                k = -1;
            }
        }
    }
}          
