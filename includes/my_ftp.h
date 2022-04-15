/*
** EPITECH PROJECT, 2022
** my_ftp.h
** File description:
** TODO
*/

#ifndef MYFTP_MY_FTP_H
    #define MYFTP_MY_FTP_H
    #include <sys/socket.h>
    #include <sys/un.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <errno.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include <dirent.h>
    #include <time.h>

    #define MAX_CLIENTS 2

    #define DELIM " \r\n"

    #define RESET "\033[0m"
    #define RED "\033[31m"
    #define GREEN "\033[32m"
    #define BLUE "\033[34m"
    #define BOLD "\033[1m"
    #define CR "\r\n"

    #define LOG_MESS BLUE "[%02d:%02d:%02d] " RESET BOLD GREEN "[%s:%d] " \
    RESET BOLD "%s " RESET
    #define ERROR BOLD RED "[%s:%d] " RESET BOLD "%s " RESET
    #define USAGE "USAGE: ./myftp port path\n" \
    "\tport is the port number on which the server socket listens\n" \
    "\tpath is the path to the home directory for the Anonymous use"

    #define NOOP "200 " BOLD GREEN "Command ok." RESET CR
    #define HELP "214 " BOLD BLUE "Help message." RESET CR
    #define SERVICE_READY "220 " BOLD GREEN "Service ready for new user." \
    RESET CR
    #define LOGOUT "221 " BOLD RED "Disconnected" RESET CR
    #define SYNTAX_ERROR "501 " BOLD RED "Syntax error in parameters or" \
    " arguments" RESET CR

    #define DESTROY(v) \
if (v) { \
    free(v); \
}

typedef struct server_s {
    long port;
    char *home_anon;
    int socket;
    int max_fd;
    int opt;
    struct sockaddr_in addr;
    int addr_len;
    fd_set read_fds;
    int activity;
    int new_socket;
    int read_ret;
    bool running;
} server_t;

typedef struct client_s {
    char *home;
    int socket;
} client_t;

bool dir_ok(char *path);
void parse_av(char *av[]);
void int_handler(int);

void create_server(void);
void close_server(void);
void run_server(void);
void routine_server(void);

void connect_client(void);
void handle_client(int);
void disconnect_client(int);

void handle_command(int, char *, char *);

void garbage_delete(void);
server_t *my_server(void);
client_t **my_clients(void);
client_t *my_client(int);

    #define DEF_OR_ARG(value, ...) value
    #define ASSERT(v, ...) \
if (v) { \
    fprintf(stderr, ERROR, __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stderr, "(%s)\n", DEF_OR_ARG(__VA_ARGS__ __VA_OPT__(,) "Error")); \
    garbage_delete(); \
    exit(84); \
}
    #define LOG(fm, args...) \
{ \
    time_t t = time(NULL); \
    struct tm tm = *localtime(&t); \
    printf(LOG_MESS fm "\n", tm.tm_hour, tm.tm_min, tm.tm_sec, __FILE__, \
    __LINE__, __FUNCTION__, ##args); \
}
    #define CHECK_ARG(v) \
if (!(v)) { \
    dprintf(C_SOCKET, SYNTAX_ERROR); \
    return; \
}

    #define C_SOCKET my_client(i)->socket
    #define S_SOCKET my_server()->socket
    #define S_ADDR my_server()->addr
    #define S_PORT S_ADDR.sin_port
#endif
