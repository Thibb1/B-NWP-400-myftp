/*
** EPITECH PROJECT, 2022
** client.c
** File description:
** TODO
*/

#include "my_ftp.h"

void disconnect_client(int i)
{
    if (!C_SOCKET)
        return;
    dprintf(C_SOCKET, LOGOUT);
    FCLOSE(C_SOCKET);
    LOG("Connection closed %s:%d", inet_ntoa(S_ADDR.sin_addr), ntohs(S_PORT));
    FCLOSE(C_DATA);
    FCLOSE(C_DTSCT);
    C_DTSCT = 0;
    C_DATA = 0;
    C_SOCKET = 0;
    DESTROY(C_CMD);
    DESTROY(C_PATH);
    DESTROY(C_ACC);
    C_CNT = false;
    C_CMD = NULL;
    C_PATH = NULL;
    C_ACC = NULL;
}

void handle_client(int i)
{
    ssize_t read_ret;
    char buffer[1024];

    if (FD_ISSET(C_SOCKET, &SERVER->read_fds)) {
        if ((read_ret = read(C_SOCKET, buffer, 1024)) == 0) {
            disconnect_client(i);
        } else {
            buffer[read_ret] = 0;
            to_word_array(i, buffer);
            handle_command(i);
        }
    }
}

void connect_client(void)
{
    ASSERT((my_server()->new_socket = accept(S_SOCKET,
        (struct sockaddr *)&S_ADDR, &S_ADLEN)) < 0, "accept error");
    LOG("Connection from %s:%d", inet_ntoa(S_ADDR.sin_addr), ntohs(S_PORT));
    ASSERT(dprintf(my_server()->new_socket, SERVICE_READY) < 0, "message");
    LOG("Welcomed new connection");
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (C_SOCKET == 0) {
            C_SOCKET = my_server()->new_socket;
            C_CNT = false;
            C_PATH = strdup(my_server()->home_anon);
            return;
        }
    }
}
