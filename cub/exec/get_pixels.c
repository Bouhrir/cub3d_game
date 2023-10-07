/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:18:18 by obouhrir          #+#    #+#             */
/*   Updated: 2023/10/04 23:44:10 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_position(double pos, int txtwidth)
{
	int	position;

	position = ((pos / PIXEL_SIZE) - (int)(pos / PIXEL_SIZE)) * txtwidth;
	return (position);
}

int32_t	get_pixel(mlx_texture_t *txt, int x, int y)
{
	int		pix;
	int32_t	r; 
	int32_t	g; 
	int32_t	b; 
	int32_t	a;

	r = 0;
	g = 0;
	b = 0;
	a = 0;
	if (x >= 0 && x < (int)txt->width && y >= 0 && y < (int)txt->height)
	{
		pix = ((y * txt->bytes_per_pixel)
				* txt->width + (x * txt->bytes_per_pixel));
		r = txt->pixels[pix++];
		g = txt->pixels[pix++];
		b = txt->pixels[pix++];
		a = txt->pixels[pix];
	}
	return (ft_pixel(r, g, b, a));
}

uint32_t	get_vercolor(t_data *map, double txthight, double *hitwall)
{
	uint32_t	color;

	if (cos(map->player->ray) > 0)
		color = get_pixel(map->pnj.ea_txt,
				get_position(hitwall[1], map->pnj.ea_txt->width), txthight);
	else 
		color = get_pixel(map->pnj.we_txt,
				get_position(hitwall[1], map->pnj.we_txt->width), txthight);
	return (color);
}

uint32_t	get_horcolor(t_data *map, double txthight, double *hitwall)
{
	uint32_t	color;

	if (sin(map->player->ray) > 0)
		color = get_pixel(map->pnj.so_txt,
				get_position(hitwall[0], map->pnj.so_txt->width), txthight);
	else 
		color = get_pixel(map->pnj.no_txt,
				get_position(hitwall[0], map->pnj.no_txt->width), txthight);
	return (color);
}
