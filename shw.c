// Copyright 2021 Dumistracel Eduard-Costin
#include "all.h"

void print_shw(dll *list_planet, char *index) {
    if (list_planet->size == 0) {
        printf("Planet out of bounds!\n");
        return;
    }
    unsigned count = atoi(index);
    if (count > list_planet->size - 1) {
        printf("Planet out of bounds!\n");
        return;
    }
    unsigned i;
    node *head = list_planet->head;
    for (i = 0; i < count; ++i) {
        head = head->next;
    }
    printf("NAME: %s\n", ((planet *)head->data)->name);
    if (list_planet->size == 1) {
        printf("CLOSEST: none\n");
    } else if (list_planet->size == 2){
        printf("CLOSEST: %s\n", ((planet *)head->next->data)->name);
    } else {
        printf("CLOSEST: %s and ", ((planet *)head->prev->data)->name);
        printf("%s\n", ((planet *)head->next->data)->name);
    }
    node *current = ((planet *)(head->data))->shields->head;
    printf("SHIELDS: ");
    unsigned number_shields = ((planet *)(head->data))->shields->size;
    for (i = 0; i < number_shields; ++i) {
        printf("%d ", *((int*)current->data));
        current = current->next;
    }
    printf("\n");
    printf("KILLED: %d\n", ((planet *)(head->data))->kills);
}
