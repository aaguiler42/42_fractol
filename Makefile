NAME		= fractol

SRCS		= src/main.c src/hooks.c src/fractals.c src/utils.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

INCLUDES	= -I include -I MLX42/include/MLX42

LIBS		= MLX42/libmlx42.a -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all:	${NAME}

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< ${INCLUDES}

${NAME}: ${OBJS}
	make -C MLX42
	${CC} ${OBJS} ${LIBS} ${INCLUDES} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

normi:
	norminette ${SRCS} include

.PHONY: all, clean, fclean, re