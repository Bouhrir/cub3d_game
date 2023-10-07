# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 21:01:35 by obouhrir          #+#    #+#              #
#    Updated: 2023/10/05 21:01:36 by obouhrir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

all: mand 

mand: 
	make -C cub
	cp cub/cub3d ./

bonus:
	make -C bonus
	cp bonus/cub3d_bonus ./

clean:
	make clean -C cub
	make clean -C bonus

fclean:
	make fclean -C cub
	make fclean -C bonus
	rm -f cub3d
	rm -f cub3d_bonus

re: fclean all

.PHONY: mand bonus clean fclean