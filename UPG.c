// Copyright 2021 Dumistracel Eduard-Costin
#include "all.h"

void upg(dll *list_planet, char *index_planet, char *index_shield, char *value)
{
    unsigned index_p = atoi(index_planet);
    unsigned index_s = atoi(index_shield);
    unsigned upgrade = atoi(value);
    if (index_p >= list_planet->size) {
        printf("Planet out of bounds!\n");
        return;
    }
    node *current = list_planet->head;
    for (unsigned i = 0; i < index_p; ++i) {
        current = current->next;
    }
    if (((planet*)current->data)->shields->size <= index_s) {
        printf("Shield out of bounds!\n");
        return;
    }
    node *current_s = ((planet*)current->data)->shields->head;
    for (unsigned i = 0; i < index_s; ++i) {
        current_s = current_s->next;
    }
    unsigned x = upgrade + *((unsigned *)current_s->data);
    memcpy(current_s->data, &x, sizeof(unsigned));
}
