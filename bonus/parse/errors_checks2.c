/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_checks2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:19:50 by amahdiou          #+#    #+#             */
/*   Updated: 2023/10/05 16:34:42 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_rgb_sky(t_colors *rgb)
{
	if ((rgb->sr > 0 && rgb->sr > 255) || (rgb->sr < 0))
		error("Error :Wrong color input:\n", NULL);
	if ((rgb->sg > 0 && rgb->sg > 255) || (rgb->sg < 0))
		error("Error :Wrong color input:\n", NULL);
	if ((rgb->sb > 0 && rgb->sb > 255) || (rgb->sb < 0))
		error("Error :Wrong color input:\n", NULL);
}

void	check_rgb_floor(t_colors *rgb)
{
	if ((rgb->fr > 0 && rgb->fr > 255) || (rgb->fr < 0))
		error("Error :Wrong color input:\n", NULL);
	if ((rgb->fg > 0 && rgb->fg > 255) || (rgb->fg < 0))
		error("Error :Wrong color input:\n", NULL);
	if ((rgb->fb > 0 && rgb->fb > 255) || (rgb->fb < 0))
		error("Error :Wrong color input:\n", NULL);
}

void	map_checker(t_data *utils, int lines)
{
	int	i;
	int	j;

	i = -1;
	while (utils->map[++i])
	{
		j = -1;
		while (utils->map[i][++j])
		{
			if (utils->map[i][j] && (utils->map[i][j] == '0'
				|| utils->map[i][j] == 'N' || utils->map[i][j] == 'S'
					|| utils->map[i][j] == 'E' || utils->map[i][j] == 'W'))
			{
				if (j - 1 < 0 || i - 1 < 0 
					|| j + 2 >= (int)ft_strlen(utils->map[i])
					|| i + 1 >= lines || check_space(utils, i, j)
					|| j + 1 >= (int)ft_strlen(utils->map[i + 1])
					|| j > (int)ft_strlen(utils->map[i - 1]))
					error("Error :Invalid Map:\n", NULL);
			}
		}
	}
	map_checker2(utils);
}

void	map_checker2(t_data *utils)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (utils->map[i])
	{
		j = 0;
		while (utils->map[i][j])
		{
			if (utils->map[i][j] != 'N' && utils->map[i][j] != 'S'
			&& utils->map[i][j] != 'E' && utils->map[i][j] != 'W'
			&& utils->map[i][j] != '0' && utils->map[i][j] != '1'
			&& utils->map[i][j] != '\n' && utils->map[i][j] != ' ')
				error("Error :Invalid Map:\n", NULL);
			j++;
		}
		i++;
	}
	player_checks(utils);
}

void	player_checks(t_data *utils)
{
	int	i;
	int	j;

	i = 0;
	utils->p = 0;
	while (utils->map[i])
	{
		j = 0;
		while (utils->map[i][j])
		{
			if (utils->map[i][j] == 'N' || utils->map[i][j] == 'S' 
			|| utils->map[i][j] == 'E' || utils->map[i][j] == 'W')
				utils->p++;
			j++;
		}
		i++;
	}
	if (utils->p != 1)
		error("Error :Map must containe one player:\n", NULL);
}
