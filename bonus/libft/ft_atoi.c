/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:44:28 by obouhrir          #+#    #+#             */
/*   Updated: 2022/10/20 10:55:06 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char	*str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		error("Error:wrong input rgb:\n", NULL);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}
