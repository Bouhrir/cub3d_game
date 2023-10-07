/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_exist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:04:18 by amahdiou          #+#    #+#             */
/*   Updated: 2023/10/05 16:25:02 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	f_name_check(char *name)
{
	int	i;

	i = ft_strlen(name) - 1;
	if (name[i] != 'b')
		error("Error : file name \n", NULL);
	if (name[i - 1] != 'u')
		error("Error : file name \n", NULL);
	if (name[i - 2] != 'c')
		error("Error : file name \n", NULL);
}

void	files_exist(t_data *utils)
{
	int	fd;

	fd = open(utils->northpath, O_RDONLY);
	if (fd == -1)
		error("Error : No Path file\n", NULL);
	close(fd);
	fd = open(utils->southpath, O_RDONLY);
	if (fd == -1)
		error("Error : No Path file\n", NULL);
	close(fd);
	files_exist2(utils);
}

void	files_exist2(t_data *utils)
{
	int	fd;

	fd = open(utils->westpath, O_RDONLY);
	if (fd == -1)
		error("Error : No Path file\n", NULL);
	close(fd);
	fd = open(utils->eastpath, O_RDONLY);
	if (fd == -1)
		error("Error : No Path file\n", NULL);
	close(fd);
}
