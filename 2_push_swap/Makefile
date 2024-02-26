NAME = push_swap

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -f

FT_C = main.c ft_printf.c print_char_str_nbr.c

FT_O = $(FT_C:.c=.o)

FT_H = push_swap.h

OBJS = $(FT_O)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	$(RM) $(FT_O)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re