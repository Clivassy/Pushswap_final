SRCS	= main.c push_swap.c main.c ft_check_errors.c

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
	@ar rcs ${NAME} ${OBJS} ./libft/libft.a -o ${NAME}
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
