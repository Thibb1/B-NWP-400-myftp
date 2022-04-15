##
## EPITECH PROJECT, 2022
## main.c
## File description:
## done
##

OUT 	=	myftp
SOURCE	=	src/main.c			\
			src/metadata.c		\
			src/server.c		\
			src/client.c		\
			src/command.c		\
			src/string_util.c
CC		=	gcc
CFLAGS	=	-W -Wall -Wshadow -Wextra -I./includes
LDFLAGS	=
OBJS	=	$(SOURCE:.c=.o)


$(OUT):	$(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS) $(LDFLAGS)

all:	$(OUT)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(OUT)

re:		fclean all

debug:	CFLAGS	+=	-ggdb
debug:	re

.PHONY:	all clean fclean re debug
