/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:39:42 by aroque            #+#    #+#             */
/*   Updated: 2020/07/09 14:15:49 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "server.h"
#include "mlx.h"

t_image			*new_image(t_server *x)
{
	t_image		*img;

	if (!(img = malloc(sizeof(*img))))
		return (NULL);
	img->image = mlx_new_image(x->mlx, x->window->width, x->window->height);
	img->data = mlx_get_data_addr(img->image, &(img->bpp),
			&(img->size_line), &(img->endian));
	img->width = x->window->width;
	img->height = x->window->height;
	return (img);
}

t_server		*new_server(unsigned int width, unsigned int height)
{
	t_server	*x;
	t_window	*win;

	if (!(x = malloc(sizeof(*x))))
		return (NULL);
	if (!(win = malloc(sizeof(*win))))
		return (NULL);
	x->mlx = mlx_init();
	win->width = width;
	win->height = height;
	win->window = mlx_new_window(x->mlx, width, height, TITLE);
	x->window = win;
	x->image = new_image(x);
	return (x);
}
