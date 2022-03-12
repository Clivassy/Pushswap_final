NAME = push_swap

SRCS = ft_cases.c ft_check_errors.c ft_parsing.c ft_push.c ft_reverse_rotate.c ft_rotate.c ft_sort_large.c ft_sort_small_utils.c ft_sort_small.c ft_swap.c push_swap.c ft_lists.c ft_utils.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME} ${CHECK}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
