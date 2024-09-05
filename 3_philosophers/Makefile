PHILO = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD -g -fsanitize=thread -g
RM = rm -f

INCLUDES = -I./incs

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS := $(shell find $(SRCS_DIR) -type f -name '*.c')

OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

DEPS := $(OBJS:%.o=%.d)

all : $(PHILO)

$(PHILO) : $(OBJS)
	$(CC) -o $@ $^ $(INCLUDES) -fsanitize=thread

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

-include $(DEPS)

clean :
	@$(RM) $(OBJS) $(DEPS)
	@rmdir -p $(OBJS_DIR) || true

fclean : clean
	$(RM) $(PHILO)

re : fclean all

.PHONY : all clean fclean re
