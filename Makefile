SRC = 	client.c \
		server.c \
		utils.c \
OBJS = ${SRCS:.c=.o}
PRINT = -C ./ft_printf
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
LIBC = ar -rcs

all: ${NAME}

bonus: fclean ${OBJS_B}
	@${LIBC} ${NAME} ${OBJS_B}
	@$ make ${PRINT}
	@echo "<3 :3 uWu <3 :3"

${NAME}: ${OBJS}
	@${LIBC} ${NAME} ${OBJS}

	@echo "<3 :3 uWu <3 :3"

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS} ${OBJS_B}

fclean: clean
	@${RM} ${NAME} ${bonus}

re: fclean all

.PHONY: all bonus clean fclean re .c.o