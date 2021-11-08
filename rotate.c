// Copyright 2021 Dumistracel Eduard-Costin
#include "all.h"

void rotate(dll *list_p, char *index_planet, char *direction, char *units)
{
    unsigned i, size, units_move;
    unsigned index_p = atoi(index_planet);
    if (index_p >= list_p->size) {
        printf("Planet out of bounds!\n");
        return;
    } else if (strcmp(direction, "c") != 0 && strcmp(direction, "t") != 0) {
        printf("Not a valid direction!\n");
        return;
    }
    node *current_p = list_p->head;
    for (i = 0; i < index_p; ++i) {
        current_p = current_p->next;
    }
    node *current_s = ((planet *)(current_p->data))->shields->head;
    size = ((planet *)(current_p->data))->shields->size;
    units_move = atoi(units) % size;
    for (i = 0; i < units_move; ++i) {
        if (strcmp(direction, "t") == 0) {
            ((planet *)(current_p->data))->shields->head = current_s->next;
        } else if (strcmp(direction, "c") == 0){
            ((planet *)(current_p->data))->shields->head = current_s->prev;
        }
        current_s = ((planet *)(current_p->data))->shields->head;
    }
}
