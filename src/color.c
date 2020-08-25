/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:48:45 by aroque            #+#    #+#             */
/*   Updated: 2020/08/25 08:47:35 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "color.h"
#include "server.h"

#define RGB_MAX 0xFF

static int clamp_rgb(int x)
{
	if (x > RGB_MAX)
		return (RGB_MAX);
	return (x < 0 ? 0 : x);
}

int cadd(int color_a, int color_b)
{
	int r = clamp_rgb((color_a >> 0x10) + (color_b >> 0x10));
	int g = clamp_rgb((color_a >> 0x08 & 0xFF) + (color_b >> 0x08 & 0xFF));
	int b = clamp_rgb((color_a & 0xFF) + (color_b & 0xFF));
	return ((r << 0x10) | (g << 0x08) | b);
}


t_color cproduct(t_color u, t_color v)
{
	int r;
	int g;
	int b;

	r = (((float)(u >> 0x10) / RGB_MAX) * ((float)(v >> 0x10) / RGB_MAX)) * RGB_MAX;
	g = (((float)((u >> 0x08) & 0xFF) / RGB_MAX) * ((float)((v >> 0x08) & 0xFF)  / RGB_MAX)) * RGB_MAX;
	b = (((float)(u & 0xFF) / RGB_MAX) * ((float)(v & 0xFF) / RGB_MAX)) * RGB_MAX;
	//return ((r) | (g) | b);
	return ((r << 0x10) | (g << 0x08) | b);
}

t_color		cscale(int color, float c)
{
	int mask;
	int r;
	int	g;
	int	b;

	mask = RGB_MAX;
	//r = c * ((color & (mask << 0x10)) >> 0x10);
	r = clamp_rgb(c * (color >> 0x10));
	g = clamp_rgb(c * ((color >> 0x08) & 0xFF));
	b = clamp_rgb(c * (color & 0xFF));
	//r = r > 0xFF ? 0xFF : r;
	//g = g > 0xFF ? 0xFF : g;
	//b = b > 0xFF ? 0xFF : b;
	return ((r << 0x10) | (g << 0x08) | b);
}

