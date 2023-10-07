SRCS    = get_next_line.c get_next_line_utils.c \

OBJS    = ${SRCS:.c=.o}

NAME    = get_next_line.a

CC      = gcc

CFLAGS    = -Wall -Wextra -Werror

RM        = rm -f

%.o: %.c 
		${CC} ${CFLAGS} -c $< -o $@

${NAME}:${OBJS}
		ar -rcs ${NAME} $?

all:    ${NAME}

clean:
		${RM} ${OBJS}

fclean:        clean
		${RM} ${NAME}

re:            fclean all

.PHONY: all re clean fclean