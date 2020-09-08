/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:25:40 by aroque            #+#    #+#             */
/*   Updated: 2020/09/08 09:23:54 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "color.h"

/*
**	Check if a char is ASCII space, tabulation, carriage return
**  or another space character as defined in isspace(3).
*/

//static int	ft_isspace(char str)
//{
//	if (str == 0x20 || (str >= 0x09 && str <= 0x0d))
//		return (1);
//	return (0);
//}

/*
** Converts a string of characters to integer. An arbitrary amount
** of white spaces can be added at string start, followed by any
** amount of '+' or '-' signals. An even number of '-' cancels each
** other. The conversion is then made while the following chars are
** numeric, stopping at any other char identified. If no numeric char
** os identified, the function returns 0 (zero).
*/

//int			ft_atof(const char *str)
//{
//	int n;
//	int aux;
//	int signal;
//
//	
//	n = ft_atoi(str);
//	aux = 0;
//	signal = -1;
//	while (*str >= '0' && *str <= '9')
//	{
//		n = n * 10 - (*str++ - '0');
//		if (aux < n)
//		{
//			if (signal < 0)
//				return (-1);
//			return (0);
//		}
//		aux = n;
//	}
//	return (n * signal);
//}

static void 	free_array(void **array)
{
	unsigned 	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	////while (*array)
	////	free();
	//if (*array)
	//	free_array(&(++*array));
	//free(*array);
}

t_vector atov(char *s)
{
	t_vector 	v;
	char		**split;

	split = ft_split(s, ',');
	v.x = atof(split[0]);
	v.y = atof(split[1]);
	v.z = atof(split[2]);
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

t_color atoc(char *s)
{
	t_color 	color;
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
	return (color);
}

float ft_atof(char *s)
{
	return (atof(s));
}
