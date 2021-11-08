// Copyright 2021 Dumistracel Eduard-Costin
#include "all.h"

void col(dll* list_planet, char *index_p1, char *index_p2)
{
    unsigned index1 = atoi(index_p1);
    unsigned index2 = atoi(index_p2);
    unsigned i;
    if (index1 >= list_planet->size || index2 >= list_planet->size) {
        printf("Planet out of bounds!\n");
        return;
    }
    node *planet1 = list_planet->head;
    for (i = 0; i < index1; ++i) {
        planet1 = planet1->next;
    }
    node *planet2 = planet1->next;
    unsigned index_s1 = ((planet *)planet1->data)->shields->size / 4;
    unsigned index_s2 = (((planet *)planet2->data)->shields->size / 4) * 3;
    node *shield1 = ((planet *)planet1->data)->shields->head;
    node *shield2 = ((planet *)planet2->data)->shields->head;
    for (i = 0; i < index_s1; ++i) {
        shield1 = shield1->next;
    }
    for (i = 0; i < index_s2; ++i) {
        shield2 = shield2->next;
    }
    int value1 = *((int *)shield1->data) - 1;
    memcpy(shield1->data, &value1, sizeof(int));
    int value2 = *((int *)shield2->data) - 1;
    memcpy(shield2->data, &value2, sizeof(int));
    if (*((int *)shield1->data) == -1 && *((int *)shield2->data) != -1) {
        printf("The planet %s has imploded.\n", ((planet*)planet1->data)->name);
        ((planet*)planet2->data)->kills++;
        blh(list_planet, index1, 0);
    } else if (*((int *)shield2->data) == -1 && *((int *)shield1->data) != -1) {
        printf("The planet %s has imploded.\n", ((planet*)planet2->data)->name);
        ((planet*)planet1->data)->kills++;
        blh(list_planet, index2, 0);
    } else if (*((int *)shield2->data) == -1 && *((int *)shield1->data) == -1) {
        printf("The planet %s has imploded.\n", ((planet*)planet1->data)->name);
        printf("The planet %s has imploded.\n", ((planet*)planet2->data)->name);
        blh(list_planet, index1, 0);
        blh(list_planet, index2 - 1, 0);
    }
}
