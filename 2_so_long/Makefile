NAME = so_long

CC = cc
CFLAG = -Wall -Wextra -Werror
MLX = -g -fsanitize=address -L./mlx -lmlx -framework OpenGL -framework AppKit -lz
RM = rm -f

FT_C = main.c map.c util1.c dfs.c mlx.c 1_ft_printf/ft_printf.c 1_ft_printf/print_char_str_nbr.c 1_get_next_line/get_next_line.c 1_get_next_line/get_next_line_utils.c 0_libft/ft_split.c

FT_O = $(FT_C:.c=.o)

FT_H = so_long.h

OBJS = $(FT_O)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(MLX) -o $(NAME) $(OBJS)

clean :
	$(RM) $(FT_O)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
