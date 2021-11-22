SRCS		=       $(wildcard Include/*.c) \
                        $(wildcard ./*.c)\

OBJS		=	${SRCS:.c=.o}

FLAGS		=	-Wall -Wextra -Werror -g

LIB		=	MyCrd.a

NAME		=	MyCrd

RM		=	rm -rf


all		:	${NAME}
			$(shell mv ${NAME} ./Release)

$(NAME)		:	${OBJS}
			ar rcs ${LIB} ${OBJS}
			ranlib ${LIB}
			gcc my_crd.c -o ${NAME} ${LIB} -I. -g

.c.o		:
			gcc ${FLAGS} -c $< -o ${<:.c=.o}

clean		:
			${RM} ${OBJS}
			${RM} ${LIB}

fclean		:	clean
			${RM} ${NAME}

re		:	fclean all

allc		:	all clean

rec		:	re clean
