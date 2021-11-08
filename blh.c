// Copyright 2021 Dumistracel Eduard-Costin
#include "all.h"

node* delete(dll *list, unsigned index)
{
    unsigned i;
    node *delete = NULL;
    node *current = list->head;
    if (index == 0) {
        while (current->next != list->head) {
            current = current->next;
        }
        delete = list->head;
        list->head = delete->next;
        list->head->prev = current;
        current->next = list->head;
    } else {
        node *next_node;
        for (i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        next_node = current->next->next;
        delete = current->next;
        next_node->prev = current;
        current->next = next_node;
    }
    return delete;
}

void blh(dll* list_planet, unsigned index, int ok)
{
    unsigned i;
    if (index >= list_planet->size) {
        printf("Planet out of bounds!\n");
        return;
    } else {
        node *delete_planet = delete(list_planet, index);
        unsigned number_shields;
        number_shields = ((planet *)(delete_planet->data))->shields->size;
        for (i = 0; i < number_shields; ++i) {
            node *shield = delete(((planet*)delete_planet->data)->shields, 0);
            free(shield->data);
            free(shield);
        }
        free(((planet*)delete_planet->data)->shields);
        if (ok != 0) {
            printf("The planet %s ", ((planet*)(delete_planet->data))->name);
            printf("has been eaten by the vortex.\n");
        }
        free(((planet*)(delete_planet->data))->name);
        free(delete_planet->data);
        free(delete_planet);
        --list_planet->size;
    }
}
