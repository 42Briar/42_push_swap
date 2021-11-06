NAME = push_swap
CC = gcc
SRC = main.c utils.c operations-s.c operations-p.c operations-r.c operations-rr.c solve.c sort.c
CFLAGS = -Wextra -Wall -Werror
OBJ = ${SRC:.c=.o}
LIBFT = ./libft
HEADERS = -I ./includes

GREEN = \x1b[32m
RESET = \033[0m
RED   = \x1b[31m

%.o: %.c
	@$(CC) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Making libft...$(RESET)"
	@$(MAKE) -C $(LIBFT) bonus
	@mv libft/libft.a .
	@echo "$(GREEN)Compiling...$(RESET)"
	@$(CC) $(SRC) libft.a -o $(NAME)
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