/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:19:37 by obouhrir          #+#    #+#             */
/*   Updated: 2023/10/04 23:44:25 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	hor_steps(t_data *map)
{
	map->hor.yinc = ((int)(map->player->y / PIXEL_SIZE)) * PIXEL_SIZE;
	if (sin(map->player->ray) > 0)
		map->hor.yinc += PIXEL_SIZE;
	map->hor.xinc = (map->player->y - map->hor.yinc) / tan(map->player->ray);
	if (cos(map->player->ray) < 0)
		map->hor.xinc = map->player->x - fabs(map->hor.xinc);
	else
		map->hor.xinc = map->player->x + fabs(map->hor.xinc);
	map->hor.ystep = PIXEL_SIZE;
	if (sin(map->player->ray) < 0)
		map->hor.ystep *= -1;
	map->hor.xstep = PIXEL_SIZE / tan(map->player->ray);
	if ((cos(map->player->ray) < 0 && map->hor.xstep > 0)
		|| (cos(map->player->ray) > 0 && map->hor.xstep < 0))
		map->hor.xstep *= -1;
	map->hor.x_hor = map->hor.xinc;
	map->hor.y_hor = map->hor.yinc;
	if (sin(map->player->ray) < 0)
		map->hor.y_hor -= 0.001;
}

void	ver_steps(t_data *map)
{
	map->ver.xinc = floor(map->player->x / PIXEL_SIZE) * PIXEL_SIZE;
	if (cos(map->player->ray) > 0)
		map->ver.xinc += PIXEL_SIZE;
	map->ver.yinc = (map->player->x - map->ver.xinc) * tan(map->player->ray);
	if (sin(map->player->ray) > 0)
		map->ver.yinc = map->player->y + fabs(map->ver.yinc);
	else
		map->ver.yinc = map->player->y - fabs(map->ver.yinc);
	map->ver.xstep = PIXEL_SIZE;
	if (cos(map->player->ray) < 0)
		map->ver.xstep *= -1;
	map->ver.ystep = PIXEL_SIZE * tan(map->player->ray);
	if ((sin(map->player->ray) > 0 && map->ver.ystep < 0)
		|| (sin(map->player->ray) < 0 && map->ver.ystep > 0))
		map->ver.ystep *= -1;
	map->ver.x_ver = map->ver.xinc;
	map->ver.y_ver = map->ver.yinc;
	if (cos(map->player->ray) < 0)
		map->ver.x_ver -= 0.001;
}

void	get_hor(t_data *map, double *wall)
{
	hor_steps(map);
	while (1)
	{
		if (map->hor.x_hor >= (PIXEL_SIZE * map->width)
			|| map->hor.x_hor < 0
			|| map->hor.y_hor >= (PIXEL_SIZE * map->height)
			|| map->hor.y_hor < 0)
		{
			wall[0] = -1;
			wall[1] = -1;
			break ;
		}
		if (check_hit(map, map->hor.y_hor, map->hor.x_hor))
		{
			wall[0] = map->hor.x_hor;
			wall[1] = map->hor.y_hor;
			break ;
		}
		map->hor.x_hor += map->hor.xstep;
		map->hor.y_hor += map->hor.ystep;
	}
}

void	get_ver(t_data	*map, double *wall)
{
	ver_steps(map);
	while (1)
	{
		if (map->ver.x_ver >= (PIXEL_SIZE * map->width)
			|| map->ver.x_ver < 0
			|| map->ver.y_ver >= (PIXEL_SIZE * map->height)
			|| map->ver.y_ver < 0)
		{
			wall[0] = -1;
			wall[1] = -1;
			break ;
		}
		if (check_hit(map, map->ver.y_ver, map->ver.x_ver))
		{
			wall[0] = map->ver.x_ver;
			wall[1] = map->ver.y_ver;
			break ;
		}
		map->ver.x_ver += map->ver.xstep;
		map->ver.y_ver += map->ver.ystep;
	}
}
