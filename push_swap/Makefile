SRCS   = 	 mand/push_swap.c \
	     	 mand/ft_check_input.c \
		 	 mand/ft_fill_stack_a.c \
		 	 mand/ft_check_double.c \
		 	 mand/ft_sort_list.c \
		 	 mand/ft_index_stack_a.c \
		 	 mand/ft_find_min.c \
		 	 mand/ft_find_max.c \
		 	 mand/ft_sorted.c \
		 	 mand/ops/ft_op_swap.c \
		 	 mand/ops/ft_op_rotate.c \
		 	 mand/ops/ft_op_rrotate.c \
		 	 mand/ops/ft_op_push.c \
		 	 mand/algo/ft_sort_three.c \
		 	 mand/algo/ft_sort_four.c \
		 	 mand/algo/ft_sort_five.c \
		 	 mand/algo/ft_sort_mid.c \

SRCS_BONUS = bonus/checker_bonus.c \
             bonus/ft_op_rr_bonus.c \
             bonus/ft_op_rrr_bonus.c \
             bonus/ft_op_ss_bonus.c \
             bonus/ft_sort_with_arg_bonus.c \
			 bonus/ops/ft_op_swap_bonus.c \
		 	 bonus/ops/ft_op_rotate_bonus.c \
		 	 bonus/ops/ft_op_rrotate_bonus.c \
		 	 bonus/ops/ft_op_push_bonus.c \
			 bonus/ft_check_input_bonus.c \
			 bonus/ft_fill_stack_a_bonus.c \
			 bonus/ft_check_double_bonus.c \
			 bonus/ft_index_stack_a_bonus.c \
			 bonus/ft_sorted_bonus.c \
			 bonus/get_next_line/get_next_line.c \

LIBFT_SRC = libft/ft_atoi.c \
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
			libft/ft_strncmp.c \

FT_PRINTF_SRC = ft_printf/ft_printf.c \
				ft_printf/ft_print_format.c \
				ft_printf/ft_printchar.c \
				ft_printf/ft_printstr.c \
				ft_printf/ft_printdigit.c \


LIBFT_OB = $(LIBFT_SRC:.c=.o)

FT_PRINTF_OB = $(FT_PRINTF_SRC:.c=.o)

OBJS   = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

FT_PRINTF_DIR = ft_printf

FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = libft

LIBFT_LIB = $(LIBFT_DIR)/libft.a

CC     = cc

CFLAGS = -Wall -Wextra -Werror

HEADERS_MAND = mand/push_swap.h libft/libft.h ft_printf/ft_printf.h
HEADERS_BONUS = bonus/push_swap_bonus.h libft/libft.h ft_printf/ft_printf.h

LIBC   = ar rc
RM	   = rm -rf
NAME   = push_swap
NAME_BONUS = checker

all: $(FT_PRINTF_LIB)  $(LIBFT_LIB) $(NAME)

bonus: $(FT_PRINTF_LIB) $(LIBFT_LIB) $(NAME_BONUS)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_OB) $(FT_PRINTF_OB)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_OB) $(FT_PRINTF_OB)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(NAME_BONUS)

$(OBJS): %.o:%.c $(HEADERS_MAND)
	$(CC) $(CFLAGS) -c  $< -o $@

$(OBJS_BONUS): %.o:%.c $(HEADERS_BONUS)
	$(CC) $(CFLAGS) -c  $< -o $@

clean:
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all




