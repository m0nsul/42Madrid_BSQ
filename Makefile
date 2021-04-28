SRCS	= ft_aux.c ft_board.c ft_board_print.c ft_board_squares.c ft_check_first_line.c ft_file.c ft_file_io.c ft_split.c ft_str.c ft_strxcpy.c main.c
OBJS		= $(addprefix src/, ${SRCS:.c=.o})

SRC_HEADERS	= ft_aux.h ft_board_print.h ft_file.h ft_split.h ft_strxcpy.h ft_board.h ft_board_squares.h ft_file_io.h ft_str.h
HEADERS		:= $(addprefix includes/, ${SRC_HEADERS})

NAME		= bsq

CFLAGS		= -Wall -Wextra -Werror -Ofast

all:		${NAME}

${NAME}:	${OBJS} ${HEADERS}
			gcc ${CFLAGS} ${OBJS} -o $@

.c.o:		${HEADERS}
			gcc ${CFLAGS} -I./includes -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re