/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:44:08 by aroque            #+#    #+#             */
/*   Updated: 2020/08/14 15:00:59 by aroque           ###   ########.fr       */
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
	int i;
	float t;
	t_vector n;
	t_color pixel_color;
	t_sphere *sphere;

   
	i = 0;
	while (world->content)
	{
		sphere = (t_sphere *) world->content;
		t = hit_sphere(ray, sphere);
		if (t > 0)
		{
			n = norm(sub(calculate(ray, t), sphere->center));
			pixel_color = (scale(color(n.x + 1, n.y + 1, n.z + 1), 0.5));
		}
		else
			pixel_color =  (gradient(color(0.5, 0.7, 1), color(1, 1, 1), ray));
		world = world->next;
	}
	return pixel_color;
}


void			render(t_server *x)
{
	int	i;
	int	j;
	float vpy;
	float vpx;
	float aspect_ratio;
	float focal_length;
	t_ray ray;

	aspect_ratio = (float)x->window->width / x->window->height;
	vpy = 2.0;
	vpx = vpy * aspect_ratio;
	focal_length = 1.0;

	ray.origin = point(0, 0, 0);

	t_vector horizontal = vector(vpx, 0, 0);
	t_vector vertical = vector(0, vpy, 0);
	t_point llc = add(scale(vertical, 0.5), vector(0, 0, focal_length));
	llc = add(scale(horizontal, 0.5), llc);
	llc = scale(add(ray.origin, llc), -1);
	j = x->window->height;
	while (j--)
	{
		i = x->window->width;
		while (i--)
		{
			float u = (float) i / (x->window->width - 1);
			float v = (float) j / (x->window->height - 1);
			ray.direction = add(llc, scale(horizontal, u));
			ray.direction = add(ray.direction, scale(vertical, v));
			put_pixel(x, i, j, ray_color(ray, x->world));
		}
	}
	mlx_put_image_to_window(x->mlx, x->window->window, x->image->image, 0, 0);
}
