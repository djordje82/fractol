# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 10:38:41 by dodordev          #+#    #+#              #
#    Updated: 2024/08/13 15:29:18 by dodordev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_DIR = ./minilibx
LINK :=	-L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm
LIBMLX :=		$(MLX_DIR)/libmlx.a
SRC = main.c \
		input_utils.c \
		utils.c \
		string_utils.c \
		events_hooks.c \
		render.c \
		math_utils.c 
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all:	$(LIBMLX) $(NAME)

$(LIBMLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Cloning MiniLibX repository..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR) >/dev/null 2>&1; \
	fi
	@echo "Compiling MiniLibX..."
	@make -s -C $(MLX_DIR) >/dev/null 2>&1;

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LINK) -o $(NAME)


clean:
		rm -rf $(OBJ_DIR)

fclean:	clean
		rm -fr $(NAME) minilibx

re:	fclean all

.PHONY: all clean fclean re
