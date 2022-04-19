/*
** EPITECH PROJECT, 2022
** display_cmd.c
** File description:
** commands that display data
*/

#include "my_ftp.h"
#include "my_commands.h"
#include "my_help.h"

void my_noop(int i)
{
    (void) COMMANDS_FUNC;
    dprintf(C_SOCKET, NOOP);
}

void my_help(int i)
{
    int y;

    if (!C_CMD[1]) {
        dprintf(C_SOCKET, HELP_LIST);
        return;
    }
    for (int x = 1; C_CMD[x]; x++) {
        y = 0;
        for (; COMMANDS[y] && strcmp(COMMANDS[y], C_CMD[x]); y++);
        if (COMMANDS_HELP[y])
            dprintf(C_SOCKET, HELP, COMMANDS_HELP[y]);
        else
            dprintf(C_SOCKET, COMMAND_ERROR);
    }
}

void my_pwd(int i)
{
    CHECK_LOG;
    CHECK_ARG(!C_CMD[1]);
    dprintf(C_SOCKET, "253 \"%s\"" CR, C_PATH);
}
