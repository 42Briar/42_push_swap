NAME = push_swap
CC = gcc
SRC = main.c utils.c operations-s.c operations-p.c operations-r.c operations-rr.c solve.c sort.c
LIBFT =	./libft/libft.a
LIBFT_DIR =	./libft
CFLAGS = -Wextra -Wall -Werror
INC =	-I. -I$(LIBFT_DIR) 
OBJ = ${SRC:.c=.o}

GREEN = \x1b[32m
RESET = \033[0m
RED   = \x1b[31m

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(GREEN)Compiling...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INC) -o $(NAME)
	@echo "$(GREEN)Done!$(RESET)"

$(LIBFT):
	@echo "$(GREEN)Making libft...$(RESET)"
	@$(MAKE) -C ./libft

clean:
	@echo "$(RED)Cleaning...$(RESET)"
	@rm -f $(OBJ)
	@$(MAKE) -C ./libft clean
	@echo "$(RED)Done!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: clean, all, fclean, re