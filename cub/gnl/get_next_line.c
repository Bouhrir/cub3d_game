/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:43:57 by amahdiou          #+#    #+#             */
/*   Updated: 2023/10/05 14:23:01 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*gettheline(char *l)
{
	char	*p;
	int		i;

	i = 0;
	if (!l[i])
		return (NULL);
	p = malloc(lencount(l) + 2);
	while (l[i] && l[i] != '\n')
	{
		p[i] = l[i];
		i++;
	}
	if (l[i] == '\n')
	{
		p[i] = l[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*skiper(char *s)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (!s[i] || (s[i] == '\n' && s[i] == '\0'))
	{
		free(s);
		return (NULL);
	}
	i++;
	new = malloc ((countlen(s) - i) + 1);
	if (!new)
		return (NULL);
	while (s[i])
		new[j++] = s[i++];
	new[j] = '\0';
	free(s);
	return (new);
}

char	*readit(int fd, char *getit)
{
	char		*stock;
	int			i;

	stock = malloc (BUFFER_SIZE + 1);
	if (!stock)
		return (0);
	i = 1;
	while (i != 0)
	{
		i = read(fd, stock, BUFFER_SIZE);
		if (i == -1)
		{
			free(getit);
			free(stock);
			return (NULL);
		}
		stock[i] = '\0';
		getit = box(getit, stock);
		if (t_strchr(getit, '\n'))
			break ;
	}
	free(stock);
	return (getit);
}

char	*get_next_line(int fd)
{
	char		*newline;
	static char	*getit;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	getit = readit(fd, getit);
	if (!getit)
		return (NULL);
	newline = gettheline(getit);
	getit = skiper(getit);
	return (newline);
}
