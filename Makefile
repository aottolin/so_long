RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
BOLD = \033[1m

NAME = so_long
ARCHIVE = so_long.a
SRCS = so_long.c \
	   ft_error.c \
	   ft_free.c \
	   ft_memory.c \
	   get_next_line.c \
	   get_next_line_utils.c \
	   key_press.c \
	   print_map.c \
	   read_map.c \
	   ft_strlen2.c \
	   check_exit.c \
	   ft_checkread_map.c \
	   check_flood.c
	
OBJS = $(SRCS:.c=.o)
INCLUD = ./mlx/mlx.h \ ./ft_printf/ft_printf.h \ so_long_lib.h
CC = gcc
MAKE_LIB = ar -rcs
FLAGS = -Wall -Wextra -Werror -MMD -g
LIB = -L. -lmlx -framework OpenGL -framework AppKit
DEPS = $(SRCS:.c=.d)
SILENCE = --no-print-directory

all: $(NAME)

$(NAME) : $(ARCHIVE) so_long_lib.h Makefile ./ft_printf/ft_printf.h
	@echo "$(WHITE) $(NAME) $(RESET) $(GREEN) ok $(RESET)"
	@echo "\n${ORANGE} Minilibx compilando: $(DEF_COLOR)\n"
	@make -C ./mlx all
	@cp ./mlx/libmlx.a .
	@make -C ./ft_printf all $(SILENCE)
	@cp ./ft_printf/libftprintf.a .
	@$(CC) -o $(NAME) $(ARCHIVE) libftprintf.a $(LIB)

$(ARCHIVE) : $(OBJS)
	@$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(GREEN) ok $(RESET) $(CYAN)$(BOLD) $<$(RESET)"

clean:
	@echo "$(MAGENTA) Eliminando .o  ... $(RESET)"
	@make -C ./mlx clean
	@make -C ./ft_printf clean
	@rm -f $(OBJS) $(DEPS) libmlx.a libftprintf.a so_long.a
	@echo "$(GREEN) clean OK  $(RESET)"

fclean: clean
	@echo "$(MAGENTA) Eliminando ... $(RESET)"
	@make -C ./mlx clean
	@make -C ./ft_printf fclean
	@rm -f $(NAME) $(DEPS) libmlx.a libftprintf.a so_long.a
	@echo "$(GREEN) fclean OK  $(RESET)"

re: fclean all

.PHONY: all clean fclean re
