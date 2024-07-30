SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD
RM = rm -f

LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a

SRCS_DIR = srcs

LIBFT_OBJS_DIR = libft/objs
PRINTF_OBJS_DIR = ft_printf/objs

INCLUDES = -I./includes -I./libft/includes -I./ft_printf/includes

SERVER_SRCS = server.c
CLIENT_SRCS = client.c
LIBFT_SRCS := $(shell find libft -type f -name '*.c')
PRINTF_SRCS := $(shell find ft_printf -type f -name '*.c')

SERVER_OBJS = $(addprefix $(SRCS_DIR)/, $(SERVER_SRCS:.c=.o))
CLIENT_OBJS = $(addprefix $(SRCS_DIR)/, $(CLIENT_SRCS:.c=.o))
LIBFT_OBJS := $(patsubst libft/%.c,$(LIBFT_OBJS_DIR)/%.o,$(LIBFT_SRCS))
PRINTF_OBJS := $(patsubst ft_printf/%.c,$(PRINTF_OBJS_DIR)/%.o,$(PRINTF_SRCS))

OBJS = $(SERVER_OBJS) $(CLIENT_OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)

SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_SRCS = client_bonus.c

SERVER_BONUS_OBJS = $(addprefix $(SRCS_DIR)/, $(SERVER_BONUS_SRCS:.c=.o))
CLIENT_BONUS_OBJS = $(addprefix $(SRCS_DIR)/, $(CLIENT_BONUS_SRCS:.c=.o))

BONUS_OBJS = $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)

DEPS := $(OBJS:%.o=%.d) $(BONUS_OBJS:%.o=%.d)

all : $(SERVER) $(CLIENT)

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT) :
	@$(MAKE) -C ./libft;

$(PRINTF) :
	@$(MAKE) -C ./ft_printf;

$(SERVER) : $(SERVER_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJS) $(LIBFT) $(PRINTF)

$(CLIENT) : $(CLIENT_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJS) $(LIBFT) $(PRINTF)

$(SERVER_BONUS) : $(SERVER_BONUS_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(SERVER_BONUS_OBJS) $(LIBFT) $(PRINTF)

$(CLIENT_BONUS) : $(CLIENT_BONUS_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_BONUS_OBJS) $(LIBFT) $(PRINTF)

-include $(DEPS)

clean :
	@$(MAKE) -C libft clean;
	@$(MAKE) -C ft_printf clean;
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS) $(DEPS)

fclean : clean
	@$(MAKE) -C libft fclean;
	@$(MAKE) -C ft_printf fclean;
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re : fclean all

.PHONY : all bonus clean fclean re
