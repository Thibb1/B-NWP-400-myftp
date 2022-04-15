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
    LOG("Connection closed %s:%d", inet_ntoa(S_ADDR.sin_addr), ntohs(S_PORT));
    close(C_SOCKET);
    C_SOCKET = 0;
}

void handle_client(int i)
{
    ssize_t read_ret;
    char buffer[1024];
    char *cmd = NULL;
    char *arg = NULL;

    if (FD_ISSET(C_SOCKET, &my_server()->read_fds)) {
        if ((read_ret = read(C_SOCKET, buffer, 1024)) == 0) {
            disconnect_client(i);
        } else {
            buffer[read_ret] = 0;
            cmd = strtok(buffer, DELIM);
            arg = strtok(NULL, DELIM);
            handle_command(i, cmd, arg);
        }
    }
}

void connect_client(void)
{
    ASSERT((my_server()->new_socket = accept(S_SOCKET,
        (struct sockaddr *)&S_ADDR, (socklen_t *)
        &my_server()->addr_len)) < 0, "accept error");
    LOG("Connection from %s:%d", inet_ntoa(S_ADDR.sin_addr), ntohs(S_PORT));
    ASSERT(dprintf(my_server()->new_socket, SERVICE_READY) < 0, "message");
    LOG("Welcomed new connection");
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (C_SOCKET == 0) {
            C_SOCKET = my_server()->new_socket;
            break;
        }
    }
}
