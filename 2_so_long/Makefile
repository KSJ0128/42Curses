NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit -lz
RM = rm -rf

LIBFT = libft.a
LIBFT_DIR = 0_libft

PRINTF = libftprintf.a
PRINTF_DIR = 1_ft_printf

SRCS_DIR = srcs
OBJS_DIR = objs
INCLUDES_DIR = includes

INCLUDES = -I./$(INCLUDES_DIR) -I./$(LIBFT_DIR) -I./$(PRINTF_DIR)

SRCS := $(shell find $(SRCS_DIR) -type f -name '*.c')
OBJS := $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:%.o=%.d)

all : $(NAME)

$(NAME) : $(LIBFT_DIR)/$(LIBFT) $(PRINTF_DIR)/$(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(MLX) -o $@ $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(PRINTF_DIR)/$(PRINTF)

$(LIBFT_DIR)/$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR);

$(PRINTF_DIR)/$(PRINTF) :
	@$(MAKE) -C $(PRINTF_DIR);

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(@D);
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEPS)

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean;
	@$(MAKE) -C $(PRINTF_DIR) clean;
	@$(RM) $(OBJS) $(DEPS)

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean;
	@$(MAKE) -C $(PRINTF_DIR) fclean;
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
