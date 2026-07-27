NAME		= bsq

SRCS		= ./srcs/main.c \
			  ./srcs/read_utils.c \
			  ./srcs/str_utils.c \
			  ./srcs/parse.c \
			  ./srcs/solve.c \
			  ./srcs/print.c

OBJS		= ${SRCS:.c=.o}

HEAD		= ./includes/

GCC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${GCC} ${CFLAGS} -I ${HEAD} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
