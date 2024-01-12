# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 23:32:27 by obouhrir          #+#    #+#              #
#    Updated: 2024/01/12 10:29:06 by obouhrir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEB   = cub3d_bonus
CC      = cc
CFLAGS  = -Wall -Werror -Wextra #-fsanitize=address -g3
MLX 	= -Wunreachable-code -O3
# MLX    = -lmlx -framework OpenGL -framework AppKit
SRC     =  main.c \
			parse/cub3d.c parse/cub3dutils.c parse/errors_checks.c \
			 parse/errors_checks2.c parse/errors_checks3.c parse/files_exist.c \
			 parse/fill_data.c exec/raycast.c exec/utils.c exec/render.c exec/player.c \
			 exec/event_hooks.c exec/earth.c exec/get_pixels.c exec/event_hooks1.c parse/utils.c \
			 exec/minimap.c
GNL = ./gnl/get_next_line.a
LIBMLX	= /Users/obouhrir/MLX42
HEADERS	= -I ./include -I ../include
LIBS	= ../libmlx42.a -Iinclude -lglfw 
 

OBJDIR  = objects
OBJ     = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
LIBFT   = ./libft/libft.a

# Colours
GREEN   = "\033[32m"
GREY    = "\033[30m"
RED     = "\033[31m"

.SILENT:
# Compile all
bonus : all libmlx $(NAMEB)
# libmlx  :
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAMEB) : $(OBJ) $(LIBFT) $(PRINTF) $(GNL)
	@$(CC) $(CFLAGS) $(MLX) $(OBJ) $(LIBFT) $(LIBS) $(GNL) $(HEADERS) -o $(NAMEB)
	@echo "\033[1;32mSuccessfully compiled $(NAMEB)!\033[0m"

# Compile object files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(MLX) -c $< -o $@

$(LIBFT):
	@make -C libft

$(GNL):
	@make -C gnl

# Clean up
clean :
	@echo "\033[1;31mCleaning up...!\033[0m"
	@make -C libft clean
	@make -C gnl clean
	@rm -rf $(OBJDIR)

fclean : clean
	@make -C libft fclean
	@make -C gnl fclean
	@rm -f $(NAMEB)

re : fclean bonus

.PHONY: all clean fclean re bonus libmlx
