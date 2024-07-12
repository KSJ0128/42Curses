NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -MMD
RM = rm -f

LIBFT = libft.a
LIBFT_DIR = 0_libft

PRINTF = libftprintf.a
PRINTF_DIR = 1_ft_printf

SRCS_DIR = srcs
BONUS_DIR = bonus_srcs
OBJS_DIR = objs
BONUS_OBJS_DIR = bonus_objs
INCLUDES_DIR = includes
BONUS_INCLUDES_DIR = bonus_includes

INCLUDES = -I./$(INCLUDES_DIR) -I./$(LIBFT_DIR) -I./$(PRINTF_DIR)
BONUS_INCLUDES = -I./$(BONUS_INCLUDES_DIR) -I./$(LIBFT_DIR) -I./$(PRINTF_DIR)

SRCS := $(shell find $(SRCS_DIR) -type f -name '*.c')
BONUS_SRCS := $(shell find $(BONUS_DIR) -type f -name '*.c')
OBJS := $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))
BONUS_OBJS := $(patsubst $(BONUS_DIR)/%.c,$(BONUS_OBJS_DIR)/%.o,$(BONUS_SRCS))
DEPS := $(OBJS:%.o=%.d) $(BONUS_OBJS:%.o=%.d)

all : $(NAME)

$(NAME) : $(LIBFT_DIR)/$(LIBFT) $(PRINTF_DIR)/$(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(PRINTF_DIR)/$(PRINTF)

$(BONUS) : $(LIBFT_DIR)/$(LIBFT) $(PRINTF_DIR)/$(PRINTF) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $@ $(BONUS_OBJS) $(LIBFT_DIR)/$(LIBFT) $(PRINTF_DIR)/$(PRINTF)

$(LIBFT_DIR)/$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR);

$(PRINTF_DIR)/$(PRINTF) :
	@$(MAKE) -C $(PRINTF_DIR);

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(@D);
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJS_DIR)/%.o : $(BONUS_DIR)/%.c
	@mkdir -p $(@D);
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEPS)

bonus : $(BONUS)

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean;
	@$(MAKE) -C $(PRINTF_DIR) clean;
	@$(RM) $(OBJS) $(BONUS_OBJS) $(DEPS)

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean;
	@$(MAKE) -C $(PRINTF_DIR) fclean;
	$(RM) $(NAME) $(BONUS)

re : fclean all

.PHONY : all bonus clean fclean re
