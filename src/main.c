/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** handle input and call functions
*/

#include "my_ftp.h"

void int_handler(int a)
{
    (void) a;
    close_server();
    garbage_delete();
    exit(0);
}

int main(int ac, char *av[])
{
    ASSERT(ac != 3, USAGE);
    ASSERT(!strcmp(av[1], "-h"), USAGE);
    parse_av(av);
    create_server();
    signal(SIGINT, int_handler);
    run_server();
    close_server();
    garbage_delete();
    return 0;
}

bool dir_ok(char *path)
{
    DIR *dir = opendir(path);
    bool open = dir;

    closedir(dir);
    return open;
}

void parse_av(char *av[])
{
    char *ptr;
    char actual_path[PATH_MAX];

    realpath(av[2], actual_path);
    ASSERT(!dir_ok(actual_path), "dir");
    my_server()->port = strtol(av[1], &ptr, 10);
    ASSERT(av[1] == ptr || my_server()->port < 0, "port");
    my_server()->home_anon = calloc(strlen(actual_path) + 1, sizeof(char));
    strcpy(my_server()->home_anon, actual_path);
    ASSERT(!my_server()->home_anon, "dir copy");
}
