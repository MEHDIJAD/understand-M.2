SRCS =  mand/so_long.c \
		mand/get_next_line/get_next_line.c \
		mand/ft_get_map.c \
		mand/ft_tools.c \
		mand/ft_exit.c  \
		mand/ft_get_map_dimention.c \
		mand/ft_get_img_data.c \
		mand/ft_drow_map.c \
		mand/ft_first_move.c \
		mand/ft_get_player_position.c \
		mand/ft_valid_map.c \
		mand/ft_cleanup_game.c \
		mand/ft_checking_tools.c \
		mand/ft_puterror.c \
		mand/ft_put_image.c \
		mand/ft_moving_player.c \

BSRCS = bonus/so_long_bonus.c \
		bonus/get_next_line_bonus/get_next_line.c \
		bonus/ft_get_map_bonus.c \
		bonus/ft_tools_bonus.c \
		bonus/ft_exit_bonus.c  \
		bonus/ft_get_map_dimention_bonus.c \
		bonus/ft_get_img_data_bonus.c \
		bonus/ft_drow_map_bonus.c \
		bonus/ft_first_move_bonus.c \
		bonus/ft_get_player_position_bonus.c \
		bonus/ft_valid_map_bonus.c \
		bonus/ft_cleanup_game_bonus.c \
		bonus/ft_checking_tools_bonus.c \
		bonus/ft_puterror_bonus.c \
		bonus/ft_put_image_bonus.c \
		bonus/ft_moving_enemy.c \
		bonus/ft_moving_player_bonus.c \
		bonus/ft_put_open_door.c \
		bonus/ft_count_collectibles.c \
		bonus/ft_check_components.c \
	
CC 		= cc

CFLAGS 	=  -Wall -Wextra -Werror

MLX = -L/home/eel-garo/include/mlx/ -lmlx -lX11 -lXext

HEADERS_MAND =  mand/so_long.h libft/libft.h ft_printf/ft_printf.h

HEADERS_BONUS =  bonus/so_long_bonus.h libft/libft.h ft_printf/ft_printf.h

LIBFT_SRC=  libft/ft_strlen.c \
			libft/ft_strchr.c \
			libft/ft_calloc.c \
			libft/ft_memcpy.c \
			libft/ft_memset.c \
			libft/ft_bzero.c \
			libft/ft_strdup.c \
			libft/ft_strnstr.c \
			libft/ft_itoa.c \

FT_PRINTF_SRC = ft_printf/ft_printf.c \
				ft_printf/ft_print_format.c \
				ft_printf/ft_printchar.c \
				ft_printf/ft_printstr.c \
				ft_printf/ft_printdigit.c \
			
LIBFT_OB = $(LIBFT_SRC:.c=.o)

FT_PRINTF_OB = $(FT_PRINTF_SRC:.c=.o)

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

INCLUDES = -I includes -I ft_printf -I /home/eel-garo/include/mlx/

FT_PRINTF_DIR = ft_printf

LIBFT_DIR = libft

LIBFT_LIB = $(LIBFT_DIR)/libft.a

FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

FT_GET_NEXT_LINE_DIR = get_next_line

NAME 	= so_long
B_NAME  = so_long_bonus

all : $(FT_PRINTF_LIB) $(LIBFT_LIB) $(NAME)

bonus: $(FT_PRINTF_LIB) $(LIBFT_LIB) $(B_NAME)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_OB) $(FT_PRINTF_OB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)                     

$(B_NAME): $(BOBJS) $(LIBFT_OB) $(FT_PRINTF_OB)
	$(CC) $(CFLAGS) $(BOBJS) $(MLX) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(B_NAME)     

$(OBJS): %.o:%.c $(HEADERS_MAND)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BOBJS): %.o:%.c $(HEADERS_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(B_NAME)


re: fclean all
