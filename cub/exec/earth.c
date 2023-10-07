/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   earth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:15:25 by obouhrir          #+#    #+#             */
/*   Updated: 2023/10/04 23:40:07 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ceiling(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(map->image, j, i,
				ft_pixel(map->rgb->sr, map->rgb->sg, map->rgb->sb, 255));
			j++;
		}
		i++;
	}
}

void	flooor(t_data *map)
{
	int	i;
	int	j;

	i = HEIGHT / 2;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(map->image, j, i,
				ft_pixel(map->rgb->fr, map->rgb->fg, map->rgb->fb, 255));
			j++;
		}
		i++;
	}
}
