C_YELLOWB=\033[1;33m
C_BLUEB=\033[1;34m
C_REDB=\033[0;91m
C_WHITE=\033[0;97m
C_WHITEB=\033[1;97m
C_RESET=\033[0;39m

SRCS	= ./src/ft_aux.c ./src/ft_board.c ./src/ft_board_print.c ./src/ft_board_squares.c ./src/ft_check_first_line.c ./src/ft_file.c ./src/ft_file_io.c ./src/ft_split.c ./src/ft_str.c ./src/ft_strxcpy.c ./src/main.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= bsq
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
BOARD   = tablero661 tablero552

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

norm : 
	norminette */*.[ch]

find_sources :
	find src -type f -name "*.c" | xargs -I{} echo ./{} | tr '\n' ' '

re : fclean all

test : re
	@echo "[$(C_YELLOWB)TESTING$(C_RESET)] $(C_WHITEB)${BOARD}$(C_RESET)" ;
	@echo "\n"
	@./${NAME} ${BOARD}  || true ;
	@##
	@echo "\n"

.PHONY: all clean fclean re .c.o test