/*
** EPITECH PROJECT, 2022
** my_file.c
** File description:
** file access
*/

#include "my_ftp.h"

void my_dele(int i)
{
    CHECK_LOG;
    chdir(C_PATH);
    CHECK_ARG(C_CMD[1]);
    if (access(C_CMD[1], W_OK) == 0 && remove(C_CMD[1]) == 0)
        dprintf(C_SOCKET, DELE, C_CMD[1]);
    else
        dprintf(C_SOCKET, FILE_ERROR, C_CMD[1]);
}
