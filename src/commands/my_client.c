/*
** EPITECH PROJECT, 2022
** my_client.c
** File description:
** connect user with pass
*/

#include "my_ftp.h"

void my_user(int i)
{
    CHECK_ARG(C_CMD[1]);
    if (C_ACC && !strcmp(C_CMD[1], C_ACC) && C_CNT) {
        dprintf(C_SOCKET, LOGIN);
        return;
    }
    C_CNT = false;
    DESTROY(C_ACC);
    C_ACC = strdup(C_CMD[1]);
    dprintf(C_SOCKET, ACC_OK);
}

void my_pass(int i)
{
    if (C_ACC && !strcmp(C_ACC, "Anonymous") && !C_CMD[1]) {
        dprintf(C_SOCKET, LOGIN);
        C_CNT = true;
        LOG("User %s connected successfully", C_ACC);
    } else if (!C_ACC) {
        dprintf(C_SOCKET, ACC_KO);
    } else {
        dprintf(C_SOCKET, LOG_IN);
    }
}
