SRC		= ft_printf.c ft_outil.c ft_outil_p.c
OBJS	= $(SRC:.c=.o)
NAME	= libftprintf.a
CC		= gcc
AR		= ar rc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:		all clean fclean re