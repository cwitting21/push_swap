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

NAME = push_swap

CC = gcc -g
FLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft/
SRC_DIR = ./srcs/
INC_DIR = ./includes/

SOURCE := new_lst.c args_to_lst.c pb.c pa.c swap.c ss.c rotate.c rr.c
SRC := $(addprefix $(SRC_DIR), $(SOURCE))
INCLUDES = push_swap.h
INC = $(addprefix $(INC_DIR), $(INCLUDES))
OBJ = $(SOURCE:.c=.o)

GREEN = \033[0;32m
RESET = \033[0m
RED = \033[0;31m
CYAN = \033[0;36m

all: lib $(NAME)

$(NAME): $(SRC) $(INC)
	@echo "$(GREEN)compiling...$(RESET)"
	@$(CC) -o $(NAME) srcs/push_swap.c $(SRC) -L $(LIB_DIR) -lft
	@echo "$(CYAN)DONE$(RESET)"

lib:
	@make -C $(LIB_DIR)

clean:
	@make -C $(LIB_DIR) clean
	@echo "$(RED)Object files removed$(RESET)"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(RED)Fully clean$(RESET)"

re:	fclean all

.PHONY: clean fclean
