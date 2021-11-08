// Copyright 2021 Dumistracel Eduard-Costin
#ifndef ALL_H_
#define ALL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

typedef struct node
{
    void *data;
    struct node *prev, *next;
} node;

typedef struct dll
{
    node *head;
    unsigned size;
} dll;

typedef struct planet
{
    int kills;
    char *name;
    dll* shields;
} planet;

void function_call(dll *list_planet);
dll *ll_create();
int count_orders();
void dll_add_planet(dll* list, char *name_planet, char *index, char *number);
void
dll_print_int_list(dll* list);
void print_shw(dll *list_planet, char *index);
void blh(dll* list_planet, unsigned index, int ok);
node* delete(dll *list, unsigned index);
void upg(dll *list_planet, char *index_planet, char *index_shield, char *value);
void EXP(dll *list, char *index, char *value);
void rmv(dll *list, char *index_planet, char *index_shield);
void rotate(dll *list_p, char *index_planet, char *direction, char *units);
void dll_print_int_list(dll* list);
void col(dll* list_planet, char *index_p1, char *index_p2);
#endif  // ALL_H_
