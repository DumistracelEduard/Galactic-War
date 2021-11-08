// Copyright 2021 Dumistracel Eduard-Costin
#include "all.h"

#define size_line 30

int
count_orders()
{
    char *line = malloc(size_line);
    DIE(line == NULL, "error\n");
    fgets(line, 30, stdin);
    int value = atoi(line);
    free(line);
    return value;
}

void
which_function(char *command, char *value1, char *value2,
                char *value3, dll *list_planet)
{
    if (strcmp(command, "ADD") == 0){
        dll_add_planet(list_planet, value1, value2, value3);
    } else if (strcmp(command, "BLH") == 0) {
        blh(list_planet, atoi(value1), 1);
    } else if (strcmp(command, "UPG") == 0) {
        upg(list_planet, value1, value2, value3);
    } else if (strcmp(command, "EXP") == 0) {
        EXP(list_planet, value1, value2);
    } else if (strcmp(command, "RMV") == 0) {
        rmv(list_planet, value1, value2);
    } else if (strcmp(command, "COL") == 0) {
        col(list_planet, value1, value2);
    } else if (strcmp(command, "ROT") == 0) {
        rotate(list_planet, value1, value2, value3);
    } else if (strcmp(command, "SHW") == 0) {
        print_shw(list_planet, value1);
    }
}
void
function_call(dll *list_planet)
{
    int i = 0;
    char mat[4][21];
    char *line = malloc(size_line);
    DIE(line == NULL, "error\n");
    fgets(line, 30, stdin);
    const char s[4] = "  \n";
	char *token;
	token = strtok(line, s);
	while (token != 0) {
		strcpy(mat[i], token);
		token = strtok(0, s);
        i++;
	}
    which_function(mat[0], mat[1], mat[2], mat[3], list_planet);
    free(line);
}
