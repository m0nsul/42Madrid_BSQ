SRCS	= ./src/ft_aux.c ./src/ft_board.c ./src/ft_board_print.c ./src/ft_board_squares.c ./src/ft_check_first_line.c ./src/ft_file.c ./src/ft_file_io.c ./src/ft_split.c ./src/ft_str.c ./src/ft_strxcpy.c ./src/main.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= bsq
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

run :
	./${NAME} ${BOARD}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

find_sources :
	find src -type f -name "*.c" | xargs -I{} echo ./{} | tr '\n' ' '

re : fclean all

.PHONY: all clean fclean re .c.o test