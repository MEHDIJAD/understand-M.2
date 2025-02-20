SRCS   = push_swap.c \
	     ft_check_input.c \
		 ft_fill_stack_a.c \
		 ft_check_double.c \
		 ft_sort_list.c \
		 ft_index_stack_a.c \
		 ft_print_list.c \
		 ft_find_min.c \
		 ft_find_max.c \
		 ft_sorted.c \
		 libft/ft_atoi.c \
		 libft/ft_isdigit.c \
		 libft/ft_lstnew.c \
		 libft/ft_lstlast.c \
		 libft/ft_lstadd_back.c \
		 libft/ft_lstdelone.c \
		 libft/ft_lstclear.c \
		 libft/ft_lstsize.c \
		 libft/ft_lstadd_front.c \
		 ops/ft_op_swap.c \
		 ops/ft_op_rotate.c \
		 ops/ft_op_rrotate.c \
		 ops/ft_op_push.c \
		 algo/ft_sort_three.c \
		 algo/ft_sort_four.c \
		 algo/ft_sort_five.c \
		 algo/ft_sort_mid.c \

SRCS_BONUS = bonus/checker_bonus.c \
             bonus/ft_op_rr_bonus.c \
             bonus/ft_op_rrr_bonus.c \
             bonus/ft_op_ss_bonus.c \
             bonus/ft_sort_with_arg_bonus.c \
			 ops/ft_op_swap.c \
		 	 ops/ft_op_rotate.c \
		 	 ops/ft_op_rrotate.c \
		 	 ops/ft_op_push.c \
			 ft_check_input.c \
			 ft_fill_stack_a.c \
			 ft_check_double.c \
			 ft_index_stack_a.c \
			 ft_sorted.c \
			 ft_print_list.c \
			 libft/ft_atoi.c \
		     libft/ft_isdigit.c \
		     libft/ft_lstnew.c \
		     libft/ft_lstlast.c \
		     libft/ft_lstadd_back.c \
		     libft/ft_lstdelone.c \
		     libft/ft_lstclear.c \
		     libft/ft_lstsize.c \
		     libft/ft_lstadd_front.c \
			 libft/ft_strjoined.c \
			 libft/ft_strlcpy.c \
			 libft/ft_strdup.c \
			 libft/ft_strlen.c \
			 libft/ft_strchr.c \
			 libft/ft_strncmp.c \
			 get_next_line/get_next_line.c \


OBJS   = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME   = push_swap
NAME_BONUS = checker

INCLUDES = -I includes -I ft_printf

FT_PRINTF_DIR = ft_printf

FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

CC     = cc 
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LIBC   = ar rc
RM	   = rm -rf

all: $(FT_PRINTF_LIB) $(NAME)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR) 

# -C: change directory before running the make command.

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) -o $(NAME)

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c  $< -o $@


bonus: $(FT_PRINTF_LIB) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(FT_PRINTF_LIB) -o $(NAME_BONUS)

clean:
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all




