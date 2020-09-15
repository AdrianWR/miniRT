/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:25:40 by aroque            #+#    #+#             */
/*   Updated: 2020/09/15 11:23:54 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include "color.h"
#include "errcode.h"
#include "scene.h"
#include <math.h>


static bool		invalid_number(const char *arg)
{
	bool 		inv;
	int			i;

	i = -1;
	inv = false;
	while (arg[++i])
	{
		if (i == 0)
			inv |= (!ft_isdigit(arg[i]) & (arg[i] != '+') & (arg[i] != '-'));
		else
			inv |= (!ft_isdigit(arg[i]) & (arg[i] != '.'));
	}
	return (inv);
}

/*
** Converts a string of characters to float. An arbitrary amount
** of white spaces can be added at string start, followed by any
** amount of '+' or '-' signals. An even number of '-' cancels each
** other. The conversion is then made while the following chars are
** numeric, stopping at any other char identified. If no numeric char
** os identified, the function returns 0 (zero).
*/

float			ft_atof(const char *str, int *errcode)
{
	float		n;
	float		d;
	int			i;
	int			signal;

	n = 0;
	d = 0.0;
	i = -1;
	signal = 1;
	if (invalid_number(str))
		*errcode = EINVID;
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

t_vector		ft_atov(char *s, int *errcode)
{
	t_vector	v;
	char		**split;

	split = ft_split(s, ',');
	if (strarray_len(split) != 3 && (*errcode = EBADVEC))
		v = vector(0, 0, 0);
	else
	{
		v.x = ft_atof(split[0], errcode);
		v.y = ft_atof(split[1], errcode);
		v.z = ft_atof(split[2], errcode);
	}
	free_array((void **)split);
	return (v);
}

/*
**	ft_atoc(char *s): Get a string in the format "<r>,<g>,<b>"
**  and convert its information to a t_color data type.
**  Each one of these letters <r>, <g> and <b> represent
**  a value of the primitives red, green and blue, in the
**  range 0 to 255.
**
**	@s: string with color information
**
**	Return: t_color data if no erros found, -1 otherwise;
*/

t_color			ft_atoc(char *s, int *errcode)
{
	t_color		color;
	char		**split;
	int			prim;
	unsigned	i;

	i = 0;
	color = 0x0;
	split = ft_split(s, ',');
	if (strarray_len(split) != 3)
		*errcode = EBADCLR;
	else
	{
		while (i < 3)
		{
			if (invalid_number(split[i]))
				*errcode = EINVID;
			prim = ft_atoi(split[i]);
			if (prim < 0 || prim > 0xFF)
				*errcode = EOURCLR;
			color = (color << 8) | prim;
			i++;
		}
	}
	free_array((void **)split);
	return (color);
}
