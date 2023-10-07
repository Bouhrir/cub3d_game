/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:55:00 by obouhrir          #+#    #+#             */
/*   Updated: 2023/10/05 17:28:48 by obouhrir         ###   ########.fr       */
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
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
	{
		map->player->view += rad(2);
		fixed_view(map);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
	{
		map->player->view -= rad(2);
		fixed_view(map);
	}
}
