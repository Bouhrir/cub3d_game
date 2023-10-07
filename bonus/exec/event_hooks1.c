/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:55:00 by obouhrir          #+#    #+#             */
/*   Updated: 2023/10/05 12:17:07 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fixed_view(t_data *map)
{
	if (map->player->view < 0)
		map->player->view += (2 * M_PI);
	if (map->player->view >= (2 * M_PI))
		map->player->view -= (2 * M_PI);
}

void	rotation(t_data *map)
{
	mlx_get_mouse_pos(map->mlx, &map->mouse.dx, &map->mouse.dy);
	if (map->mouse.dx <= WIDTH && map->mouse.dx >= 0
		&& map->mouse.dx > map->mouse.mtmp)
	{
		map->player->view += rad(1);
		fixed_view(map);
		map->mouse.mtmp = map->mouse.dx;
	}
	if (map->mouse.dx <= WIDTH && map->mouse.dx >= 0
		&& map->mouse.dx < map->mouse.mtmp)
	{
		map->player->view -= rad(1);
		fixed_view(map);
		map->mouse.mtmp = map->mouse.dx;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
	{
		map->player->view += rad(3);
		fixed_view(map);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
	{
		map->player->view -= rad(3);
		fixed_view(map);
	}
}
