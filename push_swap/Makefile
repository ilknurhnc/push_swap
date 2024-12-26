NAME = push_swap

SRCS = 	push_swap.c \
		stack_op/stack_op.c \
		stack_op/stack_op1.c  \
		stack_op/stack_op2.c  \
		stack_op/stack_op3.c  \
		utils/utils_av_control.c \
		utils/utils_sort_control.c \
		utils/utils_stack.c\
		utils/utils_function.c\
		utils/utils_function1.c\
		utils/utils_list.c\
		sort.c\

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
RM = rm -f

all: ${NAME} ${CHECK}
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re