/*
** EPITECH PROJECT, 2022
** string_util.c
** File description:
** string utilities
*/

#include "my_ftp.h"

int len_array(char *buff)
{
    char *cpy = calloc(strlen(buff) + 1, sizeof(char));
    int len = 0;
    char *left;

    strcpy(cpy, buff);
    left = cpy;
    while (strtok_r(left, DELIM, &left) && ++len);
    DESTROY(cpy);
    return len;
}

void to_word_array(int i, char *buff)
{
    int len = len_array(buff);
    char *ptr = NULL;
    int x = 0;

    DESTROY(C_CMD);
    C_CMD = calloc(len + 1, sizeof(char *));
    while ((ptr = strtok_r(buff, DELIM, &buff)))
        C_CMD[x++] = ptr;
}
