# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 21:36:50 by cwitting          #+#    #+#              #
#    Updated: 2019/12/05 22:05:51 by cwitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -g
FLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft/
SRC_DIR = ./srcs/
INC_DIR = ./includes/
OBJ_DIR = ./obj

SRC := $(shell ls $(SRC_DIR))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

GREEN = \033[0;32m
RESET = \033[0m
RED = \033[0;31m
CYAN = \033[0;36m

all:$(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(CYAN)libftprintf.a created$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) $(SRCS) -I $(INC_DIR) -I $(LIB_DIR) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean
