// Copyright 2021 Dumistracel Eduard-Costin
#include "all.h"

dll *ll_create()
{
    dll* list;
    list = malloc(sizeof(dll));
    DIE(list == NULL, "list malloc failed");
    list->size = 0;
    return list;
}

void
add_shields(dll* list_shields)
{
    unsigned int x = 1;
    node *new_shield = malloc(sizeof(node));
    DIE(new_shield == NULL, "Error\n");
    new_shield->data = malloc(sizeof(unsigned));
    memcpy(new_shield->data, &x, sizeof(unsigned));
    if (list_shields->size == 0) {
        list_shields->head = new_shield;
        new_shield->next = new_shield->prev = new_shield;
        ++list_shields->size;
    } else {
        node *tail = list_shields->head;
        while (tail->next != list_shields->head) {
            tail = tail->next;
        }
        tail->next = new_shield;
        new_shield->prev = tail;
        list_shields->head->prev = new_shield;
        new_shield->next = list_shields->head;
        list_shields->head = new_shield;
        ++list_shields->size;
    }
}

void dll_add_planet(dll* list, char *name_planet, char *index, char *number)
{
    unsigned int index_planet = atoi(index);
    if (list->size < index_planet) {
        printf("Planet out of bounds!\n");
        return;
    }
    unsigned int i, number_shields = atoi(number);
    int size = strlen(name_planet)+1;
    node* new_planet = malloc(sizeof(node));
    DIE(new_planet == NULL, "Error\n");
    new_planet->data = malloc(sizeof(planet));
    ((planet *)(new_planet->data))->name = malloc(size);
    DIE(((planet *)(new_planet->data))->name == NULL, "Error\n");
    memcpy(((planet *)(new_planet->data))->name, name_planet, size);
    ((planet *)(new_planet->data))->kills = 0;
    ((planet *)(new_planet->data))->shields = ll_create();
    for (i = 0; i < number_shields; ++i) {
        add_shields(((planet *)(new_planet->data))->shields);
    }
    printf("The planet %s has joined the galaxy.\n", name_planet);
    if (index_planet == 0){
        if (list->size == 0){
            list->head = new_planet;
            new_planet->next = new_planet;
            new_planet->prev = new_planet;
        } else {
            node* tail = list->head;
            while (tail->next != list->head) {
                tail = tail->next;
            }
            tail->next = new_planet;
            new_planet->prev = tail;
            list->head->prev = new_planet;
            new_planet->next = list->head;
            list->head = new_planet;
        }
    } else {
        node* node_before = list->head;
        node* node_after;
        for (i = 0; i < index_planet - 1; ++i) {
            node_before = node_before->next;
        }
        node_after = node_before->next;
        node_before->next = new_planet;
        new_planet->prev = node_before;
        node_after->prev = new_planet;
        new_planet->next = node_after;
    }
    ++list->size;
}
