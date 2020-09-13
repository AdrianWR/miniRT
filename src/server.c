/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:39:42 by aroque            #+#    #+#             */
/*   Updated: 2020/09/13 20:18:35 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "server.h"
#include "camera.h"
#include <stdlib.h>

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

t_server		*new_server(t_world *world)
{
	t_server	*x;
	t_window	*win;

	if (!(x = malloc(sizeof(*x))))
		return (NULL);
	if (!(win = malloc(sizeof(*win))))
		return (NULL);
	x->mlx = mlx_init();
	mlx_get_screen_size(x->mlx, &(win->width), &(win->height));
	if (world->resolution[0] < win->width)
		win->width = world->resolution[0];
	if (world->resolution[1] < win->height)
		win->height = world->resolution[1];
	win->window = mlx_new_window(x->mlx, win->width, win->height, TITLE);
	x->window = win;
	x->image = new_image(x);
	x->world = world;
	init_cameras(world->cameras, *x->window);
	return (x);
}

void			put_pixel(t_server *s, unsigned x, unsigned y, t_color color)
{
	char		*color_addr;
	unsigned	hex_color;
	unsigned	opp;

	opp = s->image->bpp / 8;
	color_addr = (s->image->data + y * s->image->size_line + x * opp);
	hex_color = mlx_get_color_value(s->mlx, color);
	ft_memcpy(color_addr, &hex_color, opp);
}
