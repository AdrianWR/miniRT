/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:39:42 by aroque            #+#    #+#             */
/*   Updated: 2020/09/14 15:39:06 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "server.h"
#include "camera.h"
#include <stdlib.h>

t_image			*new_image(t_server *x, unsigned width, unsigned height)
{
	t_image		*img;

	if (!(img = malloc(sizeof(*img))))
		return (NULL);
	img->image = mlx_new_image(x->mlx, width, height);
	img->data = mlx_get_data_addr(img->image, &(img->bpp),
			&(img->size_line), &(img->endian));
	return (img);
}

t_server		*new_server(t_world *world, bool windowless)
{
	t_server	*x;
	int			width;
	int			height;

	if (!(x = malloc(sizeof(*x))))
		return (NULL);
	x->mlx = mlx_init();
	mlx_get_screen_size(x->mlx, &width, &height);
	if (world->resolution[0] < width)
		width = world->resolution[0];
	if (world->resolution[1] < height)
		height = world->resolution[1];
	if ((x->image = new_image(x, width, height)) == NULL)
		return (NULL);
	x->world = world;
	x->width = width;
	x->height = height;
	x->windowless = windowless;
	init_cameras(world->cameras, width, height);
	if (!windowless)
		x->window = mlx_new_window(x->mlx, width, height, TITLE);
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
