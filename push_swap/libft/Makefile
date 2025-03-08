SRCS = 	ft_atoi.c \
		ft_isdigit.c \
		ft_lstnew.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstsize.c \
		ft_lstadd_front.c \
		ft_strjoined.c \
		ft_strlcpy.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strncmp.c \

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