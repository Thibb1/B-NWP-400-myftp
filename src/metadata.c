/*
** EPITECH PROJECT, 2022
** metadata.c
** File description:
** static vars used thorough the program
*/

#include "my_ftp.h"

server_t *my_server(void)
{
    static server_t *server;

    if (!server)
        server = calloc(1, sizeof(server_t));
    return server;
}

client_t **my_clients(void)
{
    static client_t **clients;

    if (!clients)
        clients = calloc(MAX_CLIENTS, sizeof(client_t *));
    return clients;
}

client_t *my_client(int idx)
{
    if (!my_clients()[idx])
        my_clients()[idx] = calloc(1, sizeof(client_t));
    return my_clients()[idx];
}

void garbage_delete(void)
{
    if (my_server())
        DESTROY(my_server()->home_anon);
    DESTROY(my_server());
    for (int i = 0; i < MAX_CLIENTS; i++) {
        DESTROY(C_PATH);
        DESTROY(C_CMD);
        DESTROY(C_ACC);
        DESTROY(my_client(i));
    }
    DESTROY(my_clients());
}
