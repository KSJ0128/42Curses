NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD
MLX = -g3 -fsanitize=address -L./mlx -lmlx -framework OpenGL -framework AppKit -lz
RM = rm -rf

LIBFT = libft.a
LIBFT_DIR = 0_libft

SRCS_DIR = srcs
OBJS_DIR = objs
INCLUDES_DIR = includes

INCLUDES = -I./$(INCLUDES_DIR) -I./$(LIBFT_DIR)

SRCS := $(shell find $(SRCS_DIR) -type f -name '*.c')
OBJS := $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:%.o=%.d)

all : $(NAME)

$(NAME) : $(LIBFT_DIR)/$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(MLX) -o $@ $(OBJS) $(LIBFT_DIR)/$(LIBFT)

$(LIBFT_DIR)/$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR);

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(@D);
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEPS)

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean;
	@$(RM) $(OBJS) $(DEPS)

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean;
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
