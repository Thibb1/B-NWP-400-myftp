/*
** EPITECH PROJECT, 2022
** my_list.c
** File description:
** list
*/

#include "my_ftp.h"

void list_to_data(int i)
{
    char *str = commands_with_args("ls -l", i);
    FILE *f = popen(str, "r");

    LOG("Executing: %s", str);
    DESTROY(str);
    if (!f) {
        dprintf(C_SOCKET, FILE_ERR);
        return;
    }
    read_output(f, i, true);
    pclose(f);
}

void my_list(int i)
{
    CHECK_LOG;
    CHECK_SOCKET;
    open_socket(i);
    if (fork() == 0) {
        list_to_data(i);
        garbage_delete();
        exit(0);
    }
    close_socket(i);
}
