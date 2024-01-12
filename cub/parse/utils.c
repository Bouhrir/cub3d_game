/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:13:16 by obouhrir          #+#    #+#             */
/*   Updated: 2023/10/05 16:55:33 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	north(t_data *utils, int i)
{
	char	**backup;

	backup = ft_split(utils->cub[i], ' ');
	if (!backup[1] || backup[2])
		error("please add correct path\n", NULL);
	utils->northpath = ft_strdup(backup[1]);
	free(utils->cub[i]);
	free_doublearr(backup);
}

void	west(t_data *utils, int i)
{
	char	**backup;

	backup = ft_split(utils->cub[i], ' ');
	if (!backup[1] || backup[2])
		error("please add correct path\n", NULL);
	utils->westpath = ft_strdup(backup[1]);
	free(utils->cub[i]);
	free_doublearr(backup);
}

void	east(t_data *utils, int i)
{
	char	**backup;

	backup = ft_split(utils->cub[i], ' ');
	if (!backup[1] || backup[2])
		error("please add correct path\n", NULL);
	utils->eastpath = ft_strdup(backup[1]);
	free(utils->cub[i]);
	free_doublearr(backup);
}

void	south(t_data *utils, int i)
{
	char	**backup;

	backup = ft_split(utils->cub[i], ' ');
	if (!backup[1] || backup[2])
		error("please add correct path\n", NULL);
	utils->southpath = ft_strdup(backup[1]);
	free(utils->cub[i]);
	free_doublearr(backup);
}

int	check_space(t_data *utils, int i, int j)
{
	if (utils->map[i][j + 1] == ' '
		|| utils->map[i][j - 1] == ' '
		|| utils->map[i + 1][j] == ' '
		|| utils->map[i - 1][j] == ' ')
		return (1);
	return (0);
}
