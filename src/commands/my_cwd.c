/*
** EPITECH PROJECT, 2022
** my_cwd.c
** File description:
** change working dir
*/

#include "my_ftp.h"

void my_cwd(int i)
{
    char actual_path[PATH_MAX];

    CHECK_LOG;
    CHECK_ARG(C_CMD[1]);
    chdir(C_PATH);
    if (dir_ok(C_CMD[1])) {
        realpath(C_CMD[1], actual_path);
        free(C_PATH);
        C_PATH = strdup(actual_path);
        dprintf(C_SOCKET, DIR_CHANGED, C_PATH);
    } else {
        dprintf(C_SOCKET, FOLDER_ERROR, C_CMD[1]);
    }
}

void my_cdup(int i)
{
    char actual_path[PATH_MAX];

    CHECK_LOG;
    chdir(C_PATH);
    if (dir_ok("..")) {
        realpath("..", actual_path);
        free(C_PATH);
        C_PATH = strdup(actual_path);
        dprintf(C_SOCKET, DIR_CHANGED, C_PATH);
    } else {
        dprintf(C_SOCKET, FOLDER_ERROR, "Can't go up");
    }
}
