/*
** EPITECH PROJECT, 2022
** my_file.c
** File description:
** file access
*/

#include "my_ftp.h"

void my_dele(int i)
{
    CHECK_LOG;
    CHECK_ARG(C_CMD[1]);
    chdir(C_PATH);
    if (access(C_CMD[1], W_OK) == 0 && remove(C_CMD[1]) == 0)
        dprintf(C_SOCKET, DELE, C_CMD[1]);
    else
        dprintf(C_SOCKET, FILE_ERROR, C_CMD[1]);
}

void my_retr(int i)
{
    FILE *f;

    CHECK_LOG;
    CHECK_ARG(C_CMD[1]);
    CHECK_SOCKET;
    open_socket(i);
    if (fork() == 0) {
        f = fopen(C_CMD[1], "r");
        if (f) {
            read_output(f, i, false);
            fclose(f);
        } else
            dprintf(C_SOCKET, FILE_ERR);
        garbage_delete();
        exit(0);
    }
    close_socket(i);
}

void store_file(int i)
{
    FILE *in = fdopen(C_DTSCT, "r");
    int ch;
    int out;

    if (!(in))
        dprintf(C_SOCKET, FILE_ERR);
    else if ((out = open(C_CMD[1], O_WRONLY | O_CREAT, 0644)) < 0) {
        fclose(in);
        dprintf(C_SOCKET, FILE_ERR);
    } else {
        while ((ch = fgetc(in)) != EOF)
            dprintf(out, "%c", ch);
        fclose(in);
        FCLOSE(out);
    }
}

void my_stor(int i)
{
    CHECK_LOG;
    CHECK_ARG(C_CMD[1]);
    CHECK_SOCKET;
    open_socket(i);
    if (fork() == 0) {
        store_file(i);
        garbage_delete();
        exit(0);
    }
    close_socket(i);
}
