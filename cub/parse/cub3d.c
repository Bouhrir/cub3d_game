/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:32:30 by amahdiou          #+#    #+#             */
/*   Updated: 2023/10/05 16:34:51 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse(int ac, char **av, t_data *utils, t_colors *rgb)
{
	int			fd;
	int			lines;

	if (ac != 2)
		error("Error : you must enter two args\n", NULL);
	f_name_check(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error("Error : No map file\n", NULL);
	close(fd);
	fillinfo(utils, av[1]);
	lines = count_lines_map(av[1]);
	fillmap(utils, av[1], lines);
	fillcoordinates(utils);
	map_checker(utils, lines);
	files_exist(utils);
	colors_data_checks(utils);
	fill_rgb(utils, rgb);
	check_rgb_floor(rgb);
	check_rgb_sky(rgb);
}
