/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:44:08 by aroque            #+#    #+#             */
/*   Updated: 2020/08/15 23:50:06 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ray.h"
#include "color.h"
#include "camera.h"
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

//static 		t_color gradient(t_color start, t_color end, t_ray ray)
//{
//	float		t;
//	t_vector unit;
//
//	unit = norm(ray.direction);
//
//	t = 0.5 * (unit.y + 1);
//	return add(scale(start, 1 - t), scale(end, t));
//}


t_color 			ray_color(t_ray *ray, t_color background, t_list *world, int depth)
{
	//t_vector	n;
	t_color		pixel_color;
	t_hit		record;

	if (depth <= 0)
		return color(0, 0, 0);
	if (!hit_world(ray, world, &record))
		return background;
	t_vector n = record.normal;
	pixel_color = (scale(color(n.x + 1, n.y + 1, n.z + 1), 0.5));
	world = world->next;
	return pixel_color;
}


void			render(t_server *x, t_camera *cam)
{
	unsigned int	i;
	unsigned int	j;
	t_vector		horizontal;
	t_vector		vertical;
	t_vector		llc;
	t_ray			ray;

	float	u;
	float	v;

	horizontal = cam->horizontal;
	vertical = add(vector(0, 0, 0), cam->vertical);
	llc = cam->llc;

	ray.origin = cam->origin;

	j = x->window->height;
	while (--j)
	{
		i = x->window->width;
		while (--i)
		{
			u = (float) i / x->window->width;
			v = (float) j / x->window->height;
			ray.direction = add(scale(horizontal, u), scale(vertical, v));
			ray.direction = add(ray.direction, llc);
			ray.direction = sub(ray.direction, ray.origin);
			put_pixel(x, i, j, ray_color(&ray, color(0, 0, 0), x->world, 100));
			//i++;
		}
		//j++;
	}
	mlx_put_image_to_window(x->mlx, x->window->window, x->image->image, 0, 0);
}
