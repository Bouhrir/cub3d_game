/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:27:05 by obouhrir          #+#    #+#             */
/*   Updated: 2023/10/05 11:28:52 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_player(t_data *map, int y, int x, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < M_PIXEL_SIZE_P)
	{
		j = 0;
		while (j < M_PIXEL_SIZE_P)
		{
			mlx_put_pixel(map->image, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_squares(t_data *map, int y, int x, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < M_PIXEL_SIZE)
	{
		j = 0;
		while (j < M_PIXEL_SIZE)
		{
			mlx_put_pixel(map->image, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	mini_map(t_data *map)
{
	int		y;
	int		x;
	int		color;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == '1')
			{
				color = ft_pixel(255, 255, 255, 255);
				draw_squares(map, y * M_PIXEL_SIZE, x * M_PIXEL_SIZE, color);
			}
			if (map->map[y][x] == '0' || ft_strchr("NSWE", map->map[y][x]))
			{
				color = ft_pixel(0, 0, 0, 255);
				draw_squares(map, y * M_PIXEL_SIZE, x * M_PIXEL_SIZE, color);
			}
		}
	}
	draw_player(map, (map->player->y / PIXEL_SIZE) * M_PIXEL_SIZE,
		(map->player->x / PIXEL_SIZE)
		* M_PIXEL_SIZE, ft_pixel(255, 0, 0, 255));
}
