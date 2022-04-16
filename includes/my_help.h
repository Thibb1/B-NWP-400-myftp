/*
** EPITECH PROJECT, 2022
** my_help.h
** File description:
** help strings
*/

#ifndef MYFTP_MY_HELP_H
    #define MYFTP_MY_HELP_H
static const char *COMMANDS_HELP[] = {
    "USER <username>" RESET ": Specify user for authentication",
    "PASS <password>" RESET ": Specify password for authentication",
    "CWD <pathname>" RESET ": Change working directory",
    "CDUP" RESET ": Change working directory to parent director",
    "QUIT" RESET ": Disconnection",
    "DELE <pathname>" RESET ": Delete file on the server",
    "PWD" RESET ": Print working directory",
    "PASV" RESET ": Enable \"passive\" mode for data transfer",
    "PORT <host-port>" RESET ": Enable \"active\" mode for data transfer",
    "HELP[ <string>]" RESET ": List available commands",
    "NOOP" RESET ": Do nothing",
    "RETR <pathname>" RESET ": Download file from server to client",
    "STOR <pathname>" RESET ": Upload file from client to server",
    "LIST[ <pathname>]" RESET ": List files in the current working directory",
    NULL
};
#endif
