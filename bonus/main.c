/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:15:15 by obouhrir          #+#    #+#             */
/*   Updated: 2024/01/09 21:26:34 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(void *mlx)
{
	t_data	*map;
	float	i;
	float	inc;

	map = mlx;
	ceiling(map);
	flooor(map);
	i = 0;
	map->player->ray = map->player->view - (rad(FOV / 2));
	inc = rad((float)FOV) / WIDTH;
	while (i < WIDTH)
	{
		cub3d(map, i);
		map->player->ray += inc;
		i++;
	}
	mini_map(map);
}

void	init(t_data *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", 1);
	map->image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	draw(map);
	mlx_image_to_window(map->mlx, map->image, 0, 0);
}

void	texture(t_data *map)
{
	map->pnj.no_txt = NULL;
	map->pnj.so_txt = NULL;
	map->pnj.ea_txt = NULL;
	map->pnj.we_txt = NULL;
	map->pnj.no_txt = mlx_load_png(map->northpath);
	if (!map->pnj.no_txt)
		error("faild png", NULL);
	map->pnj.so_txt = mlx_load_png(map->southpath);
	if (!map->pnj.so_txt)
		error("faild png", NULL);
	map->pnj.ea_txt = mlx_load_png(map->eastpath);
	if (!map->pnj.ea_txt)
		error("faild png", NULL);
	map->pnj.we_txt = mlx_load_png(map->westpath);
	if (!map->pnj.we_txt)
		error("faild png", NULL);
}

int	main(int ac, char **av)
{
	t_data		map;
	t_colors	rgb;
	pid_t		pid;

	ft_bzero(&map, 0);
	ft_bzero(&rgb, 0);
	parse(ac, av, &map, &rgb);
	pid = fork();
	if (!pid)
		system("afplay zalij1.mp3");
	map.rgb = &rgb;
	map.player = malloc(sizeof(t_player));
	map_length(&map);
	texture(&map);
	get_player_position(&map);
	init(&map);
	mlx_loop_hook(map.mlx, hook, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	system("pkill afplay");
	system("pkill cub3d");
	wait(NULL);
}
