/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:39:42 by aroque            #+#    #+#             */
/*   Updated: 2020/09/10 16:17:40 by aroque           ###   ########.fr       */
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

t_server		*new_server(int width, int height, t_world *world)
{
	t_server	*x;
	t_window	*win;

	if (!(x = malloc(sizeof(*x))))
		return (NULL);
	if (!(win = malloc(sizeof(*win))))
		return (NULL);
	x->mlx = mlx_init();
	mlx_get_screen_size(x->mlx, &(win->width), &(win->height));
	if (width < win->width)
		win->width = width;
	if (height < win->height)
		win->height = height;
	win->window = mlx_new_window(x->mlx, win->width, win->height, TITLE);
	x->window = win;
	x->image = new_image(x);
	x->world = world;
	return (x);
}

void	put_pixel(t_server *s, unsigned int x, unsigned int y, t_color color)
{
	char			*color_addr;
	unsigned int 	hex_color;
	unsigned int 	opp;
	
	opp = s->image->bpp / 8;
	color_addr = (s->image->data + y * s->image->size_line + x * opp);
	hex_color = mlx_get_color_value(s->mlx, color);
	ft_memcpy(color_addr, &hex_color, opp);
}
