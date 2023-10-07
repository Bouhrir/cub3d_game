/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 22:43:55 by amahdiou          #+#    #+#             */
/*   Updated: 2023/10/05 18:24:34 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	checktab(t_data *utils)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!utils->map[i])
		error("Wrong data\n", NULL);
	while (utils->map[i])
	{
		j = 0;
		while (utils->map[i][j])
		{
			if (utils->map[i][j] == '\t')
				error("Error :Found TAB:\n", NULL);
			j++;
		}
		i++;
	}
}

void	checktab2(t_data *utils)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!utils->cub[i])
		error("Wrong data\n", NULL);
	while (utils->cub[i])
	{
		j = 0;
		while (utils->cub[i][j])
		{
			if (utils->cub[i][j] == '\t')
				error("Error :Found TAB:\n", NULL);
			j++;
		}
		i++;
	}
}

void	checknl(t_data *utils)
{
	int	i;

	i = 0;
	while (utils->map[i])
	{
		if (!is_not_empty(utils->map[i]))
			error("Error :Empty line:\n", NULL);
		i++;
	}
}

void	colors_data_checks(t_data *utils)
{
	int	i;

	i = 0;
	while (utils->florcolor[i])
	{
		if (utils->florcolor[i] == ',' && utils->florcolor[i + 1] == ',')
			error("Error :Wrong colors data:\n", NULL);
		i++;
	}
	i = 0;
	while (utils->skycolor[i])
	{
		if (utils->skycolor[i] == ',' && utils->skycolor[i + 1] == ',')
			error("Error :Wrong colors data:\n", NULL);
		i++;
	}
}

// void	colors_data_sky(t_data *utils)
// {
// 	char		**backup;
// 	int			i;
// 	int			j;

// 	i = 0;
// 	j = 0;
// 	backup = ft_split(utils->skycolor, ',');
// 	while (backup[i])
// 	{
// 		if (ft_strlen(backup[i]) > 3)
// 			error("Error :Colors not found:\n", utils);
// 		i++;
// 	}
// }

// void	colors_data_floor(t_data *utils)
// {
// 	char		**backup;
// 	int			i;
// 	int			j;

// 	i = 0;
// 	j = 0;
// 	backup = ft_split(utils->florcolor, ',');
// 	while (backup[i])
// 	{
// 		if (ft_strlen(backup[i]) > 3)
// 			error("Error :Colors not found:\n", utils);
// 		i++;
// 	}
// }
