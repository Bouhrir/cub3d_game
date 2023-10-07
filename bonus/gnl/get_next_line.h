/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:44:36 by amahdiou          #+#    #+#             */
/*   Updated: 2023/10/04 18:27:03 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# include <unistd.h>
# include <stdlib.h>

int		lencount(char *str);
size_t	countlen(const char *str);
char	*box(char *one, char *two);
char	*gettheline(char *l);
char	*skiper(char *s);
char	*get_next_line(int fd);
char	*t_strchr(const char *s, int c);

#endif
