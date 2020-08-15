/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:44:08 by aroque            #+#    #+#             */
/*   Updated: 2020/08/14 22:58:45 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ray.h"
#include "color.h"
#include "hittables.h"
#include <stdio.h>
#include <unistd.h>

/*
** Creates a ray pointing to (x, y) frame coordinates.
** This ray will have its origin on the frame center,
** which is the (0, 0, 0) point on the ray vector space.
**
** @x:		X server, implements the frame;
** @w, h:	Frame coordinates pointed by the ray.
*/

static 		t_color gradient(t_color start, t_color end, t_ray ray)
{
	float		t;
	t_vector unit;

	unit = norm(ray.direction);

	t = 0.5 * (unit.y + 1);
	return add(scale(start, 1 - t), scale(end, t));
}


t_color 			ray_color(t_ray ray, t_list *world)
{
	t_vector	n;
	t_color		pixel_color;
	t_hit		*record;
   
	record = malloc(sizeof(*record));
	if (hit_world(ray, world, record))
	{
		n = record->normal;
		pixel_color = (scale(color(n.x + 1, n.y + 1, n.z + 1), 0.5));
	}
	else
		pixel_color =  (gradient(color(0.5, 0.7, 1), color(1, 1, 1), ray));
	world = world->next;
	free(record);
	return pixel_color;
}


void			render(t_server *x)
{
	unsigned int	i;
	unsigned int	j;
	float vpy;
	float vpx;
	float aspect_ratio;
	float focal_length;
	t_ray ray;
	t_point llc;

	aspect_ratio = (float)x->window->width / x->window->height;
	vpy = 2.0;
	vpx = vpy * aspect_ratio;
	focal_length = 1.0;

	ray.origin = point(0, 0, 0);

	t_vector horizontal = vector(vpx, 0, 0);
	t_vector vertical = vector(0, vpy, 0);
	llc = sub(ray.origin, scale(horizontal, 0.5));
	llc = sub(llc, scale(vertical, 0.5));
	llc = sub(llc, vector(0, 0, focal_length));
	j = 0;
	while (j < x->window->height)
	{
		i = 0;
		//i = x->window->width;
		while (i < x->window->width)
		{
			float u = (float) i / (x->window->width - 1);
			float v = (float) j / (x->window->height - 1);
			ray.direction = add(scale(horizontal, u), scale(vertical, v));
			ray.direction = add(ray.direction, llc);
			ray.direction = sub(ray.direction, ray.origin);
			put_pixel(x, i, j, ray_color(ray, x->world));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(x->mlx, x->window->window, x->image->image, 0, 0);
}
