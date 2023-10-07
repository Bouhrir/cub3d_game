/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_checks3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:28:49 by amahdiou          #+#    #+#             */
/*   Updated: 2023/10/05 19:15:41 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error(char *str, t_data __unused *utils)
{
	if (utils)
		freeall(utils);
	while (*str)
		write(2, str++, 1);
	exit(0);
}

void	fill_f(char **backup, t_colors *rgb)
{
	if (backup[0] && backup[1] && backup[2] && !backup[3])
	{
		rgb->fr = ft_atoi(backup[0]);
		rgb->fg = ft_atoi(backup[1]);
		rgb->fb = ft_atoi(backup[2]);
	}
	else
	{
		free_doublearr(backup);
		error("wrong F rgb", NULL);
	}
}

void	fill_s(char **backup, t_colors *rgb)
{
	if (backup[0] && backup[1] && backup[2] && !backup[3])
	{
		rgb->sr = ft_atoi(backup[0]);
		rgb->sg = ft_atoi(backup[1]);
		rgb->sb = ft_atoi(backup[2]);
	}
	else
	{
		free_doublearr(backup);
		error("wrong C rgb", NULL);
	}
}

int	ft_nbrlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	rgbs_checks(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_nbrlen(ft_atoi(s[i])) > 3)
			error("Error:Wrongs rgb:\n", NULL);
		i++;
	}
}
