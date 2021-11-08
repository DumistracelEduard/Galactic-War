// Copyright 2021 Dumistracel Eduard-Costin
#include "all.h"

void rmv(dll *list, char *index_planet, char *index_shield)
{
    unsigned i;
    unsigned index_p = atoi(index_planet);
    unsigned index_s = atoi(index_shield);
    if (index_p >= list->size) {
        printf("Planet out of bounds!\n");
        return;
    }
    node *current_p = list->head;
    for (i = 0 ; i < index_p; ++i) {
        current_p = current_p->next;
    }
    if (index_s >= ((planet*)(current_p->data))->shields->size) {
        printf("Shield out of bounds!\n");
        return;
    }
    if (((planet*)(current_p->data))->shields->size <= 4) {
        printf("A planet cannot have less than 4 shields!\n");
        return;
    }
    node *shield = delete(((planet*)(current_p->data))->shields, index_s);
    free(shield->data);
    free(shield);
    --((planet*)(current_p->data))->shields->size;
}
