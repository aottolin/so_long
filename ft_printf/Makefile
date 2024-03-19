RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
BOLD = \033[1m

NAME = libftprintf.a
SRCS = ft_hex.c \
	   ft_printf.c \
	   ft_puts.c \
	   ft_ptr_memory.c \
	   ft_unsigned.c

FLAGS = -Wall -Wextra -Werror -MMD
OBJS = $(SRCS:.c=.o)
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
DEPS = $(SRCS:.c=.d)
SILENCE = --no-print-directory

all: $(NAME)
CC = gcc

%.o:%.c Makefile ft_printf.h libft/libft.h libft/Makefile libft/*c
	@echo "$(GREEN) ok $(RESET) $(CYAN)$(BOLD) $<$(RESET)"
	@$(CC) $(FLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJS) Makefile libft/Makefile
	@make -C $(LIBFT_PATH) all $(SILENCE)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(WHITE) $(NAME) $(RESET) $(GREEN) ok $(RESET)"
	@echo "$(GREEN) -Todo ha sido compilado! $(RESET)"

clean:
	@echo "$(MAGENTA) Eliminando .o  ... $(RESET)"
	@rm -f $(OBJS) $(DEPS)
	@make -C $(LIBFT_PATH) clean $(SILENCE)
	@echo "$(GREEN) clean OK  $(RESET)"

fclean: clean
	@echo "$(MAGENTA) Eliminando ... $(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean $(SILENCE)
	@echo "$(GREEN) fclean OK  $(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libft
