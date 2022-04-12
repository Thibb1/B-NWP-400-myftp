##
## EPITECH PROJECT, 2022
## main.c
## File description:
## done
##

OUT 	=	ftp
SOURCE	=	src/main.c
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

re:		all

debug:	CFLAGS	+=	-ggdb
debug:	re

.PHONY:	all clean fclean re debug
