/*
** EPITECH PROJECT, 2022
** my_socket.c
** File description:
** TODO
*/

#include "my_ftp.h"

void close_socket(int i)
{
    dprintf(C_SOCKET, DATA_CLOS);
    FCLOSE(C_DTSCT);
    FCLOSE(C_DATA);
    C_DTSCT = 0;
    C_DATA = 0;
}

void open_socket(int i)
{
    dprintf(C_SOCKET, OPENING);
    chdir(C_PATH);
}

void create_data(int i)
{
    C_DATA = socket(AF_INET, SOCK_STREAM, 0);
    ASSERT(C_DATA == -1, "data");
    C_OPT = true;
    ASSERT(setsockopt(C_DATA, SOL_SOCKET, SO_REUSEADDR, (char *)&C_OPT,
        sizeof(C_OPT)) < 0, "data opt");
    C_ADDR.sin_addr.s_addr = htonl(INADDR_ANY);
    C_PORT = htons(0);
    C_ADDR.sin_family = AF_INET;
    ASSERT(bind(C_DATA, (struct sockaddr *)&C_ADDR,
        sizeof(struct sockaddr_in)) == -1, "data bind");
    ASSERT(listen(C_DATA, 1) == -1, "data listen");
    C_ADLEN = sizeof(C_ADDR);
    FD_ZERO(&CLIENT->read_fds);
    FD_SET(C_DATA, &CLIENT->read_fds);
}

void my_pasv(int i)
{
    uint16_t port;

    CHECK_LOG;
    FCLOSE(C_DATA);
    create_data(i);
    port = get_port(C_DATA);
    dprintf(C_SOCKET, PASV, replace(inet_ntoa(S_ADDR.sin_addr), '.', ','),
        port / 256, port % 256);
    LOG("New port opened: %d", port);
    FCLOSE(C_DTSCT);
    C_DTSCT = accept(C_DATA, (struct sockaddr *)&C_ADDR, &C_ADLEN);
}
