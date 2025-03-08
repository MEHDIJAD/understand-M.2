SRCS = 	ft_strlen.c \
		ft_strchr.c \
		ft_calloc.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_bzero.c \
		ft_strdup.c \
		ft_strnstr.c \
		ft_itoa.c \

OBJS = $(SRCS:.c=.o)

NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f 
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)

%.o:%.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
	$(LIBC) $(NAME) $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all