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

char *replace(char *str, char from, char to)
{
    char *ptr = str;

    while ((ptr = strchr(ptr, from)) != NULL)
        *ptr++ = to;
    return str;
}

uint16_t get_port(int socket)
{
    struct sockaddr_in sin;
    socklen_t len = sizeof(sin);

    if (getsockname(socket, (struct sockaddr *)&sin, &len) != -1)
        return ntohs(sin.sin_port);
    return 0;
}

void read_output(FILE *f, int i, bool replace)
{
    int ch;

    while ((ch = fgetc(f)) != EOF) {
        if (ch == '\n' && replace)
            dprintf(C_DTSCT, CR);
        else
            dprintf(C_DTSCT, "%c", ch);
    }
}
