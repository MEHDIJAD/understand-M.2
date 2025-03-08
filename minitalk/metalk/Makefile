SRCS_CLIENT = client.c ft_atoi.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)


CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

CLIENT = client
SERVER = server

FT_PRINTF_DIR = ft_printf

FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a


all: $(FT_PRINTF_LIB) $(CLIENT) $(SERVER)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR) 

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(FT_PRINTF_LIB) -o $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(FT_PRINTF_LIB) -o $(SERVER)

%.o:%.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(RM) $(CLIENT) $(SERVER)

re: fclean all


