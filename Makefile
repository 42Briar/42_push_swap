NAME = push_swap
CC = gcc
SRC = main.c 
CFLAGS = -Wextra -Wall -Werror
OBJ = ${SRC:.c=.o}
LIBFT = ./libft
HEADERS = -I ./includes

GREEN = \x1b[32m
RESET = \033[0m
RED   = \x1b[31m

%.o: %.c
	@$(CC) -o $@ -c $< $(HEADERS)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Making libft...$(RESET)"
	@$(MAKE) -C $(LIBFT)
	@mv libft/libft.a .
	@echo "$(GREEN)Compiling...$(RESET)"
	@$(CC) $(SRC) $(HEADERS) libft.a -o $(NAME)
	@echo "$(GREEN)Done!$(RESET)"

clean:
	@echo "$(RED)Cleaning...$(RESET)"
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT) clean
	@echo "$(RED)Done!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.a

re: fclean all


.PHONY: clean, all, fclean, re