/*
** EPITECH PROJECT, 2022
** command.c
** File description:
** handle commands input
*/

#include "my_ftp.h"
#include "my_commands.h"

void handle_command(int i)
{
    int x = 0;

    if (!C_CMD || !C_CMD[0]) {
        dprintf(C_SOCKET, SYNTAX_ERROR);
        return;
    }
    for (; COMMANDS[x] && strcmp(COMMANDS[x], C_CMD[0]); x++);
    if (COMMANDS[x] && COMMANDS_FUNC[x])
        COMMANDS_FUNC[x](i);
    else if (COMMANDS[x])
        dprintf(C_SOCKET, NOT_IMPL, C_CMD[0]);
    else
        dprintf(C_SOCKET, SYNTAX_ERROR);
}
