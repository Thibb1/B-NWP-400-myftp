/*
** EPITECH PROJECT, 2022
** server.c
** File description:
** TODO
*/

#include "my_ftp.h"

void close_server(void)
{
    for (int i = 0; i < MAX_CLIENTS; i++)
        disconnect_client(i);
    close(S_SOCKET);
    LOG("Closing server");
}

void create_server(void)
{
    S_SOCKET = socket(AF_INET, SOCK_STREAM, 0);
    ASSERT(S_SOCKET == -1, "socket");
    S_OPT = true;
    ASSERT(setsockopt(S_SOCKET, SOL_SOCKET, SO_REUSEADDR, (char *)&S_OPT,
        sizeof(S_OPT)) < 0, "socket opt");
    S_ADDR.sin_addr.s_addr = htonl(INADDR_ANY);
    S_PORT = htons(my_server()->port);
    S_ADDR.sin_family = AF_INET;
    ASSERT(bind(S_SOCKET, (struct sockaddr *)&S_ADDR,
        sizeof(struct sockaddr_in)) == -1, "bind");
    ASSERT(listen(S_SOCKET, MAX_CLIENTS) == -1, "listen");
    S_ADLEN = sizeof(S_ADDR);
    for (int i = 0; i < MAX_CLIENTS; i++)
        C_SOCKET = 0;
}

void run_server(void)
{
    my_server()->running = true;
    LOG("Server listening");
    while (my_server()->running) {
        routine_server();
        if (FD_ISSET(S_SOCKET, &SERVER->read_fds))
            connect_client();
        for (int i = 0; i < MAX_CLIENTS; i++)
            handle_client(i);
    }
}

void routine_server(void)
{
    FD_ZERO(&SERVER->read_fds);
    FD_SET(S_SOCKET, &SERVER->read_fds);
    SERVER->max_fd = S_SOCKET;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (C_SOCKET > 0)
            FD_SET(C_SOCKET, &SERVER->read_fds);
        if (C_SOCKET > SERVER->max_fd)
            SERVER->max_fd = C_SOCKET;
    }
    SERVER->activity = select(SERVER->max_fd + 1, &SERVER->read_fds, NULL,
        NULL, NULL);
    ASSERT((SERVER->activity < 0) && (errno != EINTR), "select");
}
