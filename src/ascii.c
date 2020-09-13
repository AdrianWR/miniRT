/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:25:40 by aroque            #+#    #+#             */
/*   Updated: 2020/09/11 23:23:47 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include "color.h"
#include <math.h>

/*
** Converts a string of characters to float. An arbitrary amount
** of white spaces can be added at string start, followed by any
** amount of '+' or '-' signals. An even number of '-' cancels each
** other. The conversion is then made while the following chars are
** numeric, stopping at any other char identified. If no numeric char
** os identified, the function returns 0 (zero).
*/

float			ft_atof(const char *str)
{
	float		n;
	float		d;
	int			i;
	int			signal;

	n = 0;
	d = 0.0;
	i = -1;
	signal = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			signal = -1;
	while (ft_isdigit(*str))
		n = n * 10 + (*str++ - '0');
	if (*str == '.' && *str++)
	{
		while (ft_isdigit(*str))
			d += (pow(10, i--) * (*str++ - '0'));
	}
	return ((n + d) * signal);
}

t_vector		atov(char *s)
{
	t_vector	v;
	char		**split;

	split = ft_split(s, ',');
	v.x = ft_atof(split[0]);
	v.y = ft_atof(split[1]);
	v.z = ft_atof(split[2]);
	free_array((void **)split);
	return (v);
}

/*
**	atoc(char *s): Get a string in the format "<r>,<g>,<b>"
**  and convert its information to a t_color data type.
**  Each one of these letters <r>, <g> and <b> represent
**  a value of the primitives red, green and blue, in the
**  range 0 to 255.
**
**	@s: string with color information
**
**	Return: t_color data if no erros found, -1 otherwise;
*/

t_color			atoc(char *s)
{
	t_color		color;
	char		**split;
	int			prim;
	unsigned	i;

	i = 0;
	color = 0x0;
	split = ft_split(s, ',');
	while (i < 3)
	{
		prim = ft_atoi(split[i]);
		if (prim < 0 || prim > 255)
			return (-1);
		color = (color << 8) | prim;
		i++;
	}
	free_array((void **)split);
	return (color);
}
