# My FTP

## Goal

The goal of this project is to create a **FTP server**.<br />
You MUST implement the given protocol (bonuses must be RFC959 compliant).<br />
You MUST implement request sequences that are explained in the protocol (more information could be find in RFC959)..<br />
The network communication will be achieved through the use of TCP sockets.<br />

> All the standard C library is authorized except **recv**, **send** and **all system calls that make a socket non-blocking**.

## Server
```
USAGE: ./myftp port path
    port is the port number on which the server socket listens
    path is the path to the home directory for the Anonymous use
```

The server MUST be able to handle several clients at the same time by using select for command manage-
ment and fork for data transfer.

> A good use of **select** is expected for both reading and writing on sockets.<br />
> Any bad use of **select** would cause point loss

The server MUST have an authentication with an Anonymous account and an empty password.

Data transfers MUST use active or passive mode, as explained in the bootstrap.
