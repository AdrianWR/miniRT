/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:44:08 by aroque            #+#    #+#             */
/*   Updated: 2020/08/21 11:10:11 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ray.h"
#include "color.h"
#include "camera.h"
#include "figures.h"
#include "light.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

//static t_ray shadow_ray(t_light light, t_hit record)
//{
//	t_ray shadow;
//
//	shadow.origin = add(record.p, scale(record.normal, 0.0001));
//	//shadow.origin = record.p;
//	//shadow.direction = norm(sub(record.p, light.position));
//	shadow.direction = norm(sub(light.position, record.p));
//	return (shadow);
//}

t_color 			raytrace(t_ray *ray, t_world *world, int depth)
{
	t_hit		record;
	t_color color;
	//t_color object_color;
	//t_ray shadow;
	//t_list *light;
	//t_color vis;

	//vis = 1;
	if (depth <= 0)
		return (0x0);
	if (!intersect(ray, world->figures, &record))
		return (0x0);
	color = generate_light(*world->ambience, world->lights, record);
	//light = world->lights;
	//color = 0x0;
	//object_color = ((t_sphere *)record.object)->color;
	//while (light)
	//{
	//	shadow = shadow_ray(*((t_light *) light->content), record);
	//	//vis = raytrace(&shadow, world, depth - 1);
	//	//if (vis > 0)
	//	//	vis = 0;
	//	//else
	//	//	vis = 1;
	//	color = cadd(color, cscale(object_color, light_intensity((t_light *)light->content, record)));
	//	color *= vis;
	//	color = cproduct(color, ((t_light *)light->content)->color);
	//	light = light->next;
	//}	
	return (color);
}


void				render(t_server *x)
{
	unsigned int	i;
	unsigned int	j;
	float			u;
	float			v;
	t_ray			ray;
	t_color			pixel_color;

	j = x->window->height;
	while (--j)
	{
		i = x->window->width;
		while (--i)
		{
			u = (float) i / x->window->width;
			v = (float) j / x->window->height;
			ray = generate_ray(x->world->cameras->content, u, v);
			pixel_color = raytrace(&ray, x->world, 2);
			put_pixel(x, i, x->window->height - 1 - j, pixel_color);
		}
	}
	mlx_put_image_to_window(x->mlx, x->window->window, x->image->image, 0, 0);
}
