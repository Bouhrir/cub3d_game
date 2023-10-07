/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:49:18 by obouhrir          #+#    #+#             */
/*   Updated: 2022/10/20 11:25:23 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cuter_count(int j, char const *cut)
{
	int	i;

	i = 0;
	while (cut[i])
	{
		if (j == cut[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	in;
	size_t	out;
	size_t	i;
	char	*l;

	in = 0;
	i = 0;
	if (!s)
		return (0);
	out = ft_strlen(s);
	while (cuter_count(s[in], set) && s[in])
		in++;
	if (in == out)
		return (ft_strdup(""));
	while (cuter_count(s[out - 1], set) && in < out)
		out--;
	l = malloc(sizeof(char) * out - in + 1);
	if (!l)
		return (0);
	while (out > in)
		l[i++] = s[in++];
	l[i] = '\0';
	return (l);
}
