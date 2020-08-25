/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:48:45 by aroque            #+#    #+#             */
/*   Updated: 2020/08/25 15:30:11 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "server.h"
#include <math.h>

static int clamp(int x)
{
	if (x > 0xFF)
		return (0xFF);
	return (x < 0 ? 0 : x);
}

int cadd(int color_a, int color_b)
{
	int r = clamp((color_a >> 0x10) + (color_b >> 0x10));
	int g = clamp((color_a >> 0x08 & 0xFF) + (color_b >> 0x08 & 0xFF));
	int b = clamp((color_a & 0xFF) + (color_b & 0xFF));
	return ((r << 0x10) | (g << 0x08) | b);
}

t_color cproduct(t_color u, t_color v)
{
	int r;
	int g;
	int b;

	r = (((float)(u >> 0x10) / 0xFF) * ((float)(v >> 0x10) / 0xFF)) * 0xFF;
	g = (((float)((u >> 0x08) & 0xFF) / 0xFF) * ((float)((v >> 0x08) & 0xFF)  / 0xFF)) * 0xFF;
	b = (((float)(u & 0xFF) / 0xFF) * ((float)(v & 0xFF) / 0xFF)) * 0xFF;
	return ((r << 0x10) | (g << 0x08) | b);
}

t_color		cscale(int color, float c)
{
	int r;
	int	g;
	int	b;

	r = clamp(c * (color >> 0x10));
	g = clamp(c * ((color >> 0x08) & 0xFF));
	b = clamp(c * (color & 0xFF));
	return ((r << 0x10) | (g << 0x08) | b);
}

