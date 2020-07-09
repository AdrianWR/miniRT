/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 10:11:26 by aroque            #+#    #+#             */
/*   Updated: 2020/07/09 17:37:24 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "server.h"
#include "color.h"

static int			linear_blend(int start, int end, float t)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = (1 - t) * (start >> 16) + t * (end >> 16);
	g = (1 - t) * ((start >> 8) & 0xFF) + t * ((end >> 8) & 0xFF);
	b = (1 - t) * (start & 0xFF) + t * (end & 0xFF);
	return ((r << 16) + (g << 8) + b);
}

void gradient(int start, int end, t_server *x)
{
	char			*ptr;
	float			t;
	unsigned int	w;
	unsigned int	h;
	unsigned int 	dec;
	unsigned int 	opp;
	t_color			color;

	opp = x->image->bpp / 8;
	h = x->window->height;
	while (h--)
	{
		t = (float) h / x->window->height;
		color = mlx_get_color_value(x->mlx, linear_blend(start, end, t));
		ptr = (x->image->data + h * x->image->size_line);
		w = x->window->width;
		while (w--)
		{
			dec = opp;
			while (dec--)
				*(ptr + w * opp + dec) = ((char *)(&color))[dec];
		}
	}
	mlx_put_image_to_window(x->mlx, x->window->window, x->image->image, 0, 0);
}
