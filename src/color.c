/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:48:45 by aroque            #+#    #+#             */
/*   Updated: 2020/08/16 20:44:48 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "color.h"
#include "server.h"

/*
** int	hex(t_color color)
**{
**	int hex;
**
**	hex = (int)(color.x * 255) << 16;
**	hex |= ((int)(color.y * 255) & 0xFF) << 8;
**	hex |= (int)(color.z * 255) & 0xFF;
**	return (hex);
*/

t_vector	color2vector(t_color color)
{
	t_vector	vector;

	vector.x = color.rgb.r / 255;
	vector.y = color.rgb.g / 255;
	vector.z = color.rgb.b / 255;
	return (vector);
}

t_color		hex2color(int hex)
{
	t_color	color;

	color.hex = hex;
	return color;
}

t_color		color_scale(t_color color, float c)
{
	t_color	result;

	result.rgb.r = color.rgb.r * c;
	result.rgb.g = color.rgb.g * c;
	result.rgb.b = color.rgb.b * c;
	return (result);
}

t_color		color_product(t_color color1, t_color color2)
{
	t_color	result;

	result.rgb.r = (char)((float)color1.rgb.r / 255 + (float)color2.rgb.r / 255);
	result.rgb.g = (char)((float)color1.rgb.g / 255 + (float)color2.rgb.g / 255);
	result.rgb.b = (char)((float)color1.rgb.b / 255 + (float)color2.rgb.b / 255);

	return result;
}

void	put_pixel(t_server *s, unsigned int x, unsigned int y, t_color color)
{
	char			*color_addr;
	unsigned int 	hex_color;
	unsigned int 	opp;
	
	opp = s->image->bpp / 8;
	color_addr = (s->image->data + y * s->image->size_line + x * opp);
	hex_color = mlx_get_color_value(s->mlx, color.hex);
	ft_memcpy(color_addr, &hex_color, opp);
}
