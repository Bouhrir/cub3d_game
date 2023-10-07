/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3dutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:56:59 by amahdiou          #+#    #+#             */
/*   Updated: 2023/10/05 18:43:46 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_not_empty(char *s)
{
	char	*backup;

	backup = ft_strtrim(s, " \t\n");
	if (backup[0] != '\0')
	{
		free(backup);
		return (1);
	}
	free(backup);
	return (0);
}

int	count_lines_map(char *s)
{
	int		j;
	int		fd;
	int		counter;
	char	*backup;

	j = 0;
	counter = 0;
	fd = open(s, O_RDONLY);
	while (1)
	{
		backup = get_next_line(fd);
		if (!backup)
		{
			free(backup);
			break ;
		}
		if (is_not_empty(backup))
			j++;
		if (j > 6)
			counter++;
		if (backup)
			free(backup);
	}
	close(fd);
	return (counter);
}

void	freeall(t_data *utils)
{
	if (utils->map)
		free_doublearr(utils->map);
	if (utils->cub)
		free_doublearr(utils->cub);
}

void	free_doublearr(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}
