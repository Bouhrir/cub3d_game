/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:03:46 by amahdiou          #+#    #+#             */
/*   Updated: 2023/10/05 19:19:27 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fillinfo(t_data *utils, char *s)
{
	int		j;
	int		fd;
	char	*backup;

	j = 0;
	fd = open(s, O_RDONLY);
	utils->cub = malloc(sizeof(char *) * (6 + 1));
	while (1)
	{
		backup = get_next_line(fd);
		if (!backup)
		{
			free(backup);
			break ;
		}
		if (is_not_empty(backup) && j < 6)
		{
			utils->cub[j] = ft_strtrim(backup, " \n");
			j++;
		}
		free(backup);
	}
	close(fd);
	utils->cub[j] = NULL;
	checktab2(utils);
}

char	*check(char *str)
{
	int		i;
	int		j; 
	char	*res;

	j = 0;
	i = 0;
	res = malloc(ft_strlen(str));
	while (str[i])
	{
		if (str[i] == 'F' || str[i] == 'C')
			i++;
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

void	fillcoordinates(t_data *utils)
{
	int	i;

	i = -1;
	while (utils->cub[++i])
	{
		if (ft_strncmp(utils->cub[i], "NO", 2) == 0)
			north(utils, i);
		else if (ft_strncmp(utils->cub[i], "WE", 2) == 0
			&& (utils->cub[i][2] && utils->cub[i][2] == ' '))
			west(utils, i);
		else if (ft_strncmp(utils->cub[i], "SO", 2) == 0 
			&& (utils->cub[i][2] && utils->cub[i][2] == ' '))
			south(utils, i);
		else if (ft_strncmp(utils->cub[i], "EA", 2) == 0
			&& (utils->cub[i][2] && utils->cub[i][2] == ' '))
			east(utils, i);
		else if (ft_strncmp(utils->cub[i], "F", 1) == 0)
			utils->florcolor = check(utils->cub[i]);
		else if (ft_strncmp(utils->cub[i], "C", 1) == 0)
			utils->skycolor = check(utils->cub[i]);
		else
			error("Missing data\n", NULL);
	}
}

void	fillmap(t_data *utils, char *s, int lines)
{
	t_help	norm;

	norm.j = 0;
	norm.counter = 0;
	norm.fd = open(s, O_RDONLY);
	utils->map = malloc(sizeof(char *) * (lines + 1));
	while (1)
	{
		norm.backup = get_next_line(norm.fd);
		if (!norm.backup)
		{
			free(norm.backup);
			break ;
		}
		if (is_not_empty(norm.backup))
			norm.j++;
		if (norm.j > 6)
			utils->map[norm.counter++] = ft_strdup(norm.backup);
		free(norm.backup);
	}
	utils->map[norm.counter] = NULL;
	close(norm.fd);
	checktab(utils);
}

void	fill_rgb(t_data *utils, t_colors *rgb)
{
	char		**backup;

	backup = ft_split(utils->florcolor, ',');
	if (backup[3] || !backup[0] || !backup[1] || !backup[2])
		error("incompatible data\n", NULL);
	rgbs_checks(backup);
	rgb->fr = ft_atoi(backup[0]);
	rgb->fg = ft_atoi(backup[1]);
	rgb->fb = ft_atoi(backup[2]);
	free_doublearr(backup);
	backup = ft_split(utils->skycolor, ',');
	if (backup[3] || !backup[0] || !backup[1] || !backup[2])
		error("incompatible data\n", NULL);
	rgbs_checks(backup);
	rgb->sr = ft_atoi(backup[0]);
	rgb->sg = ft_atoi(backup[1]);
	rgb->sb = ft_atoi(backup[2]);
	free_doublearr(backup);
}
