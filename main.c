// Copyright 2021 Dumistracel Eduard-Costin
#include "all.h"

int main(void)
{
    unsigned number_orders, count = 0;
    dll *list_planet;
    number_orders = count_orders();
    list_planet = ll_create();
    while (count < number_orders){
        function_call(list_planet);
        ++count;
    }
    while (list_planet->size){
        blh(list_planet, 0, 0);
    }
    free(list_planet);
    return 0;
}
