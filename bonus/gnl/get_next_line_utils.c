/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:34:38 by amahdiou          #+#    #+#             */
/*   Updated: 2023/10/05 11:20:35 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	lencount(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

size_t	countlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*t_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= countlen(s))
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (0);
}

char	*box(char *one, char *two)
{
	char	*mix;
	int		i;
	int		j;
	int		m;

	i = 0;
	j = 0;
	m = 0;
	if (!one && !two)
		return (NULL);
	mix = malloc((countlen(one) + countlen(two)) + 1);
	if (!mix)
		return (NULL);
	while (one && one[i])
		mix[m++] = one[i++];
	while (two && two[j])
		mix[m++] = two[j++];
	mix[m] = '\0';
	free(one);
	return (mix);
}
