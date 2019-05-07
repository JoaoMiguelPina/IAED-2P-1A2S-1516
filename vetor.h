#ifndef _VETOR_
#define _VETOR_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "arvore.h"

Item *vetor;

int qcompare(const void* a, const void* b);

void escolhe_node(link h, int* i);


#endif
