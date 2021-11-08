// Copyright 2021 Dumistracel Eduard-Costin
#include "all.h"
void
add_shield_last(dll* list_shields, unsigned value)
{
    node *new_shield = malloc(sizeof(node));
    DIE(new_shield == NULL, "Error\n");
    new_shield->data = malloc(sizeof(unsigned));
    memcpy(new_shield->data, &value, sizeof(unsigned));
    node *tail = list_shields->head;
    while (tail->next != list_shields->head) {
        tail = tail->next;
    }
    tail->next = new_shield;
    new_shield->prev = tail;
    list_shields->head->prev = new_shield;
    new_shield->next = list_shields->head;
    ++list_shields->size;
}

void EXP(dll *list, char *index, char *value)
{
    unsigned index_p = atoi(index);
    unsigned value_s = atoi(value);
    // verific daca indexul exista
    if (index_p >= list->size) {
        printf("Planet out of bounds!\n");
        return;
    }
    node *node_p = list->head;
    // parcurg pana la planeta dorita
    for (unsigned i = 0; i < index_p; ++i) {
        node_p = node_p->next;
    }
    // adaug un scut
    add_shield_last(((planet*)node_p->data)->shields, value_s);
}
