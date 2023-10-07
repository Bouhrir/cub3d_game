/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:12:29 by obouhrir          #+#    #+#             */
/*   Updated: 2023/10/05 11:54:20 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	up(t_data *map)
{
	map->player->tmpy += sin(map->player->view) * SPEED;
	map->player->tmpx += cos(map->player->view) * SPEED;
}

void	down(t_data *map)
{
	map->player->tmpy -= sin(map->player->view) * SPEED;
	map->player->tmpx -= cos(map->player->view) * SPEED;
}

void	right(t_data *map)
{
	map->player->tmpy -= sin(map->player->view + rad(90)) * SPEED;
	map->player->tmpx -= cos(map->player->view + rad(90)) * SPEED;
}

void	left(t_data *map)
{
	map->player->tmpy += sin(map->player->view + rad(90)) * SPEED;
	map->player->tmpx += cos(map->player->view + rad(90)) * SPEED;
}

void	hook(void *hook)
{
	t_data	*map;

	map = hook;
	map->player->tmpx = map->player->x;
	map->player->tmpy = map->player->y; 
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
		up(map);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		down(map);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		right(map);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		left(map);
	rotation(map);
	if (check_wall(map, map->player->tmpy, map->player->tmpx))
	{
		map->player->x = map->player->tmpx;
		map->player->y = map->player->tmpy;
		draw(map);
	}
}
