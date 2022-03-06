SRCS	= ft_cases.c ft_check_errors.c ft_parsing.c ft_push.c ft_reverse_rotate.c ft_rotate.c ft_sort_large.c ft_sort_small_utils.c ft_sort_small.c ft_swap.c push_swap.c ft_lists.c

OBJS	= ${SRCS:.c=.o}

CC	= gcc

NAME	= pushswap.a

CFLAGS	= -Wall -Werror -Wextra 

RM	= rm -f

%.o : 	%.c
	@echo "\033[0;31mCompiling..."
	@${CC} -o $@ -c $< ${CFLAGS}
	
all : ${NAME}

$(NAME) : ${OBJS} push_swap.h
	@${MAKE} -C ./libft
	@echo "\033[0;33mLinking..."
	@ar rcs ${NAME} ${OBJS} ./libft/libft.a ${NAME}
	@echo "\033[0;32mOK!"

clean :
	@echo "\033[0;33mCleaning..."
	@echo "\033[0;33mCleaning..."
	@echo "\033[0;33mCleaning..."
	@${RM} ${OBJS}
	@${MAKE} -C ./libft fclean
	@echo "\033[0;32mOK CLEAN!"

fclean : clean
	${RM} ${NAME}

re : fclean all
