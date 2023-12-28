/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:30:50 by obouhrir          #+#    #+#             */
/*   Updated: 2023/10/09 17:30:45 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_wall(t_data *map, double newy, double newx)
{
	if (map->map[(int)((map->player->y) / PIXEL_SIZE)] \
		[(int)(newx / PIXEL_SIZE)] != '1'
		&& map->map[(int)(newy / PIXEL_SIZE)] \
			[(int)((map->player->x) / PIXEL_SIZE)] != '1'
		&& map->map[(int)(newy / PIXEL_SIZE)][(int)(newx / PIXEL_SIZE)] != '1')
		return (1);
	return (0);
}

int	check_hit(t_data *map, double y, double x)
{
	if ((int)y / PIXEL_SIZE < map->height
		&& (int)x / PIXEL_SIZE < (int)ft_strlen(map->map[(int)y / PIXEL_SIZE])
		&& map->map[(int) y / PIXEL_SIZE][(int) x / PIXEL_SIZE] == '1')
		return (1);
	return (0);
}

double	rad(int angle)
{
	return (angle * (M_PI / 180));
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	map_length(t_data *map)
{
	map->width = 0;
	map->height = 0;
	while (map->map[map->height])
		map->height++;
	map->width = ft_strlen(map->map[0]);
}
