/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 00:37:31 by aroque            #+#    #+#             */
/*   Updated: 2020/05/18 11:44:05 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "mlx.h"

void	color_map(t_server *x, int color)
{
	char			*ptr;
	unsigned int	w;
	unsigned int	h;
	unsigned int 	dec;
	unsigned int 	opp;

	opp = x->image->bpp / 8;
	h = HEIGHT;
	color = mlx_get_color_value(x->mlx, color);
	while (h--)
	{
		ptr = (x->image->data + h * x->image->size_line);
		w = WIDTH;
		while (w--)
		{
			dec = opp;
			while (dec--)
				*(ptr + w * opp + dec) = ((char *)(&color))[dec];
		}
	}
	mlx_put_image_to_window(x->mlx, x->window->window, x->image->image, 0, 0);
}
