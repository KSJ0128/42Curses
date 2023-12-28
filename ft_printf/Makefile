NAME = libftprintf.a

CC = cc
CFLAG = -Wall -Wextra -Werror
ARC = ar -rc
RM = rm -f

FT_C = ft_printf.c print_char_str_nbr.c

FT_O = $(FT_C:.c=.o)

FT_H = ft_printf.h

OBJS = $(FT_O)

all : $(NAME)

$(NAME) : $(OBJS)
	$(ARC) $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I $(FT_H)

clean :
	$(RM) $(FT_O) $(BONUS_O)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
