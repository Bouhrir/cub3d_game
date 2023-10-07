/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:57:03 by obouhrir          #+#    #+#             */
/*   Updated: 2023/10/05 11:45:47 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_view(t_data *map, int y, int x)
{
	if (map->map[y][x] == 'N')
		map->player->view = (3 * M_PI) / 2;
	else if (map->map[y][x] == 'S')
		map->player->view = M_PI / 2;
	else if (map->map[y][x] == 'E')
		map->player->view = 0;
	else if (map->map[y][x] == 'W')
		map->player->view = M_PI;
}

void	get_player_position(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (ft_strchr("NSWE", map->map[i][j]))
			{
				map->player->x = j * PIXEL_SIZE;
				map->player->y = i * PIXEL_SIZE;
				player_view(map, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
	map->mouse.dx = -1;
	map->mouse.dy = -1;
	map->mouse.mtmp = -1;
}
