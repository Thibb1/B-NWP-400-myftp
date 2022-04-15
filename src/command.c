/*
** EPITECH PROJECT, 2022
** command.c
** File description:
** TODO
*/

#include "my_ftp.h"

void command_cmp(int i, char *cmd, char *arg)
{
    if (!strcmp(cmd, "NOOP")) {
        dprintf(C_SOCKET, NOOP);
        return;
    }
    if (!strcmp(cmd, "HELP")) {
        CHECK_ARG(arg);
        dprintf(C_SOCKET, HELP);
        return;
    }
}

void handle_command(int i, char *cmd, char *arg)
{
    LOG("%s:%s", cmd, arg);
    if (cmd == NULL || !strcmp(cmd, "QUIT")) {
        disconnect_client(i);
        return;
    }
    command_cmp(i, cmd, arg);
}
