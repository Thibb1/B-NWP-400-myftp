/*
** EPITECH PROJECT, 2022
** my_commands.h
** File description:
** TODO
*/

#ifndef MYFTP_MY_COMMANDS_H
    #define MYFTP_MY_COMMANDS_H

void my_user(int);
void my_pass(int);
void my_cwd(int);
void my_cdup(int);
void my_quit(int);
void my_pwd(int);
void my_help(int);
void my_noop(int);

static const char *COMMANDS[] = {
    "USER",
    "PASS",
    "CWD",
    "CDUP",
    "QUIT",
    "DELE",
    "PWD",
    "PASV",
    "PORT",
    "HELP",
    "NOOP",
    "RETR",
    "STOR",
    "LIST",
    NULL
};

static void (*COMMANDS_FUNC[])(int) = {
    my_user,
    my_pass,
    my_cwd,
    my_cdup,
    my_quit,
    NULL,
    my_pwd,
    NULL,
    NULL,
    my_help,
    my_noop,
    NULL,
    NULL,
    NULL
};

#endif
