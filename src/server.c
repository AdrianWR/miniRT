/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:39:42 by aroque            #+#    #+#             */
/*   Updated: 2020/05/22 18:41:37 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "server.h"
#include "mlx.h"

t_server		*new_server(unsigned int width, unsigned int height)
{
	t_server	*x;
	t_window	*win;
	t_image		*img;

	if (!(x = malloc(sizeof(*x))))
		return (NULL);
	if (!(win = malloc(sizeof(*win))))
		return (NULL);
	if (!(img = malloc(sizeof(*img))))
		return (NULL);
	x->mlx = mlx_init();
	win->width = width;
	win->height = height;
	win->window = mlx_new_window(x->mlx, width, height, TITLE);
	img->image = mlx_new_image(x->mlx, width, height);
	img->data = mlx_get_data_addr(img->image, &(img->bpp),
			&(img->size_line), &(img->endian));
	x->image = img;
	x->window = win;
	return (x);
}
