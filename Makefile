# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 17:43:20 by youngcho          #+#    #+#              #
#    Updated: 2022/07/29 19:03:58 by youngcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./include/
LIB_DIR = ./lib/
LIBMLX_DIR = $(LIB_DIR)mlx/
LIBFT_DIR = $(LIB_DIR)libft/

LIBFT_NAME = libft.a
MLX_NAME = libmlx.a

LIBMLX_FLAGS = -L$(LIBMLX_DIR) -lmlx -framework OpenGL -framework AppKit
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
INC_FLAGS = -I $(LIBFT_DIR)/inc/ -I $(LIBMLX_DIR) -I ./include/

SRCS_NAME = main.c \
			read_map.c \
			callback.c \
			ready_for_game.c

SRCS = $(addprefix $(SRC_DIR), $(SRCS_NAME))
OBJS = $(addprefix $(OBJ_DIR), $(SRCS_NAME:%.c=%.o))
LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)
LIBMLX = $(LIBMLX_DIR)$(MLX_NAME)

.PHONY :
	all clean fclean re
all : $(NAME)
clean :
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBMLX_DIR)
	make clean -C $(LIBFT_DIR)
fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
re : fclean
	make all

$(NAME) : $(LIBMLX) $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBMLX_FLAGS) $(LIBFT_FLAGS) -o $@

$(LIBMLX) :
	make -C $(LIBMLX_DIR)

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@