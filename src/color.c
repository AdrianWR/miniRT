/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:48:45 by aroque            #+#    #+#             */
/*   Updated: 2020/08/19 22:03:36 by aroque           ###   ########.fr       */
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

//t_vector	color2vector(t_color color)
//{
//	t_vector	vector;
//
//	vector.x = (float)color.rgb.r / 255;
//	vector.y = (float)color.rgb.g / 255;
//	vector.z = (float)color.rgb.b / 255;
//	return (vector);
//}

//t_color		hex2color(int hex)
//{
//	t_color	color;
//
//	color.hex = hex;
//	return color;
//}

#define RGB_MAX 0xFF

int clamp_rgb(int x)
{
	if (x > RGB_MAX)
		return (RGB_MAX);
	return (x < 0 ? 0 : x);
}

int cadd(int color_a, int color_b)
{
	int r = clamp_rgb((color_a >> 0x10) + (color_b >> 0x10));
	int g = clamp_rgb((color_a >> 0x08 & 0xFF) + (color_b >> 0x08 & 0xFF));
	int b = clamp_rgb(color_a & 0xFF + color_b & 0xFF);
	return (r << 0x10 | g << 0x08 | b);
}

//t_color		color_scale(t_color color, float c)
//{
//	t_color	result;
//
//	result.rgb.r = color.rgb.r * c;
//	result.rgb.g = color.rgb.g * c;
//	result.rgb.b = color.rgb.b * c;
//	
//	return (result);
//}

//t_color		color_product(t_color color1, t_color color2)
//{
//	t_color	result;
//
//	result.rgb.r = (char)((float)color1.rgb.r / 255 + (float)color2.rgb.r / 255);
//	result.rgb.g = (char)((float)color1.rgb.g / 255 + (float)color2.rgb.g / 255);
//	result.rgb.b = (char)((float)color1.rgb.b / 255 + (float)color2.rgb.b / 255);
//
//	return result;
//}

int		cproduct(int color, double coef)
{
	int mask;
	int r;
	int	g;
	int	b;

	mask = 0xFF;
	r = coef * ((color & (mask << 0x10)) >> 0x10);
	g = coef * ((color & (mask << 0x08)) >> 0x08);
	b = coef * (color & mask);
	r = r > 0xFF ? 0xFF : r;
	g = g > 0xFF ? 0xFF : g;
	b = b > 0xFF ? 0xFF : b;
	return ((r << 0x10) | (g << 0x08) | b);
}

