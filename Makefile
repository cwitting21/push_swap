# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwitting <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 20:16:44 by cwitting           #+#    #+#              #
#    Updated: 2019/11/10 17:03:16 by cwitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
CC = gcc -g
FLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft/
SRC_DIR = ./srcs/
INC_DIR = ./includes/

SOURCE := 	new_lst.c args_to_lst.c pb.c pa.c swap.c ss.c rotate.c rr.c \
			rev_rotate.c rrr.c stack_is_sorted.c get_next_line.c

SRC := $(addprefix $(SRC_DIR), $(SOURCE))
INCLUDES = push_swap.h
INC = $(addprefix $(INC_DIR), $(INCLUDES))
OBJ = $(SOURCE:.c=.o)

GREEN = \033[0;32m
RESET = \033[0m
RED = \033[0;31m
CYAN = \033[0;36m

all: lib $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(SRC) $(INC)
	@echo "$(GREEN)compiling...$(RESET)"
	@$(CC) -o $(CHECKER) srcs/checker.c $(SRC) -L $(LIB_DIR) -lft
	@echo "$(CYAN)DONE$(RESET)"

$(PUSH_SWAP): $(SRC) $(INC)
	@echo "$(GREEN)compiling...$(RESET)"
	@$(CC) -o $(PUSH_SWAP) srcs/push_swap.c $(SRC) -L $(LIB_DIR) -lft
	@echo "$(CYAN)DONE$(RESET)"

lib:
	@make -C $(LIB_DIR) > /dev/null

clean:
	@make -C $(LIB_DIR) clean
	@echo "$(RED)Object files removed$(RESET)"
	@rm -rf *.dSYM

fclean:	clean
	@rm -f $(CHECKER)
	@rm -f $(PUSH_SWAP)
	@echo "$(RED)Fully clean$(RESET)"

re:	fclean all

.PHONY: clean fclean
