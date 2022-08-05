# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 21:13:32 by jayoon            #+#    #+#              #
#    Updated: 2022/08/05 12:43:47 by youngcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
DEBUG		= -g3 -fsanitize=address

SRCS_DIR	= ./srcs/
OBJS_DIR	= ./objs/
INCS_DIR 	= ./incs/
LIBS_DIR	= ./libs/
LIBFT_DIR	= $(LIBS_DIR)libft/
LIBMLX_DIR	= $(LIBS_DIR)mlx/

LIBFT_NAME	= libft.a
LIBMLX_NAME	= libmlx.a

LIBMLX_FLAGS	= -L$(LIBMLX_DIR) -lmlx -framework OpenGL -framework AppKit
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

INCS_FLAGS	= -I $(LIBFT_DIR) -I $(LIBMLX_DIR) -I $(INCS_DIR)

SRCS_NAME	= check_file_name.c \
				check_inner_and_count_characters.c \
				check_map.c \
				command_to_move_player.c \
				draw_map.c \
				error.c \
				init_map_row_and_col.c \
				init_mlx_info.c \
				main.c \
				callback.c \
				parse.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS_NAME:%.c=%.o))
LIBFT		= $(LIBFT_DIR)$(LIBFT_NAME)
LIBMLX		= $(LIBMLX_DIR)$(LIBMLX_NAME)

ifdef DEBUG_FLAG
	CFLAGS += $(DEBUG)
endif

all: $(NAME)
debug: 
	$(MAKE) DEBUG_FLAG=1
clean:
	rm -rf $(OBJS_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBMLX_DIR)
fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
re: fclean
	make all
.PHONY: all clean fclean re debug

$(NAME): $(LIBMLX) $(LIBFT) $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(LIBMLX_FLAGS) $(LIBFT_FLAGS) $(OBJS) -o $@

$(LIBMLX) :
	make -C $(LIBMLX_DIR)

$(LIBFT) :
	make -C $(LIBFT_DIR)
	
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCS_FLAGS) -c $< -o $@

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)
