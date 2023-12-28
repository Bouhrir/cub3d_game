/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:15:52 by obouhrir          #+#    #+#             */
/*   Updated: 2023/10/08 22:28:41 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initwall(t_data *map, t_help *norm, int check, double *wallhit)
{
	norm->dis = sqrt(pow(map->player->y - wallhit[1], 2)
			+ pow(map->player->x - wallhit[0], 2))
		* cos(map->player->view - map->player->ray);
	norm->wallhight = 72000 / norm->dis;
	norm->ystart = (HEIGHT / 2) - (norm->wallhight / 2);
	norm->i = norm->ystart;
	norm->yend = norm->i + norm->wallhight;
	if (check == 'H')
		norm->txtsize = map->pnj.no_txt->height / norm->wallhight;
	else if (check == 'V')
		norm->txtsize = map->pnj.we_txt->height / norm->wallhight;
}

void	render_wall(t_data *map, double *wallhit, int ray_i, int check)
{
	t_help	norm;

	norm.txtheight = 0.0;
	norm.txtsize = 0.0;
	initwall(map, &norm, check, wallhit);
	if (norm.i < 0)
	{
		norm.txtheight += norm.txtsize * abs(norm.i);
		norm.i = 0;
	}
	norm.i *= (norm.i > 0);
	while (norm.i < norm.yend)
	{
		if (check == 'V')
			norm.color = get_vercolor(map, norm.txtheight, wallhit);
		else if (check == 'H')
			norm.color = get_horcolor(map, norm.txtheight, wallhit);
		if (map->image && ray_i < (int)map->image->width
			&& norm.i < (int)map->image->height)
			mlx_put_pixel(map->image, ray_i, norm.i, norm.color);
		if (norm.i >= HEIGHT)
			break ;
		norm.i++;
		norm.txtheight += norm.txtsize;
	}
}

void	cub3d(t_data *map, int __unused ray_i)
{
	double	verwall[2];
	double	horwall[2];
	double	ver_dis;
	double	hor_dis;

	get_hor(map, horwall);
	get_ver(map, verwall);
	ver_dis = (pow(map->player->y - verwall[1], 2)
			+ pow(map->player->x - verwall[0], 2));
	hor_dis = (pow(map->player->y - horwall[1], 2)
			+ pow(map->player->x - horwall[0], 2));
	if (horwall[1] <= 0 || horwall[0] <= 0)
		render_wall(map, verwall, ray_i, 'V');
	else if (verwall[1] <= 0 || verwall[0] <= 0)
		render_wall(map, horwall, ray_i, 'H');
	else if (hor_dis > ver_dis)
		render_wall(map, verwall, ray_i, 'V');
	else
		render_wall(map, horwall, ray_i, 'H');
}
